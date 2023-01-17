#include<stdio.h>
#include<stdlib.h>

int comp(int a,int b){
	if(a>b)return 1;
	else return 0;
}

int main(void){
		
        FILE *fin;
		int i,n=0,m=0,x[100], y[100];
		
		if((fin=fopen("data.csv","r"))== NULL){
                printf("ファイルをひらけへんかった\n");
                return 2;
        }
		
		for(i=0;i<100;i++){
		fscanf(fin, "%d,%d", &x[i], &y[i]);
		}
		
		for(i=0;i<100;i++){
			if(comp(x[i], y[i])==0)n++;
			else m++;
		}
		if(n+m==100)puts("正しい個数のデータを読み込みました");//エラー判定も付けました
		else puts("読み込んだデータの個数が異常です");
		
		printf("x>yになる組数は%d\nx<yになる組数は%d\n",n,m);
		
		fclose(fin);
        return 0;
}