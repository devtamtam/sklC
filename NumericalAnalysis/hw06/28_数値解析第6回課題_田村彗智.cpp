#include <stdio.h>
#include <math.h>

int main(){
    double x[6],y[6],a,az,s,sz,bz;
	int i;
	double f;
    x[1]=1.0;x[2]=2.0;x[3]=3.0;x[4]=4.0;x[5]=5.0;
    y[1]=2.2;y[2]=4.1;y[3]=6.5;y[4]=8.1;y[5]=9.9;
	sz=1.E20; // min of s
	az=1.45;  //min of a
	
    for(a=1.93;a<=1.95;a+=0.001){
	  for(double b=0.30;b<=0.35;b+=0.001){
	  	s=0;
	    for(i=1;i<=5;i++){
		  f=a*x[i]+b;
		  double yo = f-y[i];
          s=s+ pow(yo,2.0);
	    }
        if(s<sz){
    	sz=s; // min が更新される
		az=a; //min　が更新される
		bz=b; // min が更新される
        }
	  }	
    }
	printf("  \n");
	printf(" a= %e   s=%e  b=%e \n" ,az,sz,bz);
	printf("  \n");
	return 0;
}