#include <stdio.h>
#include <stdlib.h>

float funcao(float a);

int main(void){
	float a,b,erro,funcaoA,funcaoB,xm,funcaoXm,iteracoes;
	
	printf("Digite os valores do intervalo.\n");
	scanf("%f", &a);
	scanf("%f", &b);
	printf("Digite o erro máximo aceitável.\n");
	scanf("%f", &erro);
	goto tokken;
	
	while(b-a>= erro || funcaoA >= erro || funcaoB >= erro){
		tokken:
		xm = (a+b)/2;
		funcaoA = funcao(a);
		funcaoB = funcao(b);
		funcaoXm = funcao(xm);
		if(funcaoA*funcaoB < 0){
			b = xm;
		} else {
			a = xm;
		}
		iteracoes++;
		printf("O número de iterações é de: %d", iteracoes);
		printf("A = %f\n\nB = %f\n", a,b);
	}
	
	printf("\nb - a = %f\n", b - a);
	printf("Resultado final:\n%f", (a+b)/2); 
	return 0;
}

float funcao(float a){
	float aux,aux2;
	aux = a*a;
	aux2 = aux - 4;
	return aux2;
	
}
