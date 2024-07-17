#include <stdio.h>
#include <math.h>

double f(double t, double y){
    return -y*cos(t);
}

int main(){
	FILE *fp;
    double t,t0,t1,y,k1,k2,k3,k4,k,dt,dt2;
	dt=0.05;
	dt2=dt*0.5;
	t0=0.;
    y=-1.;
	t1=6.0;

	fp = fopen("HW13-q2-LUN-ans.txt","w"); //�f�[�^�t�@�C���ulesson-11.txt�v���������ݐ�p�ŊJ���B
    if (fp == NULL)
    {
        printf("�o�̓t�@�C���@lesson-11.txt�@�̃I�[�v���Ɏ��s���܂����B\n");
        printf("Enter�L�[�ŏI���B\n");
        getchar();
        return 0;
    }
	fprintf(fp,"   t \t           y \n");
	fprintf(fp," %8.3f\t %8.3f\n",t0,y);
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
			fprintf(fp," %8.3f\t %8.3f\n",(t+dt),y);
		}
    }
	fclose(fp);
	return 0;
	
	
}
///////////////////////
//    6.000	   -1.322

//////////////////