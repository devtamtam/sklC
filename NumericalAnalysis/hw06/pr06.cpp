#include <stdio.h>
#include <math.h>

int main(){
    double x[6],y[6],a,az,s,sz;
	int i;
	double f;
    x[1]=1.01;x[2]=2.02;x[3]=3.00;x[4]=3.99;x[5]=5.01;
    y[1]=1.53;y[2]=3.03;y[3]=4.51;y[4]=5.99;y[5]=7.52;
	sz=1.E20;
	az=1.45;
    for(a=1.45;a<=1.55;a+=0.001){
	  	s=0.;
	    for(i=1;i<=5;i++){
		  f=a*x[i];
          s=s+pow(f-y[i],2);
	    }
        if(s<sz){
    	sz=s;
		az=a;
        }
    }
	printf("  \n");
	printf(" a= %e   s=%e \n",az,sz);
	printf("  \n");
	return 0;
}