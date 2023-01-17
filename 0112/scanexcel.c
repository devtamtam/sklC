#include<stdio.h>
#include<stdlib.h>
int main(void){
		
        FILE *fin;
		int x[100], y[100],i;
		double Xave,Yave,X=0.0,Y=0.0;
        if((fin=fopen("data.csv","r"))== NULL){
                printf("ファイルをひらけへんかった\n");
                return 1;
        }
		
		for(i=0;i<100;i++){
		fscanf(fin, "%d,%d", &x[i], &y[i]);
		}
		
		for(i=0;i<100;i++){
			X+=x[i];
			Y+=y[i];
		}
		
		printf("x,yの平均値はそれぞれ%f,%f\n",X/100.0,Y/100.0);
		
		fclose(fin);
                return 0;
        }