	.file	"producto_secuencial_modificado_2.c"
	.text
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC0:
	.string	"Modo ejercuci\303\263n: <programa> <filas/columnas> "
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC1:
	.string	"a[%d][%d]=%f "
.LC2:
	.string	"b[%d][%d]=%f "
.LC3:
	.string	"res[%d][%d]=%f "
.LC4:
	.string	"Tiempo: %f\n"
.LC5:
	.string	"a[0][0]=%f -- a[%d][%d]=%f\n"
.LC6:
	.string	"b[0][0]=%f -- b[%d][%d]=%f\n"
	.section	.rodata.str1.8
	.align 8
.LC7:
	.string	"res[0][0]=%f -- res[%d][%d]=%f\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB52:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$104, %rsp
	.cfi_def_cfa_offset 160
	movq	%fs:40, %rax
	movq	%rax, 88(%rsp)
	xorl	%eax, %eax
	cmpl	$1, %edi
	jle	.L46
	movq	8(%rsi), %rdi
	movl	$10, %edx
	xorl	%esi, %esi
	call	strtol@PLT
	movq	%rax, %rbx
	movq	%rax, 16(%rsp)
	movl	%eax, %r15d
	call	getpid@PLT
	movl	%eax, %edi
	call	srand@PLT
	testl	%ebx, %ebx
	jle	.L3
	movl	%ebx, %eax
	leaq	a(%rip), %r14
	xorl	%r13d, %r13d
	subl	$1, %eax
	movl	$1717986919, %ebp
	movl	%r15d, 40(%rsp)
	leaq	1(%rax), %rbx
	movl	%eax, 44(%rsp)
	movq	%rax, 24(%rsp)
	leaq	8(,%rax,8), %rax
	movq	%rbx, 32(%rsp)
	imulq	$80000, %rbx, %rbx
	movq	%rax, 8(%rsp)
	movq	%rbx, (%rsp)
	leaq	b(%rip), %rbx
	.p2align 4,,10
	.p2align 3
.L4:
	movq	8(%rsp), %rax
	movq	%r13, %r15
	leaq	(%rax,%r13), %r12
	.p2align 4,,10
	.p2align 3
.L5:
	call	rand@PLT
	movl	%eax, %ecx
	pxor	%xmm0, %xmm0
	imull	%ebp
	movl	%ecx, %eax
	sarl	$31, %eax
	sarl	$2, %edx
	subl	%eax, %edx
	leal	(%rdx,%rdx,4), %eax
	addl	%eax, %eax
	subl	%eax, %ecx
	cvtsi2sd	%ecx, %xmm0
	movsd	%xmm0, (%r14,%r15)
	call	rand@PLT
	movl	%eax, %ecx
	pxor	%xmm0, %xmm0
	imull	%ebp
	movl	%ecx, %eax
	sarl	$31, %eax
	sarl	$2, %edx
	subl	%eax, %edx
	leal	(%rdx,%rdx,4), %eax
	addl	%eax, %eax
	subl	%eax, %ecx
	cvtsi2sd	%ecx, %xmm0
	movsd	%xmm0, (%rbx,%r15)
	addq	$8, %r15
	cmpq	%r12, %r15
	jne	.L5
	addq	$80000, %r13
	cmpq	(%rsp), %r13
	jne	.L4
	leaq	48(%rsp), %rsi
	xorl	%edi, %edi
	movl	40(%rsp), %r15d
	leaq	res(%rip), %r12
	leaq	a(%rip), %r13
	call	clock_gettime@PLT
	imulq	$80000, 24(%rsp), %r11
	movq	32(%rsp), %rbp
	leaq	80000(%r12), %rax
	movq	%r13, %r10
	movq	%r13, 8(%rsp)
	movq	%r12, %r9
	salq	$3, %rbp
	addq	%rax, %r11
	.p2align 4,,10
	.p2align 3
.L24:
	xorl	%edi, %edi
	.p2align 4,,10
	.p2align 3
.L14:
	movsd	(%r9,%rdi), %xmm0
	leaq	b(%rip), %r14
	leaq	(%rbx,%rdi), %rcx
	movq	%r10, %rdx
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L11:
	movsd	(%rdx), %xmm1
	leal	1(%rax), %esi
	mulsd	(%rcx), %xmm1
	cmpl	%r15d, %esi
	addsd	%xmm1, %xmm0
	jge	.L7
	movsd	8(%rdx), %xmm1
	mulsd	80000(%rcx), %xmm1
	addsd	%xmm1, %xmm0
.L7:
	leal	2(%rax), %esi
	cmpl	%esi, %r15d
	jle	.L8
	movsd	16(%rdx), %xmm1
	mulsd	160000(%rcx), %xmm1
	addsd	%xmm1, %xmm0
.L8:
	leal	3(%rax), %esi
	cmpl	%esi, %r15d
	jle	.L9
	movsd	32(%rdx), %xmm1
	mulsd	240000(%rcx), %xmm1
	addsd	%xmm1, %xmm0
.L9:
	leal	4(%rax), %esi
	cmpl	%esi, %r15d
	jle	.L10
	movsd	32(%rdx), %xmm1
	mulsd	240000(%rcx), %xmm1
	addsd	%xmm1, %xmm0
