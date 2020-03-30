#include <bits/stdc++.h>
using namespace std;

typedef struct {
  /*Ainda não tenho campo string único, mas posso fazer juntando o nome da revenda + cnpj*/
  int id; //id é um campo numérico único
  char regiao[3];

  char estado[3];
  char municipio[100];
  char revenda[100];
  double cnpj; //CNPJ é um campo numérico único
  char produto[4];
  char dataColeta[11];
  double valor_venda;
  double valor_compra;
  char peso[30];
  char bandeira[30];
} Registro;

int main(void){
  /*tenho que ler o csv e salvar no arquivo binário*/
  FILE *arq;
  arq = fopen("arquivo.bin", "wb");//arquivo aberto em modo de escrita
    //unsigned fread (void *buffer, int numero_de_bytes, int count, FILE *fp);
    FILE * file = fopen("2019-09-GLP.csv", "r");
    arq = fopen("arquivo","ab");
    Registro aux,aux2;
    string valor;
    int num_linhas=0;

    while(num_linhas < 12){
      aux.id = num_linhas;
      fscanf(file, "%[^,], %[^,], %[^,], %[^,], %lf, %[^,], %[^,], %lf, %lf, %[^,], %[^\n]}", aux.regiao, aux.estado, aux.municipio, aux.revenda, &aux.cnpj, aux.produto, aux.dataColeta, &aux.valor_venda, &aux.valor_compra, aux.peso, aux.bandeira);
      printf("%d, %s, %s, %s, %s, %lf, %s, %s, %lf, %lf, %s, %s\n", aux.id, aux.regiao, aux.estado, aux.municipio, aux.revenda, aux.cnpj, aux.produto, aux.dataColeta, aux.valor_venda, aux.valor_compra, aux.peso, aux.bandeira); /*http://www.cplusplus.com/reference/cstdio/scanf/*/
      fwrite(&aux, sizeof(Registro), 1, arq);

      //printf("%d\n", sizeof(aux));
      num_linhas++;
    }
    fclose(arq);
    int rrn;
    int escolha_usuario;
    while(true){
      printf("1 -  inserir\n");
      printf("2 -  listar todos\n");
      printf("3 -  consultar por rrn\n");
      printf("4 -  remover por rrn\n");
      printf("5 -  limpar arquivo\n");
      printf("6 -  sair\n");

      scanf("%d", &escolha_usuario);
      if(escolha_usuario == 6){
        break;
      } else {
        if(escolha_usuario == 1){

        } else if(escolha_usuario == 2){

        } else if(escolha_usuario == 3){
          printf("Digite o RRN da consulta\n");
          scanf("%d", &rrn);
        } else if(escolha_usuario == 4){
          printf("Digite o RRN da remoção\n");
          scanf("%d", &rrn);
        } else if(escolha_usuario == 5){

        }else {
          printf("Valor inválido, digite novamente.\n");
        }
      }
    }

  return 0;
}


/*
To pensando em só deixar:
id int // identificador
id_cnpj string // identificador, to pensando em juntar esses dois campos pra virar identificador
estado string
municipio string
loja string
cnpj double // identificador
preço venda double
todas as estruturas tão sendo salvas com tamanho fixo grazadeus
*/
