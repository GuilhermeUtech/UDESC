#include<stdio.h>

void processa(double h, double a, double n);

int main(void){
    
    // Programa para o calculo da integral num�rica da fun��o (x^2)+2
    double a,b,n;
    double h;
    printf("Informe os limitantes.\n");
    scanf("%lf%lf", &a,&b);
    printf("Informen o n�mero de trap�zios que voc� deseja utilizar para calcular a integral num�rica.\n");
    scanf("%lf", &n);
    h = (b-a)/n;
    processa(h,a,n);
    return 0;
    
    }
    
    void processa(double h, double a, double n){
        double i = 0;
        double b = a + h;
        double aux=0;
        double resultado = 0;
        while(i != n){
                    aux = aux +((h/2)*((pow(a,2) + 2) + (pow(b,2) + 2)));
                    a = b;
                    b = b + h;   
                    i++;
                       }
        resultado = aux;
        printf("O resultado �: %lf\n", resultado);
        system("pause");
                          
   
    }
    
