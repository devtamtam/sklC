#include<stdio.h>
int main(){
	FILE *fin, *fout;
	char buf[256];
	
	if((fin=fopen("smp1.txt","r"))== NULL){
		printf("finファイルをひらけへんかった\n");
		return 1;
	}
	
	if((fout=fopen("smp2.txt","w"))== NULL){/*smp2 なかったら作る*/
		printf("foutファイルをひらけへんかった\n");
		return 1;
	}
	
	while(fgets(buf,256,fin)!= NULL){
		fputs(buf,fout);
	}
	
	fclose(fin);
	fclose(fout);
	
	return 0;
}