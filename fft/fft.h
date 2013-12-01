#ifndef _FFT_H
#define _FFT_H

#include "mymath.h"

#define MAXFFT 65536 

int readtxt(char *filename,complex *data); 
int fft(complex *xn , int N ,complex *Xk); 


#endif
