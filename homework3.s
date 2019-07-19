	.file	"homework3.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%8d   "
	.text
	.globl	print_matrix
	.type	print_matrix, @function
print_matrix:
.LFB23:
	.cfi_startproc
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	subq	$8, %rsp
	.cfi_def_cfa_offset 48
	movq	%rdi, %r12
	leaq	128(%rdi), %r13
	jmp	.L2
.L3:
	movq	0(%rbp,%rbx,8), %rdx
	movl	$.LC0, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk
	addq	$1, %rbx
	cmpq	$4, %rbx
	jne	.L3
	movl	$10, %edi
	call	putchar
	addq	$32, %r12
	cmpq	%r12, %r13
	je	.L1
.L2:
	movq	%r12, %rbp
	movl	$0, %ebx
	jmp	.L3
.L1:
	addq	$8, %rsp
	.cfi_def_cfa_offset 40
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE23:
	.size	print_matrix, .-print_matrix
	.globl	transpose
	.type	transpose, @function
transpose:
.LFB24:
	.cfi_startproc
	leaq	8(%rdi), %r10
	addq	$32, %rdi
	movl	$0, %ecx
	jmp	.L8
.L9:
	movq	(%rsi,%rax,8), %r8
	movq	(%rdx), %r9
	movq	%r9, (%rsi,%rax,8)
	movq	%r8, (%rdx)
	addq	$1, %rax
	addq	$32, %rdx
	cmpq	%rcx, %rax
	jl	.L9
.L11:
	addq	$8, %r10
	addq	$32, %rdi
.L8:
	addq	$1, %rcx
	cmpq	$4, %rcx
	je	.L7
	testq	%rcx, %rcx
	jle	.L11
	movq	%rdi, %rsi
	movq	%r10, %rdx
	movl	$0, %eax
	jmp	.L9
.L7:
	rep ret
	.cfi_endproc
.LFE24:
	.size	transpose, .-transpose
	.globl	transpose_optimized
	.type	transpose_optimized, @function
transpose_optimized:
.LFB25:
	.cfi_startproc
	leaq	32(%rdi), %r10
	leaq	8(%rdi), %r9
	addq	$40, %rdi
	movl	$0, %r8d
	jmp	.L14
.L18:
	movq	%r9, %rdx
	movq	%r10, %rax
.L15:
	movq	(%rax), %rcx
	movq	(%rdx), %rsi
	movq	%rsi, (%rax)
	movq	%rcx, (%rdx)
	addq	$8, %rax
	addq	$32, %rdx
	cmpq	%rax, %rdi
	jne	.L15
.L17:
	addq	$32, %r10
	addq	$8, %r9
	addq	$40, %rdi
.L14:
	addq	$1, %r8
	cmpq	$4, %r8
	je	.L13
	testq	%r8, %r8
	jg	.L18
	jmp	.L17
.L13:
	rep ret
	.cfi_endproc
.LFE25:
	.size	transpose_optimized, .-transpose_optimized
	.globl	main
	.type	main, @function
main:
.LFB26:
	.cfi_startproc
	subq	$152, %rsp
	.cfi_def_cfa_offset 160
	movq	%fs:40, %rax
	movq	%rax, 136(%rsp)
	xorl	%eax, %eax
	movq	$1, (%rsp)
	movq	$2, 8(%rsp)
	movq	$3, 16(%rsp)
	movq	$4, 24(%rsp)
	movq	$1, 32(%rsp)
	movq	$2, 40(%rsp)
	movq	$3, 48(%rsp)
	movq	$4, 56(%rsp)
	movq	$1, 64(%rsp)
	movq	$2, 72(%rsp)
	movq	$3, 80(%rsp)
	movq	$4, 88(%rsp)
	movq	$1, 96(%rsp)
	movq	$2, 104(%rsp)
	movq	$3, 112(%rsp)
	movq	$4, 120(%rsp)
	movq	%rsp, %rdi
	call	print_matrix
	movl	$10, %edi
	call	putchar
	movq	%rsp, %rdi
	call	transpose_optimized
	movq	%rsp, %rdi
	call	print_matrix
	movq	136(%rsp), %rdx
	xorq	%fs:40, %rdx
	je	.L21
	call	__stack_chk_fail
.L21:
	movl	$0, %eax
	addq	$152, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE26:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
