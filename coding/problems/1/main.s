	.file	"main.c"
	.section	.rodata
.LC0:
	.string	"Enter size of array: "
.LC1:
	.string	"%d"
.LC2:
	.string	"Insufficient memory"
.LC3:
	.string	"Enter array values in order: "
.LC4:
	.string	"Difference = %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movl	$0, -48(%rbp)
	movq	$0, -32(%rbp)
	movl	$0, -44(%rbp)
	movl	$0, -40(%rbp)
	movl	$0, -36(%rbp)
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	leaq	-48(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	-48(%rbp), %eax
	cltq
	salq	$3, %rax
	movq	%rax, %rdi
	call	malloc
	movq	%rax, -32(%rbp)
	cmpq	$0, -32(%rbp)
	jne	.L2
	movl	$.LC2, %edi
	call	puts
	movl	$1, %edi
	call	exit
.L2:
	movl	$0, -44(%rbp)
	jmp	.L3
.L5:
	movl	-44(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-32(%rbp), %rax
	leaq	(%rdx,%rax), %rbx
	movl	-48(%rbp), %eax
	cltq
	salq	$2, %rax
	movq	%rax, %rdi
	call	malloc
	movq	%rax, (%rbx)
	movq	(%rbx), %rax
	testq	%rax, %rax
	jne	.L4
	movl	$.LC2, %edi
	call	puts
	movl	$1, %edi
	call	exit
.L4:
	addl	$1, -44(%rbp)
.L3:
	movl	-48(%rbp), %eax
	cmpl	%eax, -44(%rbp)
	jl	.L5
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	movl	$0, -44(%rbp)
	jmp	.L6
.L9:
	movl	$0, -40(%rbp)
	jmp	.L7
.L8:
	movl	-44(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	-40(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rdx, %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	addl	$1, -40(%rbp)
.L7:
	movl	-48(%rbp), %eax
	cmpl	%eax, -40(%rbp)
	jl	.L8
	addl	$1, -44(%rbp)
.L6:
	movl	-48(%rbp), %eax
	cmpl	%eax, -44(%rbp)
	jl	.L9
	movl	$0, -44(%rbp)
	movl	-48(%rbp), %eax
	subl	$1, %eax
	movl	%eax, -40(%rbp)
	jmp	.L10
.L13:
	movl	-44(%rbp), %eax
	cmpl	-40(%rbp), %eax
	je	.L19
	movl	-44(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	-44(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-44(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rcx
	movq	-32(%rbp), %rax
	addq	%rcx, %rax
	movq	(%rax), %rax
	movl	-40(%rbp), %ecx
	movslq	%ecx, %rcx
	salq	$2, %rcx
	addq	%rcx, %rax
	movl	(%rax), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	addl	%eax, -36(%rbp)
	jmp	.L12
.L19:
	nop
.L12:
	addl	$1, -44(%rbp)
	subl	$1, -40(%rbp)
.L10:
	cmpl	$0, -40(%rbp)
	jns	.L13
	cmpl	$0, -36(%rbp)
	jns	.L14
	negl	-36(%rbp)
.L14:
	movl	-36(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
	movl	$0, -44(%rbp)
	jmp	.L15
.L16:
	movl	-44(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	free
	addl	$1, -44(%rbp)
.L15:
	movl	-48(%rbp), %eax
	cmpl	%eax, -44(%rbp)
	jl	.L16
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	free
	movl	$0, %eax
	movq	-24(%rbp), %rsi
	xorq	%fs:40, %rsi
	je	.L18
	call	__stack_chk_fail
.L18:
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.12) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
