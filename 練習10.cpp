#include <stdio.h>//Euler方法

double f(double t, double y){
    return y;//dy/dtの式
}

int main(){
    double t,t0,t1,y,k,dt;
	dt=0.1;//結構あらいな
	t0=0.0;//初期値
	t1=0.8;//求めたい値のt
    y=1.0;//初期値
	printf(" t= %11.1e   y= %11.3e \n",t0,y);
    for(t=t0;t<t1;t+=dt){
        k=f(t,y);
        y=y+k*dt;
		printf(" t= %11.1e   y= %11.3e \n",(t+dt),y);
    }
	return 0;
}
