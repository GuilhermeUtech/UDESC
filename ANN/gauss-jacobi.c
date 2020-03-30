#include<stdio.h>

int main(void){

	int i,j;
	float matrizA[3][3];
	float Xanterior[3];
	float vetorB[3];
	float Xproximo[3];
	int n_iteracoes;
	printf("Digite o número de iterações desejado.\n");
	scanf("%d", &n_iteracoes);
	printf("Digite os valores da matriz 3x3\n");
		for(i=0; i<3; i++)
		{
			for(j=0; j<3; j++)
			{
				scanf("%f", &matrizA[i][j]);
			}
		} // Recebi os valores da matriz A

	printf("Digite os valores do vetor solução B\n");
		for(i=0; i<3; i++)
		{
			scanf("%f", &vetorB[i]);
		}


		for(i=0; i<3; i++) /*aqui vai fazer a matriz com os chutes.*/
		{
				Xanterior[i] = vetorB[i]/matrizA[i][i];
		}

			for(i=0; i<n_iteracoes; i++)
			{
			Xproximo[0] = (vetorB[0] - matrizA[0][1]*Xanterior[1] - matrizA[0][2]*Xanterior[2]) * (1/matrizA[0][0]);
			Xproximo[1] = (vetorB[1] - matrizA[1][0]*Xanterior[0] - matrizA[1][2]*Xanterior[2]) * (1/matrizA[1][1]);
			Xproximo[2] = (vetorB[2] - matrizA[2][0]*Xanterior[0] - matrizA[2][1]*Xanterior[1]) * (1/matrizA[2][2]);
			printf("%f\n%f\n%f\n",Xproximo[0], Xproximo[1], Xproximo[2]);
			printf("---------------\n");
				for(j=0; j<3; j++)
				{
					Xanterior[j] = Xproximo[j];
				}

			}

		

	


	return 0;

}