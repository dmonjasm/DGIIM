	.file	"daxpy.c"
	.text
	.comm	N,4,4
	.comm	x,8,8
	.comm	y,8,8
	.comm	a,8,8
	.section	.rodata
	.align 8
.LC0:
	.string	"Modo ejecuci\303\263n: <programa> <dimensi\303\263n> <constante>"
.LC4:
	.string	"Tiempo: %f\n"
.LC5:
	.string	"r[%d] = %f "
.LC6:
	.string	"r[0]=%f -- r[%d] = %f\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$96, %rsp
	movl	%edi, -68(%rbp)
	movq	%rsi, -80(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	cmpl	$2, -68(%rbp)
	jg	.L2
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	movl	$-1, %edi
	call	exit@PLT
.L2:
	movq	-80(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	atoi@PLT
	movl	%eax, N(%rip)
	movq	-80(%rbp), %rax
	addq	$16, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	atof@PLT
	movq	%xmm0, %rax
	movq	%rax, a(%rip)
	movl	N(%rip), %eax
	movl	%eax, %eax
	salq	$3, %rax
	movq	%rax, %rdi
	call	malloc@PLT
	movq	%rax, x(%rip)
	movl	N(%rip), %eax
	movl	%eax, %eax
	salq	$3, %rax
	movq	%rax, %rdi
	call	malloc@PLT
	movq	%rax, y(%rip)
	movl	$0, -60(%rbp)
	jmp	.L3
.L4:
	movq	x(%rip), %rax
	movl	-60(%rbp), %edx
	movslq	%edx, %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movsd	.LC1(%rip), %xmm0
	movsd	%xmm0, (%rax)
	movq	y(%rip), %rax
	movl	-60(%rbp), %edx
	movslq	%edx, %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movsd	.LC2(%rip), %xmm0
	movsd	%xmm0, (%rax)
	addl	$1, -60(%rbp)
.L3:
	movl	-60(%rbp), %edx
	movl	N(%rip), %eax
	cmpl	%eax, %edx
	jb	.L4
	leaq	-48(%rbp), %rax
	movq	%rax, %rsi
	movl	$0, %edi
	call	clock_gettime@PLT
	movl	$0, -60(%rbp)
	jmp	.L5
.L6:
	movq	x(%rip), %rax
	movl	-60(%rbp), %edx
	movslq	%edx, %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movsd	(%rax), %xmm1
	movsd	a(%rip), %xmm0
	mulsd	%xmm1, %xmm0
	movq	y(%rip), %rax
	movl	-60(%rbp), %edx
	movslq	%edx, %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movsd	(%rax), %xmm1
	movq	y(%rip), %rax
	movl	-60(%rbp), %edx
	movslq	%edx, %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	addsd	%xmm1, %xmm0
	movsd	%xmm0, (%rax)
	addl	$1, -60(%rbp)
.L5:
	movl	-60(%rbp), %edx
	movl	N(%rip), %eax
	cmpl	%eax, %edx
	jb	.L6
	leaq	-32(%rbp), %rax
	movq	%rax, %rsi
	movl	$0, %edi
	call	clock_gettime@PLT
	movq	-32(%rbp), %rdx
	movq	-48(%rbp), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	cvtsi2sdq	%rax, %xmm1
	movq	-24(%rbp), %rdx
	movq	-40(%rbp), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	cvtsi2sdq	%rax, %xmm0
	movsd	.LC3(%rip), %xmm2
	divsd	%xmm2, %xmm0
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -56(%rbp)
	movq	-56(%rbp), %rax
	movq	%rax, -88(%rbp)
	movsd	-88(%rbp), %xmm0
	leaq	.LC4(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movl	N(%rip), %eax
	cmpl	$5, %eax
	ja	.L7
	movl	$0, -60(%rbp)
	jmp	.L8
.L9:
	movq	y(%rip), %rax
	movl	-60(%rbp), %edx
	movslq	%edx, %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	(%rax), %rdx
	movl	-60(%rbp), %eax
	movq	%rdx, -88(%rbp)
	movsd	-88(%rbp), %xmm0
	movl	%eax, %esi
	leaq	.LC5(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	addl	$1, -60(%rbp)
.L8:
	movl	-60(%rbp), %edx
	movl	N(%rip), %eax
	cmpl	%eax, %edx
	jb	.L9
	movl	$10, %edi
	call	putchar@PLT
	jmp	.L10
.L7:
	movq	y(%rip), %rax
	movl	N(%rip), %edx
	subl	$1, %edx
	movl	%edx, %edx
	salq	$3, %rdx
	addq	%rdx, %rax
	movsd	(%rax), %xmm0
	movl	N(%rip), %eax
	leal	-1(%rax), %edx
	movq	y(%rip), %rax
	movq	(%rax), %rax
	movapd	%xmm0, %xmm1
	movl	%edx, %esi
	movq	%rax, -88(%rbp)
	movsd	-88(%rbp), %xmm0
	leaq	.LC6(%rip), %rdi
	movl	$2, %eax
	call	printf@PLT
.L10:
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L12
	call	__stack_chk_fail@PLT
.L12:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC1:
	.long	0
	.long	1072693248
	.align 8
.LC2:
	.long	0
	.long	1074790400
	.align 8
.LC3:
	.long	0
	.long	1104006501
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
