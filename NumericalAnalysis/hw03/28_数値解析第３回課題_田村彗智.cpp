#include <stdio.h>
#include <math.h>

double f(double x){
    double l,m,n;
    l=1.0;
	m=28*100;
	n=2.0;
    return l*x*x-m*x+n;
}

int main(){
    double a,b,c,d,e,fa,fb,fc,z;
	int i;
	a=0.0;
	b=0.5;
	d=b;
    e=1.e-6;
    for(i=1; i<=100; i++){
      c=(a+b)*0.5;
	  fa=f(a);
	  fb=f(b);
	  fc=f(c);
      z=fabs(c-d);
      if(fa*fb>0){
        printf(" ERROR");
		break;
	  }
	  printf("i=%3d   a=%11.4e   b=%11.4e   fc=%11.4e \n",i,a,b,fc);
	  if(fa*fc>0){
	    a=c;
	  }
	  if(fb*fc>0){
	    b=c;
	  }
      if(z<e){
	  	break;
      }
	  d=c;
    } 
	printf("  \n");
	printf(" i=%3d   c=%11.2e   z=%11.2e \n",i,c,z);
	return 0;
}