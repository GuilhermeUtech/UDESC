#include<stdio.h>

void processa(double h, double a, double n);

int main(void){
    
    // Programa para o calculo da integral numérica da função (x^2)+2
    double a,b,n;
    double h;
    printf("Informe os limitantes.\n");
    scanf("%lf%lf", &a,&b);
    printf("Informen o número de trapézios que você deseja utilizar para calcular a integral numérica.\n");
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
        printf("O resultado é: %lf\n", resultado);
        system("pause");
                          
   
    }
    
