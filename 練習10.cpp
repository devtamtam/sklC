#include <stdio.h>//Euler���@

double f(double t, double y){
    return y;//dy/dt�̎�
}

int main(){
    double t,t0,t1,y,k,dt;
	dt=0.1;//���\���炢��
	t0=0.0;//�����l
	t1=0.8;//���߂����l��t
    y=1.0;//�����l
	printf(" t= %11.1e   y= %11.3e \n",t0,y);
    for(t=t0;t<t1;t+=dt){
        k=f(t,y);
        y=y+k*dt;
		printf(" t= %11.1e   y= %11.3e \n",(t+dt),y);
    }
	return 0;
}
