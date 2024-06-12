#include <stdio.h>
#include <math.h>

double f(double x){
    return exp(-x)*sin(x);  //関数fの値
}
//台形則による数値積分
int main(){
    double x0,x1,xj,sum,tn,dx,pi;  //tn=積分結果
    int i,n;  //n=分割数，i= nを倍にした回数
    double tn0,dt;  //tn0=ひとつ前のtn，dt= tnの変化率
    double dtl=1.E-4;  //dtl=収束条件
    pi=acos(-1.);
    n=1;
    x0=0.;  //積分区間下限
	x1=1.;  //積分区間上限
    dx=(x1-x0)/double(n);  //分割幅
    tn=(f(x0)+f(x1))*dx*0.5;  //tnの初期値
	printf("    n      tn          dt\n");
    for(i=1;i<=20;i++){
      n=n*2;  //nを2倍に
      dx=dx*0.5;  //dxを半分に
      sum=0.;
      for(xj=x0+dx;xj<x1;xj+=dx*2.){
          sum=sum+f(xj);
      }
    tn0=tn;  //前のtnをtn0として記憶
	tn=tn*0.5+dx*sum;  //新たなtn
    dt=fabs((tn-tn0)/tn);  //tnの変化率を計算
	printf(" %4d  %10.4e  %10.4e\n",n,tn,dt);
    if(dt<dtl){  //収束条件を満たしたら終了
      break;
      }
    }
	return 0;
}
