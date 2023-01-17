#include <stdio.h>
#include <stdlib.h>	// rand を使うために必要

int main(void){
	
 FILE *fout;
	int ID = 70,x,y,i;	
	srand(ID);		// 乱数の初期化
	
	if((fout=fopen("data.csv","w"))== NULL){/*data.csvなかったら作る*/
                printf("出力ファイルをひらけへんかった\n");
                return 1;
        }
	
	
	
	for(i=0;i<100;i++){
		x = rand();	// 実行するたびに異なる数字を生成
		y = rand();
		fprintf(fout,"%d,%d\n",x, y);
	}
	fclose(fout);
	return 0;
}
