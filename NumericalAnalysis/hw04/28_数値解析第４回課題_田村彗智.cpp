#include <stdio.h>

int main(){
	int n=4;
    double a[4][4] ={
		{1.0, 2.0, -1.0,-1.0},
		{-1.0, -1.0, 2.0,-2.0},
		{-2.0,3.0,-1.0,-2.0},
		{0.0,1.0,1.0,2.0}
	};
	double y[4] = {6.0,6.0,-1.0,5.0};
	double z;
	int i;
	printf("  \n");
    for(i=0;i<n;i++){
		printf(" a[%d,1]=%e\t a[%d,2]=%e\t a[%d,3]=%e\t a[%d,4]=%e\t y[%d]=%e\n",
			i,a[i][0],i,a[i][1],i,a[i][2],i,a[i][3],i,y[i]);
	}
	printf("  \n");

	for(i=0;i<n;i++){
		z=a[i][i];
		for(int j=i;j<n;j++){
			a[i][j]=a[i][j]/z;
		}
		y[i]=y[i]/z;
		for(int k=i+1;k<n;k++){
			z=a[k][i];
			for(int j=i;j<n;j++){
				a[k][j]=a[k][j]-a[i][j]*z;
			}
			y[k]=y[k]-y[i]*z;
		}
	}

	for(i=n-1;i>0;i=i-1){
		for(int k=i-1;k>=0;k=k-1){
			z=a[k][i];
			for(int j=k+1;j<n;j++){
				a[k][j]=a[k][j]-a[i][j]*z;
			}
			y[k]=y[k]-y[i]*z;
		}
	}
    for(i=0;i<n;i++){
		printf(" y[%d]=%e\n",i,y[i]);
	}
	return 0;
}