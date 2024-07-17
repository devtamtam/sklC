#include <stdio.h>
#include <math.h>

double f(double x){
    return tan(x*x);
}
int main(){
    double x0,x1,xa,sum; // x0:積分範囲下限，x1:積分範囲上限
    double T1,T2,S1,S2; // T1:ひとつ前の台形則積分値，T2:新たな台形則積分値，
                        // S1:ひとつ前のシンプソン則積分値，S2:新たなシンプソン則積分値，
    double dx,dx2,dS12,ds; // dx:ひとつ前の積分刻み幅，dx2:新たな積分刻み幅（ dx=2*dx2 ），
                           // dS12:シンプソン則積分値の変化率，ds:収束判定条件
    int m,n; // n:分割数，m: 分割数を倍にした回数
    x0=0.;//積分区start
	x1=1.;//積分区end
	ds=1.e-4;
	dS12=1.;
    n=1;
    dx=x1-x0;
    T1=0.5*(f(x0)+f(x1))*dx;
    S1=T1;
	for(m=0;dS12>=ds;m++){
	  dx2=dx*0.5;
	  sum=0.;
      for(xa=x0+dx2;xa<x1;xa+=dx){
          sum=sum+f(xa);
      }
	  T2=T1*0.5+sum*dx2;
	  S2=(T2*4.-T1)/3.;  /*シンプソン則による積分近似値をそれぞれ TnSnとする 
	  そのTとSの関係*/
	  dS12=fabs((S2-S1)/S2);
	  T1=T2;
      S1=S2;
	  dx=dx2;
	  n=n*2;
	printf("  \n");
	printf("   n= %5i    S2= %e  dS12= %e \n",n,S2,dS12);
	}
	return 0;
}

