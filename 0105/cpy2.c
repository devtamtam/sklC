#include<stdio.h>
int main(int argc, int *argv[]){
	FILE *fin, *fout;
	char buf[256];
	
	if(argc !=3){
		puts("正しいコマンドラインは：cpy2 copy元 copy先");
		return 1;
	}
	
	if((fin=fopen(argv[1],"r"))==NULL){
		printf("couldnt open %s\n",argv[1]);
		return 1;
	}
	
	if((fout=fopen(argv[2],"w"))==NULL){
		printf("couldnt open %s\n",argv[2]);
		return 1;
	}
	
	
	while(fgets(buf, 256,fin)!=NULL){
		fputs(buf,fout);
	}
	
	fclose(fin);
	fclose(fout);
	
	return 0;
}