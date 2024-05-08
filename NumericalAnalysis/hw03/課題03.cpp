#include <stdio.h>
#include <math.h>

double f(double x, int ii){
    double l,m,n;
    l=1.0;
	m=-double(ii)*100.;
	n=2.0;
    return l*x*x+m*x+n;
}

int main(){
    double a,b,c,d,e,fa,fb,fc,z;
	int i,j;
	for(j=1; j<=100; j++){

    int id;
	printf(" ID=");scanf("%d",&id);
    if(id<=0){
 	break;
    }

	a=0.0;
	b=0.5;
	d=b;
    e=1.e-6;
    for(i=1; i<=100; i++){
      c=(a+b)*0.5;
	  fa=f(a,id);
	  fb=f(b,id);
	  fc=f(c,id);
      z=fabs(c-d);
      if(fa*fb>0){
        printf(" ERROR");
		break;
	  }
	  
	  printf("i=%3d   a=%11.4e   b=%11.4e   z=%11.4e   fc=%11.4e \n",i,a,b,z,fc);
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
	printf(" i=%d   c=%e   z=%e \n",i,c,z);

	}
	return 0;
}