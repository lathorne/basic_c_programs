

//problem 1 (2.87)

//Description		Hex		M				E		V					D
//-0				8000	0				-15		-0					-0.0
//Smallest > 2		4001	1025/1024		1		1025*2^-9			2.00195
//512				6000	0				9		512					512.0
//largest denorm	03ff	1023/1024		-14		1023*2^-24			0.0000609755		
//neg infinity		fc00	-				-		-					-
//3bb0				3bb0	123/64			-1		123*2^-7			0.9609375	
			

#if 0
//problem 2 (2.93)
//test code starts here
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned float_bits;

/* Convert a unsigned to a float Converts without changing the bit
 * representation. A normal cast from an unsigned to a float results
 * in the bit representation changing. The number 3 as an unsigned
 * doesn't have the same representation as the number 3 as a float.
 */

float u2f(unsigned u) {
    return *((float *) &u);
}

/* Convert a float to an unsigned without changing the bit representation.
 */

unsigned f2u(float f) {
    return *((unsigned *) &f);
}


float_bits float_absval(float_bits f) {
    // Fill in your code here
	if(((f | 0xff800000) != 0xff800000) && ((f & 0x7f800000) == 0x7f800000)){ //check for a NaN
		return f;
	}
    return 0x7fffffff & f;	 //otherwise, make the sign bit zero and return
}


int main() {
    float_bits loop = 0;
    do {
	float f = u2f(loop);	
	float my_abs = u2f(float_absval(loop));
  	// weird test because NaN != NaN
	if (((f == f) && my_abs != fabsf(f)) || !(f == f) && (my_abs == my_abs)) {
	    printf("ERROR! Input %e, your abs value = %e and c library"
		   " gives %e\n", f, my_abs, fabs(f));
	    exit(-1);
	}
	loop++;
    } while (loop);
    printf("All 2^32 values check out\n");

    // Show a few test cases that are interesting to turn in with your hw
    float f = -1;
    printf("Input: %e\n\t My abs: %e\n\t C abs: %e\n", f, u2f(float_absval(f2u(f))), fabs(f));

    f = 2;
    printf("Input: %e\n\t My abs: %e\n\t C abs: %e\n", f, u2f(float_absval(f2u(f))), fabs(f));

    f = 4;
    printf("Input: %e\n\t My abs: %e\n\t C abs: %e\n", f, u2f(float_absval(f2u(f))), fabs(f));

    f = -5067829280;
    printf("Input: %e\n\t My abs: %e\n\t C abs: %e\n", f, u2f(float_absval(f2u(f))), fabs(f));

    return 0;
}

#endif

#if 0
//problem 3 (3.58)

long decode2(long x, long y, long z){
	long r;
	y = y - z;
	x = y * x;
	r = y;
	r <<= 63;
	r >>= 63;
	return r ^ x;
}

int main(){

	return 0;
}

#endif

//problem 4 (3.59)

// annotations for the problem
// 2. copy y into multiplicand (rax)
// 3. sign extend y, put high order bits in rdx and low order bits in rax (cqto only works on rax)
// 4. move x to rsi
// 5. sign extend rsi(x), put bits in rcx
// 6. lower bits of y * upper bits of x multiplied and lower bits stored in rcx 
// 7. upper bits of y * lower of x multiplied and lower bits of result sotred in rdx
// 8. adding rdx and rcx, puts it in rcx
// 9. multiply rsi and rax and store upper bits of result in rdx and lower bits in rax
// 10. adds rcx and rdx and stores it in rdx
// 11. moving rax into lower order bits of what is pointed at by rdi
// 12. moving rdx into the high order bits of what is pointed at by rdi

//problem 5 (3.60)

//assembly code
// loop:
// 	movl   %esi, %ecx
// 	movl   $1, %edx
// 	movl   $0, %eax
// 	jmp    .L2
// .L3:
// 	movq   %rdi, %r8
// 	andq   %rdx, %r8
// 	orq    %r8, %rax
// 	salq   %cl, %rdx
// .L2:
// 	testq  %rdx, %rdx
// 	jne    .L3
// 	rep;   ret

#if 1
//c code
long loop(long x, int n)
{
	long result = 0;
	long mask;
	for(mask = 1; mask != 0; mask = mask << n){
		result |= (mask & x);
	}
	return result;
}

// a) x is in %rdi, n is in %esi, result is in %rax, mask is in %rdx
// b) result = 0, mask = 1
// c) checking if mask is equal zero
// d) mask is shifted by n each loop
// e) result is OR'd with mask AND'd with x
// f) see included C code for this problem

#endif
