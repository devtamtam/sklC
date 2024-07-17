/*Exccelにてグラフを出力するとyは減衰しながら振動する関数だとわかる
よって、初めに現れる極小値が最小値である。
*/
#include <stdio.h>
#include <math.h>

double f(double t, double y, double yd){
    return -0.1*yd-2*y;
}

int main(){
	FILE *fp;
	double ymin;
    double t,t0,t1,y,k11,k12,k13,k14,k1;
    double yd,k21,k22,k23,k24,k2,dt,dt2;
	dt=0.01;//刻み幅
	dt2=dt*0.5;
	t0=0.;//区間start
    y=1.;/*初期条件y(t=0)の値*/
    yd=0.;/*初期条件y'(t=0)*/
	t1=10.;//区間ends
	t=t0;
	fp = fopen("hw13-q3textdata.txt","w");
    if (fp == NULL)
    {
        printf("出力ファイル.txt のオープンに失敗しました。\n");
        printf("Enterキーで終了。\n");
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
		if(yd>0){ymin=y;
			printf("ymin is %8.3f\n",ymin);
			printf("then t is %8.3f\n",t);
			break;
		}
		if((i%2)==0){/*2回に1回表示*/
			//fprintf(fp," %8.3f\t %8.3f\t %8.3f\n",(t+dt),y,yd);
			
		}
    }
	fclose(fp);
	return 0;
}

/////////////////////////////////////////////////
/*ANSWER MEMO 
ymin is   -0.895
then t is    2.220*/
////////////////////////////////////////////////