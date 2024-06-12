#include <stdio.h>
#include <math.h>

double f(double x){
    return sin(x);
}
//台形公式による数値積分
int main(){
    double x0,x1,sum,dx,pi;
    int n;
    pi=acos(-1.);  //円周率の値をpiに与える。
    n=128;
    x0=0.;
	x1=pi/2.;
    dx=(x1-x0)/double(n);
	sum=0.5*f(x0);
    for(int j=1;j<n;j++){
        sum=sum+f(x0+j*dx);
    }
	sum=sum+0.5*f(x1);
	sum=sum*dx;
	printf("  \n");
	printf(" sum= %10.4e \n",sum);
	printf("  \n");
	return 0;
}
