#include <stdio.h>

double f(double t, double y){
    return y;dy/dtの式
}

int main(){
    double t,t0,t1,y,k,dt;
	double k1,k2;
	dt=0.1;//初期値
	t0=0.0;//
	t1=0.8;//
    y=1.0;//初期値
	printf(" t= %11.1e   y= %11.3e \n",t0,y);
    for(t=t0;t+dt<=t1;t+=dt){
        k1=f(t,y);
        k2=f(t+dt,y+k1*dt);
		k=(k1+k2)/2.;
        y=y+k*dt;
		printf(" t= %11.1e   y= %11.3e \n",(t+dt),y);
    }
	return 0;
}
