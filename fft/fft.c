#include "fft.h"
#include "mymath.h"

#define DEBUG 0

int fft(complex *xn , int N ,complex *Xk){
	//return N/2
	int remain=N/2;
	complex *xn1,*xn2;
	complex *Xk1,*Xk2;
	complex WN = RoW(N);
	int i,k,kp;
	xn1 = (complex*) malloc(remain * sizeof(complex));
	Xk1 = (complex*) malloc(remain * sizeof(complex));
	xn2 = (complex*) malloc(remain * sizeof(complex));
	Xk2 = (complex*) malloc(remain * sizeof(complex));
	for(i=0 ; i < remain ;i++){
		*(xn1+i) = *(xn+2*i);
		*(xn2+i) = *(xn+2*i+1);
	}
	if(remain == 1){
		if(DEBUG){
			printf("2-point FFT\n");
			Cprintf(*xn1);
			Cprintf(*xn2);
		}
		*Xk = Cadd(*xn1 , *xn2);
		*(Xk+1) =Cminus(*xn1 , *xn2);
	}
	else{
	//	printf("stage %d\n",remain);
				
		fft(xn1 , remain , Xk1);
		fft(xn2 , remain , Xk2);
		
		for(k=0;k<N;k++){
			if(k<N/2){
				*(Xk+k)=Cadd(*(Xk1+k),Cmult(*(Xk2+k),Cpow(WN,k)));
			}else{
				kp=k-N/2;
				*(Xk+k)=Cminus(*(Xk1+kp),Cmult(*(Xk2+kp),Cpow(WN,kp)));
			}
		}

	}		
	return N/2;
}

int readtxt(char *filename , complex *data){
	FILE *fp = fopen(filename,"r");
	if(fp == NULL){
		printf("file open failed!\n");
		exit(0);
	}
	int length=0;
	while(!feof(fp)){
		fscanf(fp,"%f + %fi\n",&((*data).re),&((*data).im));
		data++;
		length++;
	}
	return length;
}

/*
int main(int agrc ,char *argv[]){ 
	if(agrc != 2){
		printf("usage:fft time_domain_data.txt\n");
		exit(0);
	}
	//complex Xk[MAXFFT];
	complex a[MAXFFT]; 
	int length; 
	int idx;
	length = readtxt(argv[1],a);//N-fft
			
	complex *xn;
	complex *Xk;
	xn =(complex*) malloc(length * sizeof(complex));
	Xk =(complex*) malloc(length * sizeof(complex));
	xn = a;
	
	
	//test code 
	printf("FFT length: %d\n",length);
	fft(xn,length,Xk);
	printf("result\n");
	for (idx = 0 ; idx < length ;idx++){
		Cprintf(Xk[idx]);
		
	}
	//end of test code 
	printf("finished!\n");
	return 1;
}

*/

