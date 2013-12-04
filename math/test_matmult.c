#include "mymath.h"

int main(){
	complex a[2][3],b[3][2];
	complex c[2][2];
	a[0][0].re = 1;
	a[0][0].im = 2;
	a[0][1].re = -1;
	a[0][1].im = 2;
	a[0][2].re = 1;
	a[0][2].im = 2;;
	a[1][0].re = 1;
	a[1][0].im = 2;
	a[1][1].re = 1;
	a[1][1].im = 2;
	a[1][2].re = 1;
	a[1][2].im = 2;
	b[0][0].re = 1;
	b[0][0].im = 2;
	b[0][1].re = -1;
	b[0][1].im = 2;
	b[1][0].re = 1;
	b[1][0].im = 2;
	b[1][1].re = 1;
	b[1][1].im = 2;
	b[2][0].re = -1;
	b[2][0].im = 1;
	b[2][1].re = -1;
	b[2][1].im = 2;
	MatMult((complex **)a,(complex**)b,(complex**)c,2,3,2);
	int i,j;
	for(i = 0 ; i < 2; i++){
		for(j = 0 ; j < 2 ; j++){
			Cprintf(c[i][j]);
		}
	}
}
