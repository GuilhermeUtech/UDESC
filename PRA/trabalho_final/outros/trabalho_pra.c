#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
  int topo;
} Cabecalho;

typedef struct {
  char letra;
  int proximopilha;
} Removido;

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

int main(void){
  FILE *arq;
  arq = fopen("arquivo.bin", "wb");
  FILE *arquivo = fopen("2019-09-GLP.csv", "r");

  Aux aux;
  Registro auxiliar;
  Cabecalho cabecalho;
  Removido removido;

  int i=0;

  while(i < 10){
    fscanf(arquivo, "%[^,], %[^,], %[^,], %[^,], %lf, %[^,], %[^,], %lf, %lf, %[^,], %[^\n]}", aux.regiao, aux.estado, aux.municipio, aux.revenda, &aux.cnpj, aux.produto, aux.dataColeta, &aux.valor_venda, &aux.valor_compra, aux.peso, aux.bandeira);
    aux.id = i;
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
    i++;
  }

  fclose(arquivo);
  int opcao=-1;

while(opcao != 0){
  printf("Digite 1 para inserção\n");
  printf("Digite 2 para consulta\n");
  printf("Digite 3 para consultar por RRN\n");
  printf("Digite 4 para remover por RRN\n");
  printf("Digite 5 para limpar o arquivo\n");
  printf("Digite 0 para sair\n");
  scanf("%d", &opcao);
  //printf("%d\n", i);
  if(opcao == 1){
    arq = fopen("arquivo.bin", "wb");
    Registro inserir;
    inserir.id = i;
    printf("%d\n",inserir.id );
    i++;
    printf("Digite o estado (2 letras)\n");
    scanf("%s", inserir.estado);
    printf("Digite o cidade\n");
    scanf("%s", inserir.cidade);
    printf("Digite o fornecedor\n");
    scanf("%s", inserir.fornecedor);
    printf("Digite o cnpj\n");
    scanf("%lf", &inserir.cnpj);
    printf("Digite o preço\n");
    scanf("%d", &inserir.preco);
    printf("Digite o bandeira\n");
    scanf("%s", inserir.bandeira);
    printf("%s\n", inserir.fornecedor);
    strcpy(inserir.fornecedorCNPJ, inserir.fornecedor);
    char cnpj_string_1[20];
    sprintf(cnpj_string_1, "%lf", inserir.cnpj);
    strcat(inserir.fornecedorCNPJ, cnpj_string_1);
    strcat(inserir.fornecedorCNPJ, "\n");
    printf("%s\n", inserir.fornecedorCNPJ);
    fwrite(&inserir, sizeof(Registro), 1, arq);
    fclose(arq);

  } else  if(opcao == 2){//printar todos em tela
    arq = fopen("arquivo.bin", "rb");
    Registro aux_leitura;
    //printf("Entro aqui\n");
    rewind(arq);
    while(fread(&aux_leitura, sizeof(Registro), 1, arq)){
      printf("índice numérico - id: %d\n", aux_leitura.id);
      printf("estado: %s\n", aux_leitura.estado);
      printf("cidade: %s\n", aux_leitura.cidade);
      //printf("%s\n", aux_leitura.fornecedorCNPJ);
      printf("fornecedor: %s\n", aux_leitura.fornecedor);
      printf("Índice numérico - cnpj: %.0lf\n", aux_leitura.cnpj);
      printf("preço: %d\n", aux_leitura.preco);
      printf("bandeira: %s\n", aux_leitura.bandeira);
      printf("índice string - fornecedorCNPJ (campo composto): %s\n", aux_leitura.fornecedorCNPJ);
      printf("----------------------------------------\n");
    }

  } else if(opcao == 3){
    Registro registro;
    int rrn;
    printf("Digite o RRN a ser pesquisa:\n");
    scanf("%d", &rrn);
    arq = fopen ("arquivo.bin","rb");
    rewind(arq);
    fseek(arq, rrn * sizeof(Registro), SEEK_SET);
    fread(&registro, sizeof(Registro), 1, arq);
    printf("%s\n", registro.fornecedorCNPJ);



  } else if(opcao == 4){
    int rrn;
    printf("Digite o RRN\n");
    scanf("%d\n",&rrn);

  } else if(opcao == 5){

  } else if(opcao == 0){
    break;
  } else {
    printf("Opção inválida, digite novamente.\n");
  }
}


  return 0;
}
