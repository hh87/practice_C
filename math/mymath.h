#ifndef _MYMATH_H
#define _MYMATH_H

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct mycomplex{
	float re;
	float im;
}complex;
void SVD(complex **a,complex **u,complex **s,complex **v,int m,int n)//[u s v]=svd(a),a is m * n matrix
void MatMult(complex **a , complex **b ,complex **c , int m, int n ,int p);//matrix mult c=a * b,a is m * n matrix , b is n * p matrix,c is m * p matrix
complex RoW(int N);//rotain factor WN
complex Cmult(complex a,complex b);//complex a * b
complex Cmult1(float a,complex b);
complex Cmult2(complex a,float b);
complex Cdiv(complex a,complex b);//complex div a / b
complex Cdiv1(complex a,float b);
complex Cdiv2(float a,complex b);
complex Cconj(complex a);//conjaction of a
float 	Cabs(complex a);//abs(a)
complex Cadd(complex a,complex b);//complex add a + b 
complex Cminus(complex a,complex b);//complex minus a - b 
complex Cpow(complex a,int n);//complex power a ^ n
void Cprintf(complex a);

#endif
