	.file	"daxpy.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"Modo ejecuci\303\263n: <programa> <dimensi\303\263n> <constante>"
.LC4:
	.string	"Tiempo: %f\n"
.LC5:
	.string	"r[%d] = %f "
.LC6:
	.string	"r[0]=%f -- r[%d] = %f\n"
	.section	.text.startup,"ax",@progbits
	.globl	main
	.type	main, @function
main:
.LFB34:
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
	subq	$48, %rsp
	.cfi_def_cfa_offset 80
	movq	%fs:40, %rax
	movq	%rax, 40(%rsp)
	xorl	%eax, %eax
	cmpl	$2, %edi
	jg	.L2
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	orl	$-1, %edi
	call	exit@PLT
.L2:
	movq	8(%rsi), %rdi
	movq	%rsi, %rbx
	call	atoi@PLT
	movq	16(%rbx), %rdi
	movl	%eax, %ebp
	movl	%eax, N(%rip)
	movl	%ebp, %ebx
	salq	$3, %rbx
	call	atof@PLT
	movq	%rbx, %rdi
	movsd	%xmm0, a(%rip)
	call	malloc@PLT
	movq	%rbx, %rdi
	movq	%rax, %r12
	movq	%rax, x(%rip)
	call	malloc@PLT
	movsd	.LC1(%rip), %xmm0
	movq	%rax, y(%rip)
	movsd	.LC2(%rip), %xmm1
	xorl	%edx, %edx
.L3:
	cmpl	%edx, %ebp
	jbe	.L17
	movsd	%xmm0, (%r12,%rdx,8)
	movsd	%xmm1, (%rax,%rdx,8)
	incq	%rdx
	jmp	.L3
.L17:
	leaq	8(%rsp), %rsi
	xorl	%edi, %edi
	call	clock_gettime@PLT
	movl	N(%rip), %ecx
	movq	x(%rip), %rsi
	xorl	%eax, %eax
	movq	y(%rip), %rdx
.L5:
	cmpl	%eax, %ecx
	jbe	.L18
	movsd	(%rsi,%rax,8), %xmm0
	mulsd	a(%rip), %xmm0
	addsd	(%rdx,%rax,8), %xmm0
	movsd	%xmm0, (%rdx,%rax,8)
	incq	%rax
	jmp	.L5
.L18:
	leaq	24(%rsp), %rsi
	xorl	%edi, %edi
	xorl	%ebx, %ebx
	leaq	.LC5(%rip), %rbp
	call	clock_gettime@PLT
	movq	32(%rsp), %rax
	subq	16(%rsp), %rax
	leaq	.LC4(%rip), %rsi
	movl	$1, %edi
	cvtsi2sdq	%rax, %xmm0
	movq	24(%rsp), %rax
	subq	8(%rsp), %rax
	cvtsi2sdq	%rax, %xmm1
	movb	$1, %al
	divsd	.LC3(%rip), %xmm0
	addsd	%xmm1, %xmm0
	call	__printf_chk@PLT
	movl	N(%rip), %edx
	cmpl	$5, %edx
	ja	.L19
.L7:
	cmpl	%ebx, N(%rip)
	jbe	.L20
	movq	y(%rip), %rax
	movl	%ebx, %edx
	movq	%rbp, %rsi
	movl	$1, %edi
	movsd	(%rax,%rbx,8), %xmm0
	movb	$1, %al
	incq	%rbx
	call	__printf_chk@PLT
	jmp	.L7
.L20:
	movl	$10, %edi
	call	putchar@PLT
	jmp	.L10
.L19:
	movq	y(%rip), %rax
	leal	-1(%rdx), %ecx
	leaq	.LC6(%rip), %rsi
	movl	$1, %edi
	movq	%rcx, %rdx
	movsd	(%rax,%rcx,8), %xmm1
	movsd	(%rax), %xmm0
	movb	$2, %al
	call	__printf_chk@PLT
.L10:
	xorl	%eax, %eax
	movq	40(%rsp), %rcx
	xorq	%fs:40, %rcx
	je	.L11
	call	__stack_chk_fail@PLT
.L11:
	addq	$48, %rsp
	.cfi_def_cfa_offset 32
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE34:
	.size	main, .-main
	.comm	a,8,8
	.comm	y,8,8
	.comm	x,8,8
	.comm	N,4,4
	.section	.rodata.cst8,"aM",@progbits,8
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
