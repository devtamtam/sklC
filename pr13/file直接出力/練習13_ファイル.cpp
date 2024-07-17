#include <stdio.h>
#include <math.h>

double f(double t, double y, double yd){
    return -y-yd-sin(t);
}

int main(){
	FILE *fp;
    double t,t0,t1,y,k11,k12,k13,k14,k1;
    double yd,k21,k22,k23,k24,k2,dt,dt2;
	dt=0.005;/*���ݕ�*/
	dt2=dt*0.5;
	t0=0.;//���start
    y=1.;/*��������y(t=0)�̒l*/
    yd=0.;/*��������y'(t=0)*/
	t1=2.;//���ends
	t=t0;
	fp = fopen("lesson-13.txt","w");
    if (fp == NULL)
    {
        printf("�o�̓t�@�C�� lesson-13.txt �̃I�[�v���Ɏ��s���܂����B\n");
        printf("Enter�L�[�ŏI���B\n");
        getchar();
        return 0;
    }
	fprintf(fp,"   t \t           y \t          yd \n");
	fprintf(fp," %8.3f\t %8.3f\t %8.3f\n",t0,y,yd);
	int i=0;
    for(t=t0;t<t1;t+=dt){
        k11=yd;
        k21=f(t,y,yd);
		k12=yd+dt2*k21;
		k22=f(t+dt2,y+dt2*k11,yd+dt2*k21);
		k13=yd+dt2*k22;
		k23=f(t+dt2,y+dt2*k12,yd+dt2*k22);
		k14=yd+dt*k23;
		k24=f(t+dt,y+dt*k13,yd+dt*k23);
		k1=(k11+(2.*k12)+(2.*k13)+k14)/6.;
		k2=(k21+(2.*k22)+(2.*k23)+k24)/6.;
        y=y+k1*dt;
        yd=yd+k2*dt;
		i=i+1;
		if((i%2)==0){/*2���1��\��*/
			fprintf(fp," %8.3f\t %8.3f\t %8.3f\n",(t+dt),y,yd);
		}
    }
	fclose(fp);
	return 0;
}
