
// Problem 1 (4.45)

// A. This would not work the pushed value needs to be stored so it does not change before being pushed
// B. Rewritten: 
// the practice problem example seems to show that we should store the register value here before moving it to the stack
// in the case of pushing %rsp, this would preserve the old value of %rsp which needs to be done, as can be seen by the example problem
// although the problem states the source would be a register
// movq %rsp %rdx 
// subq $8 %rsp
// movq REG (%rdx)

// Problem 2 (4.46)

// A. To me it seems like this would be right as the example problem explains that the value in memory needs to be stored in the register
// B. Rewritten: 
// movq (%rsp) REG
// addq $8 %rsp


// Problem 3 (424-2)

// A) 8381564 bytes
// B) 261895 is the max recursive size (each call took 32 bytes b/c int)

// C) I get seg faults when I overflow the stack. 
// The numbers would most likely be different with different operating systems due to the way they allocate the stack frame
// recursive function with m64: 261875 with m32: unable to try, cannot get files necessary to use -m32 flag
// stack allocated array with m64: same as before
// my guess is these numbers would be smaller on the 32-bit architecture
// the listed size is very close to my results, mine number is slightly higher
// I've noticed I can only set the stack size smaller, it did what I expected, but not by the same magnitude
// The "-Os" flag works wonders and at least tripled the recursive stack size


// #include <stdio.h>

// void stackAllocatedArray(){
// 	char arr[8381564]; //this many bytes
// 	printf("%d\n\r", sizeof(arr));
// }

// void recursionDepth(int i){
// 	printf("%d\n\r", i);
// 	i++;
// 	recursionDepth(i);
// }

// int main(){

// 	// stackAllocatedArray();
// 	recursionDepth(0);

// 	return 0;
// }
