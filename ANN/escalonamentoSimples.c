#include<stdio.h>

int main(void){

  int k,i,j,n; // ordem da matriz
  printf("Digite o valor da ordem da matriz.\n");
  scanf("%d", &n);
  float mat[n][n];
  float mult;
  //Tem que operar toda linha n com o algoritmo

for(i=0; i<n; i++){
  for(j=0; j<n; j++){
    scanf("%f", &mat[i][j]);
  }
}
//recebi a mat
for(i=0; i<n; i++){
  for(j=0; j<n; j++){
    printf("%f ", mat[i][j]);
  }
  printf("\n");
}
// printei a mat

    for (k = 0; k < n-1; k++){
      for (i = k+1; i < n; i++){
        mult = mat[i][k]/mat[k][k];
        mat[i][k] = 0;
        for (j = k+1; j <= n; j++){
  	mat[i][j] -= mult * mat[k][j];
        }
      }
    }
printf("\n");
    for(i=0; i<n; i++){
      for(j=0; j<n; j++){
        printf("%f ", mat[i][j]);
      }
      printf("\n");
    }
    
    




  return 0;
}

