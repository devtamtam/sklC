#include<stdio.h>
#include<math.h>

int main(){
    double a=28.0/100.0;
    double sum=1.0;
    int nmax=10;

    for(int n=1;n<1+nmax;n++){
        sum=sum+pow(a,n);
    }


    printf("a is %f",a);

    printf("sum is %f",sum);

    return 0;
}
