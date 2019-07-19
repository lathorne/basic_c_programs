#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

int any_bit_one(int x) {
    // Fill in code for part A here.
    bool a = x; //answer for a
    return a;
}

int any_bit_zero(int x) {
    // Fill in code for part B here.
    bool b = ~x; //answer for b	
    return b;
}

int lsb_one(int x) {
    // Fill in code for part C here.
    bool c = x & 0xFF; //answer for c
    return c;	
}

int msb_zero(int x) {
    // Fill in code for part D here.	
    int xright = x >> (sizeof(int)-1 << 3); //arithmetic shift x to the right
	int msb = xright & 0xFF; //set all to 0 except the most significant byte, which has now been shifted
	bool d = ~(msb) & 0xFF; //sets everything to 0, except for the original 0's in the msb of x
	return d;
}

//problem 1
void problem261(){

	int x;
    // Test all integer values
    for (x = INT_MIN; x <= INT_MAX; x++) {
		if (any_bit_one(x) != (x != 0)) {
		    printf("Any bit in x equal to 1	FAILED!\n");
		    break;
		}
		if (any_bit_zero(x) != (x != -1)) {
		    printf("Any bit in x equal to 0 FAILED!\n");	
		    break;
		}
		if (lsb_one(x) != ((char)x != 0)) {
		    printf("Any bit in least significant byte in x equal to 1 FAILED!\n");	
		    break;
		}
		if (msb_zero(x) != (*((char*)&x + 3) != -1)) {
		    printf("Any bit in most significant byte in x equal to 0 FAILED!\n");	
		    break;
		}

		// Print out something so you know that stuff is happening
		if (x % 100000000 == 0) {
		    printf("%d\n", x);	
		}

		// Have to have a way to break out before we loop around to INT_MIN
		if (x == INT_MAX) {
		    printf("All tests passed!\n");	
		    break;
		}	
	}
	
    // Enter the numbers you want to test
    int any_bit_one_test_cases[5] = {0xffffffff, 0x00000011, 0x11000000,0x00000000, 0x11111111};
    int i;
    for (i = 0; i < 5; i++) {
	printf("any_bit_one(0x%08x) = %d\n", any_bit_one_test_cases[i],
	       any_bit_one(any_bit_one_test_cases[i]));
    }

    printf("\n");
    // Enter new set of test cases
    int any_bit_zero_test_cases[5] = {0xffffffff, 0x00000011, 0x11000000,0x00000000, 0x11111111};
    for (i = 0; i < 5; i++) {
	printf("any_bit_zero(0x%08x) = %d\n", any_bit_zero_test_cases[i],
	       any_bit_zero(any_bit_zero_test_cases[i]));
    }

    printf("\n");
    // Enter new set of test cases
    int lsb_one_test_cases[5] = {0xffffffff, 0x00000011, 0x11000000,0x00000000, 0x11111111};
    for (i = 0; i < 5; i++) {
	printf("lsb_one(0x%08x) = %d\n", lsb_one_test_cases[i],
	       lsb_one(lsb_one_test_cases[i]));
    }

    printf("\n");
    // Enter new set of test cases
    int msb_zero_test_cases[5] = {0xffffffff, 0x00000011, 0x11000000,0x00000000, 0x11111111};
    for (i = 0; i < 5; i++) {
	printf("msb_zero(0x%08x) = %d\n", msb_zero_test_cases[i],
	       msb_zero(msb_zero_test_cases[i]));
    }
    return;	
}

/* declaration of data type where 4 bytes are packed 
   into an unsigned */

typedef unsigned packed_t;

/* extract byte from word. Return as signed integer */
int xbyte(packed_t word, int bytenum)
{
    return (word >> (bytenum <<3)) & 0xFF;
}

//xbyte function for problem 2.71
int myxbyte(unsigned word, int bytenum){
	int shiftleftamount = ((3 - bytenum) << 3); //this gives us how much we need to shift the byte left
	//this will arithmetic shift the byte we need right to be the most significant byte and then arithmetic
	//shift it left so it is in the least significant byte spot
	return (int)(word << shiftleftamount) >> 24; 
}

//problem 2
void problem271(){
	//a) this code will make the upper 24 bits always equal to zero, therefore, it does not sign extend
	//a correct implementation is in the myxbyte function
	/* set x to obvious byte pattern */
    packed_t x = 0x1234ABFF;

    printf("Packed value (x) = 0x%x, value returned by xbyte(x,0) = 0x%x\n",
	   x, xbyte(x,0));
    printf("Packed value (x) = 0x%x, value returned by xbyte(x,1) = 0x%x\n",
	   x, xbyte(x,1));
    printf("Packed value (x) = 0x%x, value returned by xbyte(x,2) = 0x%x\n",
	   x, xbyte(x,2));
    printf("Packed value (x) = 0x%x, value returned by xbyte(x,3) = 0x%x\n",
	   x, xbyte(x,3));
    

    printf("Packed value (x) = 0x%x, value returned by myxbyte(x,0) = 0x%x\n",
	   x, myxbyte(x,0));
    printf("Packed value (x) = 0x%x, value returned by myxbyte(x,1) = 0x%x\n",
	   x, myxbyte(x,1));
    printf("Packed value (x) = 0x%x, value returned by myxbyte(x,2) = 0x%x\n",
	   x, myxbyte(x,2));
    printf("Packed value (x) = 0x%x, value returned by myxbyte(x,3) = 0x%x\n",
	   x, myxbyte(x,3));
}

