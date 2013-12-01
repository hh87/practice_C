#ifndef _MYMATH_H
#define _MYMATH_H

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct mycomplex{
	float re;
	float im;
}complex;
complex RoW(int N);
complex Cmult(complex a,complex b);
complex Cmult1(float a,complex b);
complex Cmult2(complex a,float b);
complex Cdiv(complex a,complex b);
complex Cdiv1(complex a,float b);
complex Cdiv2(float a,complex b);
complex Cconj(complex a);
float 	Cabs(complex a);
complex Cadd(complex a,complex b);
complex Cminus(complex a,complex b);
complex Cpow(complex a,int n);
void Cprintf(complex a);

#endif
