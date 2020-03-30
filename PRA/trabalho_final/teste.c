#include<stdio.h>

int main(){
    int a,b;
    FILE *arquivo = fopen("indices_exemplo", "r");
    FILE *arq = fopen("indice_id.dat", "wb");
    while(fscanf(arquivo, "%d %d", &a,&b)!= -1){
        printf("%d %d\n",a,b);
        fwrite(&a, sizeof(int), 1, arq);
        fwrite(&b, sizeof(int), 1, arq);
    }
    
    return 0;
}