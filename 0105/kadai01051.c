#include<stdio.h>
#include<math.h>
int main(void){
    FILE *fout;
	double dx,y;
	char buf[256];
	
	if((fout=fopen("data.csv","w"))== NULL){/*data.csv�Ȃ���������*/
		printf("�o�̓t�@�C�����Ђ炯�ւ񂩂���\n");
		return 1;
	}
	
	for(dx=0.0;dx<=5.0;dx+=0.1){
	
	y=exp(dx);
	fprintf(fout,"%f,%f\n",dx,y);

	}
	
	fclose(fout);
	
	
	return 0;
}