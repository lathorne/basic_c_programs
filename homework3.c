//Logan Thorneloe
//ECEn 424 Winter 2019
//Homework 3

#if 0

//DIFFERENCES: MODE_A does a movl isntead of movq for action = *p1. Also action is put in rcx instead of rdx

typedef enum {MODE_A, MODE_B, MODE_C, MODE_D, MODE_E} mode_t;

//Problem 1 (3.62)
long switch3(long *p1, long *p2, mode_t action){
	long result = 0;

	switch(action){
		case MODE_A:

			result = *p2; 
			action = *p1;
			*p2 = action; 
			break;

		case MODE_B:

			result = *p2;
			result = result + *p1;
			*p1 = result;
			break;

		case MODE_C:

			*p1 = 59;
			result = *p2; 
			break;

		case MODE_D:

			result = *p2;
			*p1 = result;

		case MODE_E:

			result = 27;
			break;

		default:

			result = 12;
	}
	return result;
}


int main(){
	long x = 40000000000000;
	long y = 600000000000;
	mode_t first_mode = 2;
	switch3(&x, &y, first_mode);
}

#endif

#if 0
//problem 2 (problem 3.63)

long switch_prob(long x, long n){
	long result = x;
	switch(n){
		case(62): //proceed to case 0
		case(60):
			result = x * 8; //load address of x * 8 insto result
			break;

		case(63):
			result = x;
			result >>= 3;
			break;

		case(64):
			result = x;
			result <<= 4;
			result -= x;
			x = result;
			//proceed to case 5

		case(65):
			x = x * x;
			//proceed to default

		case(61): //proceed to default

		default: //if n is above 5 it will automatically go to the default
			result = x + 75; //load address of x offset by 0x4b into result
	}

	return result;

}

int main(){
	switch_prob(4785940 , 62);
}

// 00000000004004d6 <switch_prob>:
  // 4004d6:       48 83 ee 3c             sub    $0x3c,%rsi
  // 4004da:       48 83 fe 05             cmp    $0x5,%rsi
  // 4004de:       77 29                   ja     400509 <switch_prob+0x33>
  // 4004e0:       ff 24 f5 a8 05 40 00    jmpq   *0x4005a8(,%rsi,8)
  // 4004e7:       48 8d 04 fd 00 00 00    lea    0x0(,%rdi,8),%rax
  // 4004ee:       00
  // 4004ef:       c3                      retq
  // 4004f0:       48 89 f8                mov    %rdi,%rax
  // 4004f3:       48 c1 f8 03             sar    $0x3,%rax
  // 4004f7:       c3                      retq
  // 4004f8:       48 89 f8                mov    %rdi,%rax
  // 4004fb:       48 c1 e0 04             shl    $0x4,%rax
  // 4004ff:       48 29 f8                sub    %rdi,%rax
  // 400502:       48 89 c7                mov    %rax,%rdi
  // 400505:       48 0f af ff             imul   %rdi,%rdi
  // 400509:       48 8d 47 4b             lea    0x4b(%rdi),%rax
  // 40050d:       c3                      retq

#endif

#if 0
//problem 3 (3.65)
//a) rdx
//b) rax
//c) M = 15, 120/8 
//d) see code below

#include <stdio.h>
#define M 4
//typedef int Marray_t[M][M];

void print_matrix(long A[M][M]) {
	long i,j;
	for (i = 0; i < M; i++) {
		for (j = 0; j < M; j++) {
			printf("%8d   ", A[i][j]);
		}
		printf("\n");
	}	
}

void transpose(long A[M][M]) {
	long i, j;
	for(i = 0; i < M; i++) {
		for (j = 0; j < i; j++) {
			long t = A[i][j];
			A[i][j] = A[j][i];
			A[j][i] = t;
		}	
	}
}

void transpose_optimized(long A[M][M]) {
	long i, j;
	for(i = 0; i < M; i++) {
		for (j = 0; j < i; j++) {
			long t = *(*(A + i) + j); //each M is 4-bytes because it is a long array 			
			*(*(A + i) + j) = *(*(A + j) + i);			
			*(*(A + j) + i) = t;			
		}	
	}
}

int main() {
	long i, j;
	long A[M][M] = {{1,2,3,4},{1,2,3,4},{1,2,3,4},{1,2,3,4}};
	print_matrix(A);
	printf("\n");
	// transpose(A);
	transpose_optimized(A);
	print_matrix(A);
}

#endif

#if 0

//problem 4 (3.70)

//a) offsets:
//e1.p = 4 bytes on 32-bit machine, 8 bytes on 64-bit machine (starts at the beginning of union, so 0 byte offset)
//e1.y = 4 bytes for a 32-bit value, (starts at either an 8 or 4 byte offset depending on machine)
//e2.x = 4 bytes for 32-bit value, starts at the beginning of the union, so 0 byte offset)
//e2.next = union pointer takes up 32 bits or 64 bits depending on the machine (8 byte offset due to e2.x)

//b) The total structure (the union) requires 64 bits + 64 bits = 16 bytes (a long is 64-bits on a 64-bit machine)

//c)    up->e2.x = *(up->e2.next->e1.p) - (up->e2.next->e1.y);
//	    movq    8(%rdi), %rdx
//      movq    (%rdx), %rax
//      movq    (%rax), %rax
//      subq    8(%rdx), %rax
//      movq    %rax, (%rdi)
//      ret

union ele {
	struct {
		long *p;
		long y;
	} e1;
	struct {
		long x;
		union ele *next;
	} e2;
};

void proc(union ele *up){
	up->e2.x = *(up->e2.next->e1.p) - (up->e2.next->e1.y); 
}

int main(){

}

#endif