void new_copy_int(int val, void *buf, int maxbytes){
	int size = maxbytes - sizeof(val); //cast it to make it signed
	if(size >= 0){ //the expression defaults to signed instead of unsigned
		// printf("IN BUFFER SETTER\n\r"); //this will only print when the expression evaluates true
		memcpy(buf, (void *) &val, sizeof(val));
	}
}

void copy_int(int val, void *buf, int maxbytes){
	if(maxbytes - sizeof(val) >= 0){
		// printf("IN BUFFER SETTER\n\r"); //this will only print when the expression evaluates true
		memcpy(buf, (void *) &val, sizeof(val));
	}
}

#define LENGTH 6

//problem 3

//a) when maxbytes - sizeof(val) is evaluated, the maxbytes (which is signed), is converted to 
	//unsigned which causes the expression to always evaluate as true because its always >=0
	//b) the proper conditional is shown in the new_copy_int function
	//this test code below tests both functions
void problem272(){

	int x;
	char y[LENGTH];

	//this code shows the old code does not work
	int i,j;
    /* set x to obvious byte pattern */
    x = 0x01234567;
    for (j = 0; j < LENGTH; j++)
    {
	/* reset all of y before test */
	for (i = 0; i < LENGTH; i++)
	    y[i] = 0x00;
	/* do test: call copy_int() */
	copy_int(x, &y[j], LENGTH-j);
	/* output all of y to see what happened */
	printf("iteration %d\ny: ",j);
	for (i = 0; i < LENGTH; i++)
	    printf("%.2x ", (int) y[i]);
	printf("\n\n");
    }

    //this shows that the new code does
    /* set x to obvious byte pattern */
    x = 0x01234567;
    for (j = 0; j < LENGTH; j++)
    {
	/* reset all of y before test */
	for (i = 0; i < LENGTH; i++)
	    y[i] = 0x00;
	/* do test: call copy_int() */
	new_copy_int(x, &y[j], LENGTH-j);
	/* output all of y to see what happened */
	printf("iteration %d\ny: ",j);
	for (i = 0; i < LENGTH; i++)
	    printf("%.2x ", (int) y[i]);
	printf("\n\n");
    }
}

//problem 4
void problem277(){
	/* We are to write C expressions that multiply integer variable x
       by various values of K using only +, -, and << operators, and
       no more than 3 operators total. */

    int x = 7;
    int K;
    int result1;
    int result2;
    
    /* Example: K = 9 */
    K = 9;
    result1 = (x << 3) + x;  /* you create expressions like this one */
    result2 = K * x;         /* compute using multiply to compare */
    printf("K=9: +-<< result = %d, * result = %d\n", result1, result2);
    
    /* Part A */
    K = 17;
    result1 = (x << 4) + x;   /* replace this 0 with your C expression */
    result2 = K * x;
    printf("K=17: +-<< result = %d, * result = %d\n", result1, result2);
    
    /* Part B */
    K = -7;
    result1 = x - (x << 3);   
    result2 = K * x;
    printf("K=-7: +-<< result = %d, * result = %d\n", result1, result2);
    
    /* Part C */
    K = 60;
    result1 = (x << 6) - (x << 2);
    result2 = K * x;
    printf("K=60: +-<< result = %d, * result = %d\n", result1, result2);
    
    /* Part D */
    K = -112;
    result1 = (x << 4) - (x << 7);   
    result2 = K * x;
    printf("K=-112: +-<< result = %d, * result = %d\n", result1, result2);
}

//problem 5
void problem282(){
	// a) false, using INT_MIN as x gives us a false value because negating the smallest number gives us the smallest number
	// b) always true, shifting bits is the same as multiplying by the power of the shift, distributing the multiplication
	// yields both sides of the equation equivalent
	// c) always true, the definition of Two's Complement
	// d) always true, taking a negative of an unsigned integer is the same as subtracting the unsigned integer from 2^n
	// (in this case n is 32)
	// e) always true, dividing a number by four and multiplying by four using bit shifting will never give you a 
	// number larger than the original number
}

//problem 6
void problem424(){
	float f,g;
	f = 0.0;
	g = f + 1.0;
	int count = 0; //adding int to count times through loop
	while (f != g)
	{
	    f = g;
	    g = f + 1.0;
	    count++;
	}
	printf("Does it ever get here?\n");
	printf("COUNT:%d", count); //print out the count

	// a) I would expect the loop to never terminate.
	// b) It did not do what I expected, it exited the loop.
	// c) It runs 16777216 times. This is how long it takes for 1.0 to become insignificant to the floating point 
	// value and it no longer adds it. Above 2^24 passes through the loop the resolution of the number becomes 
	// less than 1.0 and is no longer added. -will be better covered on Monday
	// d) It would run about 4.5e15 (2^53) times because there are 52 explicit bits in the fractional portion of a 
	// double (compared to the 23 of a float). Since the float took 2^24 passes, the double would be 2^53.
	// e) if the variables were an integer they would overflow as opposed to saturating and the loop would never end.
}

//main to run things
int main(){
	// problem261(); //run the first problem
	// problem271(); //run the second problem
	// problem272(); //run the third problem
	// problem277(); //run the fourth problem
	// problem282(); //run the fifth problem 
	// problem424(); //run the sixth problem
	return 1;
}


