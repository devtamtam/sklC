#include <stdio.h>
#include <math.h>

int main(){
    double x[6],y[6],a,az,s,sz;
    double b,bz;
	int i;
	int j;
	double f;
    x[1]=1.0;x[2]=2.0;x[3]=3.0;x[4]=4.0;x[5]=5.0;
    y[1]=2.2;y[2]=4.1;y[3]=6.5;y[4]=8.1;y[5]=9.9;
	sz=1.E20;
	az=1.93;
	bz=0.30;
	for(a=1.93;a<=1.95;a+=0.01){
		for(b=0.30;b<=0.35;b+=0.01){
		  	s=0.;
		    for(i=1;i<=5;i++){
			  f=a*x[i]+b;
    	      s=s+pow(f-y[i],2);
		    }
	        if(s<sz){
    		sz=s;
			az=a;
			bz=b;
    	    }
		}
    }
	printf("  \n");
	printf(" a= %e    b= %e   s=%e \n",az,bz,sz);
	printf("  \n");
	return 0;
}