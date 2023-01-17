#include<stdio.h>

/*　.cのファイル名はtyp.c*/
int main(){
	
	FILE *fin;
	char buf[256];
	
	fin=fopen("smp1.txt","r");
	if(fin==NULL){
		printf("couldn't open the file\n");
		return 1;
	}
	
	while (fgets(buf,256,fin)!=NULL){
		printf("%s",buf);
	}
	
	fclose(fin);
	
	return 0;
}