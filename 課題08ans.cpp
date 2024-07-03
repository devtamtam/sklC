#include <stdio.h>
#include <math.h>

double f(double x){
    return exp(-x)*sin(x); //�֐�f�̒l
}
int main(){
    double x0,x1,xa,sum,T1,T2,dx,dx2,dT12,ds; 
	//T1= ����܂ł̕������ł̐ϕ��l�CT2= ��������{�ɂ����ϕ��l
    int m,n;  //n= �������Cm= n��{�ɂ�����
    x0=0.;  //�ϕ���ԉ���
	x1=1.;  //�ϕ���ԏ��
	ds=1.e-3;  //ds= dT12�̎�������
	dT12=1.;  //dT12= T1�CT2�̕ω����i�����l��ds���\���傫�Ȓl��^����j
    n=1;
    dx=x1-x0;  //������
    T1=0.5*(f(x0)+f(x1))*dx;
	for(m=0;dT12>=ds;m++){  //���������𖞂����܂ŁC��������{�ɂ��Čv�Z���J��Ԃ��B
	  dx2=dx*0.5;  //�V���ȕ�����
	  sum=0.;
      for(xa=x0+dx2;xa<x1;xa+=dx){
          sum=sum+f(xa);
      }
	  T2=T1*0.5+sum*dx2;  //��`���ɂ��V���Ȑϕ��l���v�Z
	  dT12=fabs((T2-T1)/T2);  //�ϕ��l�̕ω������v�Z
	  T1=T2;  //�ϕ��l���X�V
	  dx=dx2;  //���������X�V
	  n=n*2;  //���������X�V
	printf("  \n");
	printf("   n= %4i    T2= %e  dT12= %e\n",n,T2,dT12);
	}
	return 0;
}
