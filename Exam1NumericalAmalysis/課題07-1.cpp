#include <stdio.h>
#include <math.h>

double f(double x){
    return pow(x,3)+3.*x+cos(x);
}

int main(){
    double a,b,c,d,e,fa,fb,fc,y,z;
	int i;
	a=-1.0;
	b=1.0;
	d=b;
    e=1.e-5;
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
	  printf("i=%d   a= %lf   b=%lf   fc=%6.4e \n",i,a,b,fc);
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
      y=z;
    } 
	printf("  \n");
	printf(" i=%d   c= %lf   y=%6.4e   z=%6.4e \n",i,c,y,z);
	return 0;
}
