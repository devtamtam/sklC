#include <stdio.h>
#include <math.h>

double f(double t, double y){
	double a =-0.1;
    return y*(a-tan(t));
}

int main(){
	FILE *fp;
    double t,t0,t1,y,k1,k2,k3,k4,k,dt,dt2;
	dt=0.02; //刻み幅
	dt2=dt*0.5;
	t0=0.;//区間開始
    t1=12.0;//区間終わり
	
	y=1.;//初期条件
	

	fp = fopen("lesson-11.txt","w"); //データファイル「lesson-11.txt」を書き込み専用で開く。
    if (fp == NULL)
    {
        printf("出力ファイル lesson-11.txt のオープンに失敗しました。\n");
        printf("Enterキーで終了。\n");
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
		k=(k1+(2.0*k2)+(2.0*k3)+k4)/6.0;/*6 is 1+2+2+1*/
        y=y+k*dt;
		i=i+1;
		if((i%5)==0){/*s5個お気にプリントするよ*/
			fprintf(fp," %8.3f\t %8.3f\n",(t+dt),y);//横軸縦軸
		}
    }
	fclose(fp);
	return 0;
}
