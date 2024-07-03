#include <stdio.h>
#include <math.h>

double f(double x){
    return exp(-x)*sin(x); //関数fの値
}
int main(){
    double x0,x1,xa,sum,T1,T2,dx,dx2,dT12,ds; 
	//T1= これまでの分割数での積分値，T2= 分割数を倍にした積分値
    int m,n;  //n= 分割数，m= nを倍にした回数
    x0=0.;  //積分区間下限
	x1=1.;  //積分区間上限
	ds=1.e-3;  //ds= dT12の収束条件
	dT12=1.;  //dT12= T1，T2の変化率（初期値はdsより十分大きな値を与える）
    n=1;
    dx=x1-x0;  //分割幅
    T1=0.5*(f(x0)+f(x1))*dx;
	for(m=0;dT12>=ds;m++){  //収束条件を満たすまで，分割数を倍にして計算を繰り返す。
	  dx2=dx*0.5;  //新たな分割幅
	  sum=0.;
      for(xa=x0+dx2;xa<x1;xa+=dx){
          sum=sum+f(xa);
      }
	  T2=T1*0.5+sum*dx2;  //台形則により新たな積分値を計算
	  dT12=fabs((T2-T1)/T2);  //積分値の変化率を計算
	  T1=T2;  //積分値を更新
	  dx=dx2;  //分割幅を更新
	  n=n*2;  //分割数を更新
	printf("  \n");
	printf("   n= %4i    T2= %e  dT12= %e\n",n,T2,dT12);
	}
	return 0;
}
