# Execution begins at address 0 
	.pos 0
	irmovq stack, %rsp  	# Set up stack pointer
	call main		# Execute main program
	halt			# Terminate program 

# Array of 4 elements
	.align 8
array:	.quad 0xdddd          # These values should get sorted
        .quad 0xeeee
        .quad 0xbbbb
        .quad 0xaaaa
        .quad 0xffff
        .quad 0xcccc
        .quad 0x0101          # This value should not change


main:	irmovq array,%rdi
		irmovq $6,%rsi
		call Bubble		# Bubble(array, )
		ret

# void Bubble(long *data, long count)
Bubble:
     .LFB24:
		.cfi_startproc
		leaq	-1(%rsi), %r8
		testq	%r8, %r8
		jle	.L8
		leaq	(%rdi,%rsi,8), %rsi
		jmp	.L10
	.L12:
		movq	(%rax), %rdx
		movq	-8(%rax), %rcx
		cmpq	%rcx, %rdx
		jge	.L11
		movq	%rcx, (%rax)
		movq	%rdx, -8(%rax)
	.L11:
		addq	$8, %rax
		cmpq	%rsi, %rax
		jne	.L12
	.L13:
		subq	$8, %rsi
		subq	$1, %r8
		je	.L8
	.L10:
		testq	%r8, %r8
		jle	.L13
		leaq	8(%rdi), %rax
		jmp	.L12
	.L8:
		rep ret
		.cfi_endproc
	.LFE24:
		.size	bubble_p, .-bubble_p
		.section	.rodata.str1.1,"aMS",@progbits,1
	.LC0:
		.string	"array version"
	.LC1:
		.string	"  Before: "
	.LC2:
		.string	"0x%.4x "
	.LC3:
		.string	"  After:  "
	.LC4:
		.string	"pointer version"
		.text
		.globl	main
		.type	main, @function
        ret                   # and ends with a ret instruction


# Stack starts here and grows to lower addresses
	.pos 0x200
stack: