#include <stdio.h>
#include <math.h>

int main(){
	int n=5;
    double a[5][5] ={
		{2.0, 4.0, 1.0, 0.0,-4.0},
		{1.0, 2.0, 1.0, 1.0,-3.0},
		{1.0,-1.0, 2.0, 3.0, 1.0},
		{5.0, 3.0,-1.0, 2.0, 4.0},
		{-1.0, 1.0,-2.0,-1.0, 3.0}
	};
	double y[5] = {0.0,-2.0, 3.0, 1.0, -5.0 };
	double b[5];
	double z;
	int i,j;
	printf("  \n");
    for(int ii=0;ii<n;ii++){
		printf(" %e\t %e\t %e\t %e\t %e\t   %e\n",
			a[ii][0],a[ii][1],a[ii][2],a[ii][3],a[ii][4],y[ii]);
	}
	printf("  \n");

	for(i=0;i<n;i++){

//partial pivoting start
		int ip=i;
		for(j=i;j<n;j++){
			if(fabs(a[ip][i]) < fabs(a[j][i])){
				ip=j;
			}
		}
		for(j=i;j<n;j++){
			b[j]=a[i][j];
		}
		z=y[i];
		for(j=i;j<n;j++){
			a[i][j]=a[ip][j];
			a[ip][j]=b[j];
		}
		y[i]=y[ip];
		y[ip]=z;

    for(int ii=0;ii<n;ii++){
		printf(" %e\t %e\t %e\t %e\t %e\t   %e\n",
			a[ii][0],a[ii][1],a[ii][2],a[ii][3],a[ii][4],y[ii]);
	}
		printf("  \n");
//partial pivoting end

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

	    for(int jj=0;jj<n;jj++){
		printf(" %e\t %e\t %e\t %e\t %e\t   %e\n",
			a[jj][0],a[jj][1],a[jj][2],a[jj][3],a[jj][4],y[jj]);
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
	    for(int ii=0;ii<n;ii++){
			printf(" %e\t %e\t %e\t %e\t %e\t   %e\n",
				a[ii][0],a[ii][1],a[ii][2],a[ii][3],a[ii][4],y[ii]);

		}
		printf("  \n");

	}
    for(i=0;i<n;i++){
		printf(" y[%d]=%e\n",i,y[i]);
	}
	return 0;
}