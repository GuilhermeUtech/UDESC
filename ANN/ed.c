#include<stdio.h>
#include<math.h>

int main(void){
		double ans = 0, xi = 0, xn = 0, fx = 0, fdx = 0, error = 0;
  	scanf("%lf%lf",&xn,&error);
  	int k = 0;
  	printf("%.4lf\n",error);
  
  	do{
      xi = xn;
      fx = (pow(xi,2) - 5);
      fdx = 2 * xi;
      xn = xi - (fx/fdx);
      k++;
      printf("iteracao %d\n",k);
      printf("|X inicial = %.4lf\n|X novo = %.4lf",xi,xn);
      printf("xn: %.4lf - fdx: %.4lf\n\n",abs(xn - xi),abs(fdx));
    } while(fabs(xn-xi) >= error && fabs(fdx) >= error);
      
      printf("SOLUCAO FINAL: %.4lf\n\n",xn);
	return 0;
}
