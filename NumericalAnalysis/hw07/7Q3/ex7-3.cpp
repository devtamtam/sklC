#include <stdio.h>
#include <math.h>
#include <time.h>

double f(double a, double b, double x){
	return a*x + b;
}

int main(){
	FILE *fp;//ファイル名的な
	char dummy[256];//空読み用
	int ret;
    double x[128],y[128],a,az,b,bz,s,sz;//配列の要素の数は多めに
	int i,j,nz;
	double fi;
	long t0,t1;//桁の多い整数
	double tz; 
	double amin=0.0,amx=3.0,da=0.001;
	double bmin=0.0,bmx=5.0,db=0.001;
	fp = fopen("ex-07-3.txt","r"); //データファイル「lesson-07.txt」を読み取り専用rで開く。
    fgets(dummy,256,fp); //1行目を空読みする。
	j=1;
	while( ( ret = fscanf( fp,"%lf\t%lf",&x[j],&y[j]) ) != EOF ){  //データ x[j],y[j] を読む。制御コード \tはTab。ＮＯＴEOFである限り繰り返す。
	                                       //2行目から読み取り、一行目は空読み済み
		nz=j; //nz:データ数
		j=j+1;
	}
	fclose(fp);
	printf(" N= %d\n",nz);
	printf(" Last,  x= %f ,	y= %f\n",x[nz],y[nz]);
	printf(" a_min= %f ,	a_max= %f\n",amin,amx);
	printf(" b_min= %f ,	b_max= %f\n",bmin,bmx);
/*	for(j=1;j<=nz;j++){
		printf(" %f	%f \n",x[j],y[j]);
	} */
	t0=clock(); //計算開始時のクロックカウンタ
	sz=1.E20;
	az=amin;
	bz=bmin;
    for(a=amin;a<=amx;a+=da){
		printf(" \r"); // 制御コード \nで改行，\rは改行せずに行頭へ移動。
		// 連続insert表示できるrewindのr
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
      }//b'Zloop end
    }//a'z loop end
	printf("  \n");
	printf(" a=%7.3f     b=%7.3f \n",az,bz);
	printf(" s=%10.3e \n",sz);
	printf("  \n");
	t1=clock(); //計算終了時のクロックカウンタ。
	tz=double(t1-t0)/CLK_TCK; //計算に要した時間（秒単位）を計算。
	printf(" tz=%f \n",tz);
	return 0;
}
