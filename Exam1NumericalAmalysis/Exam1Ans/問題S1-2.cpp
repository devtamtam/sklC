#include <stdio.h>
#include <math.h>

int main(){
	int id=45;
	int n=6;
    double b[6];
	double bb,z;
	int i,j;

	bb=float(id)*0.2;
		double a[6][6] ={
			{ 2.0,-1.0,-4.0,-4.0,-1.0, 2.0 },
			{ 2.0, 4.0, 3.0, 2.0,-2.0, 2.0 },
			{-3.0, 1.0, 4.0,-4.0, 3.0, 2.0 },
			{-1.0, 0.0,-2.0, 2.0, 1.0, 1.0 },
			{-2.0, 3.0,-1.0,-1.0,-2.0,-3.0 },
			{ 4.0,-4.0,-3.0,-4.0,-3.0,-4.0 },
		};
		double y[6] = { 3.0,-2.0, 0.0, bb, 2.0,-1.0};

		printf("  \n");
		for(int ii=0;ii<n;ii++){
			printf(" %f\t %f\t %f\t %f\t %f\t %f\t  %f\n",
				a[ii][0],a[ii][1],a[ii][2],a[ii][3],a[ii][4],a[ii][5],y[ii]);
		}
		printf("  \n");
		printf(" id\t x_1\t\t x_2\t\t x_3\t\t x_4\t\t x_5\t\t x_6\n");

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
		}

		for(i=n-1;i>0;i=i-1){
			for(int k=i-1;k>=0;k=k-1){
				z=a[k][i];
				for(j=k+1;j<n;j++){
					a[k][j]=a[k][j]-a[i][j]*z;
				}
				y[k]=y[k]-y[i]*z;
			}
		}
		printf(" %d",id);
	    for(i=0;i<n;i++){
			printf("\t");
			printf(" %f",y[i]);
		}
		printf("\n");

	return 0;
}
