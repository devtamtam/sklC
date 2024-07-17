#include <stdio.h>
#include <math.h>

double f(double x){
    return tan(x*x);
}
int main(){
    double x0,x1,xa,sum; // x0:�ϕ��͈͉����Cx1:�ϕ��͈͏��
    double T1,T2,S1,S2; // T1:�ЂƂO�̑�`���ϕ��l�CT2:�V���ȑ�`���ϕ��l�C
                        // S1:�ЂƂO�̃V���v�\�����ϕ��l�CS2:�V���ȃV���v�\�����ϕ��l�C
    double dx,dx2,dS12,ds; // dx:�ЂƂO�̐ϕ����ݕ��Cdx2:�V���Ȑϕ����ݕ��i dx=2*dx2 �j�C
                           // dS12:�V���v�\�����ϕ��l�̕ω����Cds:�����������
    int m,n; // n:�������Cm: ��������{�ɂ�����
    x0=0.;//�ϕ���start
	x1=1.;//�ϕ���end
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
	  S2=(T2*4.-T1)/3.;  /*�V���v�\�����ɂ��ϕ��ߎ��l�����ꂼ�� TnSn�Ƃ��� 
	  ����T��S�̊֌W*/
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

