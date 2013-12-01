#include "mymath.h"

complex RoW(int N){
	complex WN;
	WN.re = cos(2*M_PI/N);
	WN.im = -sin(2*M_PI/N);
	return WN;
}
void Cprintf(complex a){
	if(a.im < 0){
		printf("%f - %fi\n",a.re,-a.im);
	}else{
		printf("%f + %fi\n",a.re,a.im);
	}
}


complex Cadd(complex a,complex b){
	complex c;
	c.re = a.re + b.re;
	c.im = a.im + b.im;
	return c;
}

complex Cminus(complex a,complex b){
	complex c;
	c.re = a.re - b.re;
	c.im = a.im - b.im;
	return c;
}

complex Cpow(complex a,int n){
	complex c;
	int i;
	if(n==0){
		c.re = 1;
		c.im = 0;
	}else if(n < 0){
		printf("error!power n > 0\n");
		exit(0);
	}else{
		c = a;
		for (i = 1; i <= n-1 ;i++){
			c = Cmult(c,a);
		}
	}
	return c;
}

complex Cmult(complex a,complex b){
	//return a * b
	complex c;
	c.re = a.re * b.re - a.im * b.im;
	c.im = a.re * b.im + a.im * b.re;
	return c;
}

complex Cmult1(float a,complex b){
	complex c;
	c.re = b.re * a;
	c.im = b.im * a;
	return c;
}

complex Cmult2(complex a,float b){
	complex c;
	c = Cmult1(b,a);
	return c;
}
complex Cconj(complex a){
	//return a'
	complex c;
	c.re = a.re;
	c.im = -a.im;
	return c;
}

float Cabs(complex a){
	float c;
	c = sqrt(a.re * a.re + a.im * a.im);
	return c;
}

complex Cdiv(complex a,complex b){
	complex c;
	c = Cmult(a,Cconj(b));
	c.re /= Cabs(b);
	c.im /= Cabs(b);
	return c;
}

complex Cdiv1(complex a,float b){
	complex c;
	c.re = a.re / b;
	c.im = a.im / b;
	return c;
}

complex Cdiv2(float a,complex b){
	complex c;
	c = Cdiv1(Cmult1(a,Cconj(b)),Cabs(b));
	return c;
}

