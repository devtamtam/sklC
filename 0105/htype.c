#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[]){
	
	FILE *fin;
	char buf[256];
	int ct =0, min, max;
	
	if(argc !=4){
		printf("用法：headtype filename hajime owari\n");
		return 1;
	}
	
	if((fin=fopen(argv[1],"r"))== NULL){
		printf("%sファイルをひらけへんかった\n",argv[1]);
		return 1;
	}
	
	min=atoi(argv[2]);
	max=atoi(argv[3]);
	
	while(fgets(buf,256,fin)!=NULL){
		++ct;
		if(ct>max)break;
		if(ct>=min)printf("%s",buf);
		
	}
	
		return 0;
	}