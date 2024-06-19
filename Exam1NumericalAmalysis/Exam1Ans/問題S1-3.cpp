#include <stdio.h>
#include <math.h>

double f(double a, double b, double x){
	return a*sin(x)+b*x;
}

int main(){
	FILE *fp;
	char dummy[256];
	int ret;
	int id=45;
    double x[128],y[128],a,az,b,bz,s,sz;
	int i,j,nz,jj;
	double fi;
	double amin=1.5,amx=2.5,da=0.001;
	double bmin=0.2,bmx=1.0,db=0.001;
	fp = fopen("ex-S1-3.txt","r"); 
    fgets(dummy,256,fp); 
	j=1;
	while( ( ret = fscanf( fp,"%d\t%lf\t%lf",&jj,&x[j],&y[j]) ) != EOF ){  
		nz=j;
		j=j+1;
	}
	fclose(fp);
	printf(" id\t    a\t    b\n");

	sz=1.E20;
	az=amin;
	bz=bmin;
    for(a=amin;a<=amx;a+=da){
      for(b=bmin;b<=bmx;b+=db){
		s=0.;
	    for(i=id;i<=id+25;i++){
		  fi=f(a,b,x[i]);
          s=s+pow(fi-y[i],2);
	    }
        if(s<sz){
    	sz=s;
		az=a;
		bz=b;
        }
      }
    }
	printf(" %d\t %f\t% f\n",id,az,bz);

	return 0;
}
