#all:fft

test_fft:fft.o test_fft.o mymath.o
	gcc fft.o test_fft.o mymath.o -LS -o test_fft -lm

#	gcc -Wall fft.c -o fft -lm
fft.o:fft.c fft.h
	gcc -c fft.c -lm
test_fft.o:test_fft.c mymath.h
	gcc -c test_fft.c -lm

mymath.o: mymath.c mymath.h
	gcc -c mymath.c -lm

test:fft
	./fft 1
run:fft
	./fft time_domain_data.txt


clean:
	-rm *.o
	-rm test_fft
