#include <stdio.h>
#include <math.h>

double f(double a, double b, double x){
	return a*x+b;
}

int main(){
	FILE *fp;
	char dummy[256];
	int ret;
    double x[128],y[128],a,az,b,bz,s,sz;
	int i,j,nz,jj;
	double fi;
	double amin=0.0,amx=5.0,da=0.001;
	double bmin=0.0,bmx=3.0,db=0.001;
	fp = fopen("ex-07-3.txt","r"); //データファイル「ex-07-3.txt」を読み取り専用で開く。
    fgets(dummy,256,fp); //1行目を空読みする。
	j=1;
	while( ( ret = fscanf( fp,"%d\t%lf\t%lf",&jj,&x[j],&y[j]) ) != EOF ){  //データ jj,x[j],y[j] を読む。制御コード \tはTab。
		nz=j;
		j=j+1;
	}
	fclose(fp);
	printf(" N= %d\n",nz);
	printf(" Last,  x= %f ,	y= %f\n",x[nz],y[nz]);
	printf(" a_min= %f ,	a_max= %f\n",amin,amx);
	sz=1.E20;
	az=amin;
	bz=bmin;
    for(a=amin;a<=amx;a+=da){
		printf(" \r"); // 制御コード \nで改行，\rは改行せずに行頭へ移動。
		printf("Checking	a= %f",a); //検査中のaを表示。
      for(b=bmin;b<=bmx;b+=db){
		s=0.;
	    for(i=1;i<=nz;i++){
		  fi=f(a,b,x[i]);
          s=s+pow(fi-y[i],2);
	    }
        if(s<sz){
    	sz=s;
		az=a;
		bz=b;
        }
      }
    }
	printf("  \n");
	printf(" a= %9.5e   b=%9.5e \n",az,bz);
	printf(" s=%9.5e \n",sz);
	printf("  \n");
	return 0;
}
