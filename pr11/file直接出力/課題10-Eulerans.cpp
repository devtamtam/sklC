#include <stdio.h>

double f(double t, double y){
    return y;
}

int main(){
    double t,t0,t1,y,k,dt;
	dt=0.1;
	t0=0.0;
	t1=1.2;
    y=1.0;
	printf(" t= %11.1e   y= %11.3e \n",t0,y);
    for(t=t0;t<t1;t+=dt){
        k=f(t,y);
        y=y+k*dt;
		printf(" t= %11.1e   y= %11.3e \n",(t+dt),y);
    }
	return 0;
}
 