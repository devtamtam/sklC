#include <stdio.h>
#include <math.h>
#include <time.h>

double f(double a, double b, double x){
	return pow(x,a)+b;
}

int main(){
	FILE *fp;//�t�@�C�����I��
	char dummy[256];//��ǂݗp
	int ret;
    double k[128],x[128],y[128],a,az,b,bz,s,sz;//�z��̗v�f�̐��͑��߂�
	int i,j,nz;
	double fi;
	long t0,t1;//���̑�������
	double tz; 
	double amin=-1.0,amx=-5.8,da=0.001;
	double bmin=-1.0,bmx=3.8,db=0.001;
	fp = fopen("ex-07-3.txt","r"); //�f�[�^�t�@�C���v��ǂݎ���pr�ŊJ���B
    fgets(dummy,256,fp); //1�s�ڂ���ǂ݂���B
	j=1;
	while( ( ret = fscanf( fp,"%l\t%lf\t%lf",&k[j],&x[j],&y[j]) ) != EOF ){  //�f�[�^ x[j],y[j] ��ǂށB����R�[�h \t��Tab�B�m�n�sEOF�ł������J��Ԃ��B
	                                       //2�s�ڂ���ǂݎ��A��s�ڂ͋�ǂݍς�
		nz=j; //nz:�f�[�^��
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
	t0=clock(); //�v�Z�J�n���̃N���b�N�J�E���^
	sz=1.E20;
	az=amin;
	bz=bmin;
    for(a=amin;a<=amx;a+=da){
		printf(" \r"); // ����R�[�h \n�ŉ��s�C\r�͉��s�����ɍs���ֈړ��B
		// �A��insert�\���ł���rewind��r
		printf("Checking	a= %f",a); //��������a��\���B
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
	t1=clock(); //�v�Z�I�����̃N���b�N�J�E���^�B
	tz=double(t1-t0)/CLK_TCK; //�v�Z�ɗv�������ԁi�b�P�ʁj���v�Z�B
	printf(" tz=%f \n",tz);
	return 0;
}