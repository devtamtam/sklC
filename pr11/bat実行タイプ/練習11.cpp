#include <stdio.h>
#include <math.h>

double f(double t, double y){
    return -sin(t);
}

int main(){
    double t,t0,t1,y,k1,k2,k3,k4,k,dt,dt2;
	dt=0.01;
	dt2=dt*0.5;
	t0=0.;
    y=1.;
	t1=8.0;
	printf("   t \t           y \n");
	printf(" %8.3f\t %8.3f\n",t0,y);
	int i=0;
    for(t=t0;t<t1;t+=dt){
        k1=f(t,y);
		k2=f(t+dt2,y+dt2*k1);
		k3=f(t+dt2,y+dt2*k2);
		k4=f(t+dt,y+dt*k3);
		k=(k1+(2.0*k2)+(2.0*k3)+k4)/6.0;
        y=y+k*dt;
		i=i+1;
		if((i%5)==0){
			printf(" %8.3f\t %8.3f\n",(t+dt),y);
		}
    }
	return 0;
}