.L10:
	addl	$5, %eax
	addq	$40, %rdx
	addq	$400000, %rcx
	cmpl	%r15d, %eax
	jl	.L11
	movsd	%xmm0, (%r9,%rdi)
	addq	$8, %rdi
	cmpq	%rbp, %rdi
	jne	.L14
	addq	$80000, %r9
	addq	$80000, %r10
	cmpq	%r11, %r9
	jne	.L24
	leaq	64(%rsp), %rsi
	xorl	%edi, %edi
	xorl	%ebp, %ebp
	call	clock_gettime@PLT
	movq	72(%rsp), %rax
	subq	56(%rsp), %rax
	pxor	%xmm0, %xmm0
	pxor	%xmm1, %xmm1
	cvtsi2sdq	%rax, %xmm0
	movq	64(%rsp), %rax
	subq	48(%rsp), %rax
	cmpl	$5, 16(%rsp)
	cvtsi2sdq	%rax, %xmm1
	divsd	.LC8(%rip), %xmm0
	addsd	%xmm1, %xmm0
	movsd	%xmm0, (%rsp)
	jg	.L47
	.p2align 4,,10
	.p2align 3
.L16:
	xorl	%ebx, %ebx
.L15:
	movsd	0(%r13,%rbx,8), %xmm0
	leaq	.LC1(%rip), %rsi
	movl	%ebx, %ecx
	movl	%ebp, %edx
	movl	$1, %edi
	movl	$1, %eax
	addq	$1, %rbx
	call	__printf_chk@PLT
	cmpl	%ebx, %r15d
	jg	.L15
	movl	$10, %edi
	addl	$1, %ebp
	addq	$80000, %r13
	call	putchar@PLT
	cmpl	%r15d, %ebp
	jne	.L16
	leaq	.LC2(%rip), %r15
	movl	$10, %edi
	xorl	%r13d, %r13d
	call	putchar@PLT
	.p2align 4,,10
	.p2align 3
.L19:
	xorl	%ebx, %ebx
.L18:
	movsd	(%r14,%rbx,8), %xmm0
	movl	%ebx, %ecx
	movl	%r13d, %edx
	movq	%r15, %rsi
	movl	$1, %edi
	movl	$1, %eax
	addq	$1, %rbx
	call	__printf_chk@PLT
	cmpl	%ebx, %ebp
	jg	.L18
	movl	$10, %edi
	addl	$1, %r13d
	addq	$80000, %r14
	call	putchar@PLT
	cmpl	%ebp, %r13d
	jl	.L19
	leaq	.LC3(%rip), %r14
	movl	$10, %edi
	xorl	%r13d, %r13d
	call	putchar@PLT
	.p2align 4,,10
	.p2align 3
.L22:
	xorl	%ebx, %ebx
.L21:
	movsd	(%r12,%rbx,8), %xmm0
	movl	%ebx, %ecx
	movl	%r13d, %edx
	movq	%r14, %rsi
	movl	$1, %edi
	movl	$1, %eax
	addq	$1, %rbx
	call	__printf_chk@PLT
	cmpl	%ebx, %ebp
	jg	.L21
	movl	$10, %edi
	addl	$1, %r13d
	addq	$80000, %r12
	call	putchar@PLT
	cmpl	%ebp, %r13d
	jl	.L22
.L25:
	movl	$10, %edi
	call	putchar@PLT
.L44:
	movsd	(%rsp), %xmm0
	leaq	.LC4(%rip), %rsi
	movl	$1, %edi
	movl	$1, %eax
	call	__printf_chk@PLT
	xorl	%eax, %eax
	movq	88(%rsp), %rbx
	xorq	%fs:40, %rbx
	jne	.L48
	addq	$104, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
.L47:
	.cfi_restore_state
	movl	44(%rsp), %r14d
	movq	8(%rsp), %rdi
	leaq	.LC5(%rip), %rsi
	movsd	a(%rip), %xmm0
	movl	$2, %eax
	movslq	%r14d, %rbp
	movl	%r14d, %ecx
	movl	%r14d, %edx
	imulq	$80008, %rbp, %rbp
	movsd	(%rdi,%rbp), %xmm1
	movl	$1, %edi
	call	__printf_chk@PLT
	movsd	(%rbx,%rbp), %xmm1
	leaq	.LC6(%rip), %rsi
	movsd	b(%rip), %xmm0
	movl	%r14d, %ecx
	movl	%r14d, %edx
	movl	$1, %edi
	movl	$2, %eax
	call	__printf_chk@PLT
	leaq	res(%rip), %rax
	movsd	res(%rip), %xmm0
	leaq	.LC7(%rip), %rsi
	movl	%r14d, %ecx
	movl	%r14d, %edx
	movsd	(%rax,%rbp), %xmm1
	movl	$1, %edi
	movl	$2, %eax
	call	__printf_chk@PLT
	jmp	.L44
.L3:
	leaq	48(%rsp), %rsi
	xorl	%edi, %edi
	call	clock_gettime@PLT
	leaq	64(%rsp), %rsi
	xorl	%edi, %edi
	call	clock_gettime@PLT
	movq	72(%rsp), %rax
	subq	56(%rsp), %rax
	movl	$10, %edi
	pxor	%xmm0, %xmm0
	pxor	%xmm1, %xmm1
	cvtsi2sdq	%rax, %xmm0
	movq	64(%rsp), %rax
	subq	48(%rsp), %rax
	cvtsi2sdq	%rax, %xmm1
	divsd	.LC8(%rip), %xmm0
	addsd	%xmm1, %xmm0
	movsd	%xmm0, (%rsp)
	call	putchar@PLT
	movl	$10, %edi
	call	putchar@PLT
	jmp	.L25
.L48:
	call	__stack_chk_fail@PLT
.L46:
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	orl	$-1, %edi
	call	exit@PLT
	.cfi_endproc
.LFE52:
	.size	main, .-main
	.comm	res,800000000,32
	.comm	b,800000000,32
	.comm	a,800000000,32
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC8:
	.long	0
	.long	1104006501
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
