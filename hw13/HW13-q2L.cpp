#include <stdio.h>/*ルンゲ-クッタ*/
#include <math.h>

double f1(double t, double y1, double y2){
	double a=-0.2;
    return y1*(a-tan(t));//関数その１
}
double f2(double t, double y1, double y2){
	double a=-0.2;
    return y1;//関数その２
}

int main(){
	FILE *fp;
    double t,t0,t1,y1,k11,k12,k13,k14,k1;
    double y2,k21,k22,k23,k24,k2,dt,dt2;
	
	
	dt=0.05;//きざみ幅
	dt2=dt*0.5;
	t0=0.;//区間start
    y1=1.;//初期条件
    y2=y1;//初期条件
	t1=14.;//区間ends
	t=t0;
	fp = fopen("2.txt","w"); //データファイル「2.txt」を書き込み専用で開く。
    if (fp == NULL)
    {
        printf("出力ファイル lesson-12.txt のオープンに失敗しました。\n");
        printf("Enterキーで終了。\n");
        getchar();
        return 0;
    }
	fprintf(fp,"   t \t          y1 \t          y2 \n");
	fprintf(fp," %8.3f\t %8.3f\t %8.3f\n",t0,y1,y2);
	int i=0;
    for(t=t0;t<t1;t+=dt){
        k11=f1(t,y1,y2);
        k21=f2(t,y1,y2);
		k12=f1(t+dt2,y1+dt2*k11,y2+dt2*k21);
		k22=f2(t+dt2,y1+dt2*k11,y2+dt2*k21);
		k13=f1(t+dt2,y1+dt2*k12,y2+dt2*k22);
		k23=f2(t+dt2,y1+dt2*k12,y2+dt2*k22);
		k14=f1(t+dt,y1+dt*k13,y2+dt*k23);
		k24=f2(t+dt,y1+dt*k13,y2+dt*k23);
		k1=(k11+(2.*k12)+(2.*k13)+k14)/6.;
		k2=(k21+(2.*k22)+(2.*k23)+k24)/6.;
        y1=y1+k1*dt;
        y2=y2+k2*dt;
		i=i+1;
		if((i%1)==0){
			fprintf(fp," %8.3f\t %8.3f\t %8.3f\n",(t+dt),y1,y2);
		}
    }
	fclose(fp);
	return 0;
}
