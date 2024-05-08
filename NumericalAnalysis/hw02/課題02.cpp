#include <stdio.h>

int main(){
    int ID;
	printf(" ID=");scanf("%d",&ID);
    double sum=1.0; double x=1.0; double r=(double)ID/100;
    for(int n=1; n<=10; n++){
	x=x*r;
    sum=sum+x;
    } 
	printf(" f(ID/100)= %lf",sum);putchar('\n');
	return 0;
}