	.file	"daxpy.c"
	.text
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC0:
	.string	"Modo ejecuci\303\263n: <programa> <dimensi\303\263n> <constante>"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC4:
	.string	"Tiempo: %f\n"
.LC5:
	.string	"r[%d] = %f "
.LC6:
	.string	"r[0]=%f -- r[%d] = %f\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB52:
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
	jle	.L26
	movq	8(%rsi), %rdi
	movl	$10, %edx
	movq	%rsi, %rbx
	xorl	%esi, %esi
	call	strtol@PLT
	movq	16(%rbx), %rdi
	xorl	%esi, %esi
	movl	%eax, N(%rip)
	call	strtod@PLT
	movl	N(%rip), %ebp
	movsd	%xmm0, a(%rip)
	movq	%rbp, %r12
	salq	$3, %rbp
	movq	%rbp, %rdi
	call	malloc@PLT
	movq	%rbp, %rdi
	movq	%rax, %rbx
	movq	%rax, x(%rip)
	call	malloc@PLT
	testl	%r12d, %r12d
	movq	%rax, y(%rip)
	je	.L3
	leal	-1(%r12), %edx
	movsd	.LC1(%rip), %xmm1
	movsd	.LC2(%rip), %xmm0
	leaq	8(,%rdx,8), %rcx
	xorl	%edx, %edx
	.p2align 4,,10
	.p2align 3
.L4:
	movsd	%xmm1, (%rbx,%rdx)
	movsd	%xmm0, (%rax,%rdx)
	addq	$8, %rdx
	cmpq	%rdx, %rcx
	jne	.L4
.L3:
	xorl	%edi, %edi
	movq	%rsp, %rsi
	call	clock_gettime@PLT
	movl	N(%rip), %eax
	testl	%eax, %eax
	je	.L5
	movq	x(%rip), %rsi
	movq	y(%rip), %rdx
	subl	$1, %eax
	leaq	8(,%rax,8), %rcx
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L6:
	movsd	(%rsi,%rax), %xmm0
	mulsd	a(%rip), %xmm0
	addsd	(%rdx,%rax), %xmm0
	movsd	%xmm0, (%rdx,%rax)
	addq	$8, %rax
	cmpq	%rax, %rcx
	jne	.L6
.L5:
	leaq	16(%rsp), %rsi
	xorl	%edi, %edi
	call	clock_gettime@PLT
	movq	24(%rsp), %rax
	subq	8(%rsp), %rax
	leaq	.LC4(%rip), %rsi
	pxor	%xmm0, %xmm0
	movl	$1, %edi
	pxor	%xmm1, %xmm1
	cvtsi2sdq	%rax, %xmm0
	movq	16(%rsp), %rax
	subq	(%rsp), %rax
	cvtsi2sdq	%rax, %xmm1
	movl	$1, %eax
	divsd	.LC3(%rip), %xmm0
	addsd	%xmm1, %xmm0
	call	__printf_chk@PLT
	movl	N(%rip), %edx
	cmpl	$5, %edx
	ja	.L7
	testl	%edx, %edx
	je	.L8
	leaq	.LC5(%rip), %r12
	xorl	%ebp, %ebp
	xorl	%ebx, %ebx
	.p2align 4,,10
	.p2align 3
.L9:
	movq	y(%rip), %rax
	movl	%ebx, %edx
	movq	%r12, %rsi
	movl	$1, %edi
	addl	$1, %ebx
	movsd	(%rax,%rbp), %xmm0
	movl	$1, %eax
	addq	$8, %rbp
	call	__printf_chk@PLT
	cmpl	N(%rip), %ebx
	jb	.L9
.L8:
	movl	$10, %edi
	call	putchar@PLT
.L10:
	xorl	%eax, %eax
	movq	40(%rsp), %rcx
	xorq	%fs:40, %rcx
	jne	.L27
	addq	$48, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 32
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
.L7:
	.cfi_restore_state
	movq	y(%rip), %rax
	leal	-1(%rdx), %ecx
	leaq	.LC6(%rip), %rsi
	movl	$1, %edi
	movq	%rcx, %rdx
	movsd	(%rax,%rcx,8), %xmm1
	movsd	(%rax), %xmm0
	movl	$2, %eax
	call	__printf_chk@PLT
	jmp	.L10
.L26:
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	orl	$-1, %edi
	call	exit@PLT
.L27:
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE52:
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
