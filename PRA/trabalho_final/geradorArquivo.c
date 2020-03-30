#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 12


typedef struct {
  int id;
  char regiao[3];
  char estado[3];
  char municipio[100];
  char revenda[100];
  double cnpj;
  char produto[4];
  char dataColeta[11];
  double valor_venda;
  double valor_compra;
  char peso[30];
  char bandeira[30];
} Aux;

typedef struct {
int id; //identificador único
char estado[3];
char cidade[100];
char fornecedor[100];
double cnpj; //identificador único
int preco;
char bandeira[100];
char fornecedorCNPJ[100]; //identificador único de string
} Registro;

typedef struct {
    int id;
    int posicao;
} ID;

typedef struct {
    double cnpj;
    int posicao;
} CNPJ;


int main(void){
  FILE *arq = fopen("arquivo.dat", "wb");
  FILE *arq2 = fopen("indice_id.dat", "wb");
  FILE *arq3 = fopen("indice_cnpj.dat", "wb");
  FILE *arquivo = fopen("2019-09-GLP.csv", "r");

  Aux aux;
  Registro auxiliar;
  ID auxiliar_id;
  CNPJ auxiliar_cnpj;

  int i=0;

  while(i < MAX){
    fscanf(arquivo, "%[^,], %[^,], %[^,], %[^,], %lf, %[^,], %[^,], %lf, %lf, %[^,], %[^\n]}", aux.regiao, aux.estado, aux.municipio, aux.revenda, &aux.cnpj, aux.produto, aux.dataColeta, &aux.valor_venda, &aux.valor_compra, aux.peso, aux.bandeira);
    aux.id = i+1;
    auxiliar.id = aux.id;
    strcpy(auxiliar.estado, aux.estado);
    strcpy(auxiliar.cidade, aux.municipio);
    strcpy(auxiliar.fornecedor, aux.revenda);
    auxiliar.cnpj = aux.cnpj;
    auxiliar.preco = aux.valor_venda;
    strcpy(auxiliar.bandeira, aux.bandeira);
    strcpy(auxiliar.fornecedorCNPJ, aux.revenda);
    char cnpj_string[20];
    sprintf(cnpj_string, "%lf", auxiliar.cnpj);
    strcat(auxiliar.fornecedorCNPJ, cnpj_string);
    strcat(auxiliar.fornecedorCNPJ, "\n");
    
    fwrite(&auxiliar, sizeof(Registro), 1, arq);

    auxiliar_id.id = i+1;
    auxiliar_id.posicao = i+1;
    auxiliar_cnpj.cnpj = aux.cnpj;
    auxiliar_cnpj.posicao = i+1;

    fwrite(&auxiliar_id, sizeof(ID), 1, arq2);
    fwrite(&auxiliar_cnpj, sizeof(CNPJ), 1, arq3);
    i++;
  }

    fclose(arq3);
    fclose(arq2);
    arq2 = fopen("indice_id.dat", "rb");
    while(fread(&auxiliar_id, sizeof(ID), 1,arq2)){
        printf("%d %d\n", auxiliar_id.id, auxiliar_id.posicao);
    }
    
    arq3 = fopen("indice_cnpj.dat", "rb");
    while(fread(&auxiliar_cnpj, sizeof(CNPJ), 1,arq3)){
        printf("%lf %d\n", auxiliar_cnpj.cnpj, auxiliar_cnpj.posicao);
    }
    

  fclose(arquivo);
  fclose(arq);
  fclose(arq2);
  fclose(arq3);
  
  return 0;
}