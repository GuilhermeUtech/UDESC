#include<stdio.h>

int main(void){
	float x[6] = {0.5,1.0,1.5,2.0,2.5,3.0};
	float y[6] = {1.143,1.0,0.828,0.667,0.533, 0.428};
	float auxiliar = 0;
	int i,j;
	float p=0, pn = 0;
	
	/* printf("Digite os valores de X (6 valores).\n");
	for(i=0; i<6; i++){
		scanf("%f", &x[i]);
	}	
	printf("Digite os valores de Y (6 valores).\n");
	for(i=0; i<6; i++){
		scanf("%f", &y[i]);
	}	*/
	
	printf("Digite o valor que você quer saber.\n");
	scanf("%f", &auxiliar);
	for(j=0; j<6; j++){
		p = 1;
		for(i=0; i<6; i++){
			if(i !=j ){
				printf("%f", p);
				p = p * ((auxiliar - x[i]) / (x[j] - x[i]));
				printf("%f", p);
			}
		}
		pn = pn + (p * (y[j]));
	}
	printf("O resultado de: %f, em f é: %f",auxiliar,pn);
	
	
	return 0;
}
