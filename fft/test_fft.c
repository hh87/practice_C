#include <stdio.h>
#include "mymath.h"
#define MAXFFT 65536


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
