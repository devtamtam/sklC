#include <stdio.h>
#include <math.h>
double f(double x, int id){
	double aa=double(id)/10.;
	return x - aa* pow(x, 0.5);
}

int main(){
    double a,b,c,d,e,fa,fb,fc,z;
	int i;
	int id=45;
	a=0.001;
	b=25.0;
	c=b;
	d=b;
    e=1.e-6;
    for(i=1; i<=200; i++){
      c=(a+b)*0.5;
	  fa=f(a,id);
	  fb=f(b,id);
	  fc=f(c,id);
      z=fabs((c-d)/c);
		printf(" %d\t %f\t %e\n",i,c,z);
      if(fa*fb>0){
        printf(" ERROR");
		break;
	  }
	  if(fa*fc>0){
	    a=c;
	  }
	  if(fb*fc>0){
	    b=c;
	  }
	  if(fc==0){
	    z=0;
	  }
      if(z<e){
		printf(" \n");
		printf(" id\t        x\t        z\n");
	  	break;
      }
	  d=c;
    } 

	printf(" %d\t %f\t %e\n",id,c,z);
  return 0;
}
