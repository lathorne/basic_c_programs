	.file	"homework5.c"
	.text
	.globl	bubble_a
	.type	bubble_a, @function
bubble_a:
.LFB23:
	.cfi_startproc
	leaq	-1(%rsi), %r8
	testq	%r8, %r8
	jle	.L1
	leaq	(%rdi,%rsi,8), %rsi
	jmp	.L3
.L5:
	movq	(%rax), %rdx
	movq	-8(%rax), %rcx
	cmpq	%rcx, %rdx
	jge	.L4
	movq	%rcx, (%rax)
	movq	%rdx, -8(%rax)
.L4:
	addq	$8, %rax
	cmpq	%rsi, %rax
	jne	.L5
.L6:
	subq	$8, %rsi
	subq	$1, %r8
	je	.L1
.L3:
	testq	%r8, %r8
	jle	.L6
	leaq	8(%rdi), %rax
	jmp	.L5
.L1:
	rep ret
	.cfi_endproc
.LFE23:
	.size	bubble_a, .-bubble_a
	.globl	bubble_p
	.type	bubble_p, @function
bubble_p:
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
main:
.LFB25:
	.cfi_startproc
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	movl	$.LC0, %edi
	call	puts
	movl	$.LC1, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk
	movl	$array1, %ebx
	movl	$array1+48, %r12d
	movq	%rbx, %rbp
.L16:
	movq	0(%rbp), %rdx
	movl	$.LC2, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk
	addq	$8, %rbp
	cmpq	%r12, %rbp
	jne	.L16
	movl	$10, %edi
	call	putchar
	movl	$6, %esi
	movl	$array1, %edi
	call	bubble_a
	movl	$.LC3, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk
.L17:
	movq	(%rbx), %rdx
	movl	$.LC2, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk
	addq	$8, %rbx
	cmpq	%rbx, %r12
	jne	.L17
	movl	$10, %edi
	call	putchar
	movl	$.LC4, %edi
	call	puts
	movl	$.LC1, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk
	movl	$array2, %ebx
	movl	$array2+48, %r12d
	movq	%rbx, %rbp
.L18:
	movq	0(%rbp), %rdx
	movl	$.LC2, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk
	addq	$8, %rbp
	cmpq	%rbp, %r12
	jne	.L18
	movl	$10, %edi
	call	putchar
	movl	$6, %esi
	movl	$array2, %edi
	call	bubble_p
	movl	$.LC3, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk
.L19:
	movq	(%rbx), %rdx
	movl	$.LC2, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk
	addq	$8, %rbx
	cmpq	%r12, %rbx
	jne	.L19
	movl	$10, %edi
	call	putchar
	movl	$0, %eax
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE25:
	.size	main, .-main
	.globl	array2
	.data
	.align 32
	.type	array2, @object
	.size	array2, 56
array2:
	.quad	56797
	.quad	61166
	.quad	48059
	.quad	43690
	.quad	65535
	.quad	52428
	.quad	257
	.globl	array1
	.align 32
	.type	array1, @object
	.size	array1, 56
array1:
	.quad	56797
	.quad	61166
	.quad	48059
	.quad	43690
	.quad	65535
	.quad	52428
	.quad	257
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
