#include <stdio.h>
#include <math.h>

int main(){
	int n=4;
    double a[4][4] ={
		{0.0, 1.0, 1.0, 2.0},
		{1.0, 2.0, -1.0, -1.0},
		{-1.0, -1.0, 2.0, -2.0},
		{-2.0, 3.0, -1.0, -2.0}
	};
	double y[4] = {5.0, -6.0, 6.0, -1.0};
	double z;
	int i,j;
	//�s�{�b�g�Ŏg���ϐ���`
	double b[4];
	int ip;
	//
	printf("  \n");
    for(i=0;i<n;i++){
		printf(" %e\t %e\t %e\t %e\t   %e\n",
			a[i][0],a[i][1],a[i][2],a[i][3],y[i]);
	}
	printf("  \n");
	for(i=0;i<n;i++){
		//�s�{�b�g����J�n
		ip=i;
		for(j=i;j<n;j++){	//a[j][i]�̐�Βl���ő�ƂȂ�j��T��ip�Ƃ���
			if(fabs(a[ip][i]) < fabs(a[j][i])){
				ip=j;
			}
		}
		if(ip != i){	//ip==i�Ȃ牽�����Ȃ�
			for(j=i;j<n;j++){	//�����ɔ����āii�s�ځja[i][j]��b[j]�ɕۑ�
				b[j]=a[i][j];
			}
			z=y[i];	//y[i]��z�ɕۑ�
			for(j=i;j<n;j++){	//i�s�ڂ�ip�s�ڂ�����
				a[i][j]=a[ip][j];
				a[ip][j]=b[j];
			}
			y[i]=y[ip];
			y[ip]=z;	//y������

			printf(" Pibot\n");
		    for(int ii=0;ii<n;ii++){	//�r���o�߂�\���i0�j�s�{�b�g
				printf(" %e\t %e\t %e\t %e\t   %e\n",
				a[ii][0],a[ii][1],a[ii][2],a[ii][3],y[ii]);
			}
			printf("  \n");

		}		//�s�{�b�g����I��
		z=a[i][i];
		for(j=i;j<n;j++){
			a[i][j]=a[i][j]/z;
		}
		y[i]=y[i]/z;
		for(int k=i+1;k<n;k++){
			z=a[k][i];
			for(j=i;j<n;j++){
				a[k][j]=a[k][j]-a[i][j]*z;
			}
			y[k]=y[k]-y[i]*z;
		}

    for(int ii=0;ii<n;ii++){	//�r���o�߂�\���i�P�j�O�i����
		printf(" %e\t %e\t %e\t %e\t   %e\n",
			a[ii][0],a[ii][1],a[ii][2],a[ii][3],y[ii]);
	}
	printf("  \n");

	}

	for(i=n-1;i>0;i=i-1){
		for(int k=i-1;k>=0;k=k-1){
			z=a[k][i];
			for(j=k+1;j<n;j++){
				a[k][j]=a[k][j]-a[i][j]*z;
			}
			y[k]=y[k]-y[i]*z;
		}
    for(int ii=0;ii<n;ii++){	//�r���o�߂�\���i�Q�j��ޑ��
		printf(" %e\t %e\t %e\t %e\t   %e\n",
			a[ii][0],a[ii][1],a[ii][2],a[ii][3],y[ii]);
	}
	printf("  \n");

	}
    for(i=0;i<n;i++){
		printf(" y[%d]=%e\n",i,y[i]);
	}
	return 0;
}