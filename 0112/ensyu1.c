#include <stdio.h>
#include <stdlib.h>	// rand ���g�����߂ɕK�v

int main(void){
	
 FILE *fout;
	int ID = 70,x,y,i;	
	srand(ID);		// �����̏�����
	
	if((fout=fopen("data.csv","w"))== NULL){/*data.csv�Ȃ���������*/
                printf("�o�̓t�@�C�����Ђ炯�ւ񂩂���\n");
                return 1;
        }
	
	
	
	for(i=0;i<100;i++){
		x = rand();	// ���s���邽�тɈقȂ鐔���𐶐�
		y = rand();
		fprintf(fout,"%d,%d\n",x, y);
	}
	fclose(fout);
	return 0;
}
