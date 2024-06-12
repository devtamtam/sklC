#include <stdio.h>
#include <math.h>

double f(double x){
    return exp(-x)*sin(x);  //�֐�f�̒l
}
//��`���ɂ�鐔�l�ϕ�
int main(){
    double x0,x1,xj,sum,tn,dx,pi;  //tn=�ϕ�����
    int i,n;  //n=�������Ci= n��{�ɂ�����
    double tn0,dt;  //tn0=�ЂƂO��tn�Cdt= tn�̕ω���
    double dtl=1.E-4;  //dtl=��������
    pi=acos(-1.);
    n=1;
    x0=0.;  //�ϕ���ԉ���
	x1=1.;  //�ϕ���ԏ��
    dx=(x1-x0)/double(n);  //������
    tn=(f(x0)+f(x1))*dx*0.5;  //tn�̏����l
	printf("    n      tn          dt\n");
    for(i=1;i<=20;i++){
      n=n*2;  //n��2�{��
      dx=dx*0.5;  //dx�𔼕���
      sum=0.;
      for(xj=x0+dx;xj<x1;xj+=dx*2.){
          sum=sum+f(xj);
      }
    tn0=tn;  //�O��tn��tn0�Ƃ��ċL��
	tn=tn*0.5+dx*sum;  //�V����tn
    dt=fabs((tn-tn0)/tn);  //tn�̕ω������v�Z
	printf(" %4d  %10.4e  %10.4e\n",n,tn,dt);
    if(dt<dtl){  //���������𖞂�������I��
      break;
      }
    }
	return 0;
}
