	.file	"producto_secuencial.c"
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
	jle	.L42
	movq	8(%rsi), %rdi
	movl	$10, %edx
	xorl	%esi, %esi
	call	strtol@PLT
	movq	%rax, %rbx
	movq	%rax, 16(%rsp)
	movl	%eax, 40(%rsp)
	call	getpid@PLT
	movl	%eax, %edi
	call	srand@PLT
	testl	%ebx, %ebx
	jle	.L3
	movl	%ebx, %eax
	leaq	a(%rip), %r14
	leaq	b(%rip), %rbp
	subl	$1, %eax
	xorl	%r13d, %r13d
	leaq	1(%rax), %r15
	movl	%eax, 44(%rsp)
	movq	%rax, 24(%rsp)
	leaq	8(,%rax,8), %rax
	imulq	$80000, %r15, %rbx
	movq	%r15, 32(%rsp)
	movq	%rax, 8(%rsp)
	movq	%rbx, (%rsp)
	movl	$1717986919, %ebx
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
	imull	%ebx
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
	imull	%ebx
	movl	%ecx, %eax
	sarl	$31, %eax
	sarl	$2, %edx
	subl	%eax, %edx
	leal	(%rdx,%rdx,4), %eax
	addl	%eax, %eax
	subl	%eax, %ecx
	cvtsi2sd	%ecx, %xmm0
	movsd	%xmm0, 0(%rbp,%r15)
	addq	$8, %r15
	cmpq	%r12, %r15
	jne	.L5
	addq	$80000, %r13
	cmpq	(%rsp), %r13
	jne	.L4
	leaq	48(%rsp), %rsi
	xorl	%edi, %edi
	movq	32(%rsp), %r15
	leaq	a(%rip), %r14
	leaq	res(%rip), %r13
	call	clock_gettime@PLT
	imulq	$80000, 24(%rsp), %r10
	leaq	80000(%r14), %rax
	leaq	0(,%r15,8), %r9
	movq	%r14, %rcx
	movq	%r14, 8(%rsp)
	movq	%r13, %rdi
	addq	%rax, %r10
	.p2align 4,,10
	.p2align 3
.L21:
	xorl	%esi, %esi
	.p2align 4,,10
	.p2align 3
.L10:
	movsd	(%rdi,%rsi), %xmm1
	leaq	b(%rip), %r12
	leaq	0(%rbp,%rsi), %rdx
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L7:
	movsd	(%rcx,%rax,8), %xmm0
	addq	$1, %rax
	addq	$80000, %rdx
	mulsd	-80000(%rdx), %xmm0
	cmpq	%r15, %rax
	addsd	%xmm0, %xmm1
	jne	.L7
	movsd	%xmm1, (%rdi,%rsi)
	addq	$8, %rsi
	cmpq	%r9, %rsi
	jne	.L10
	addq	$80000, %rcx
	addq	$80000, %rdi
	cmpq	%r10, %rcx
	jne	.L21
	leaq	64(%rsp), %rsi
	xorl	%edi, %edi
	xorl	%ebx, %ebx
	leaq	.LC1(%rip), %r15
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
	jg	.L43
	movl	40(%rsp), %ebp
	movq	%r12, 8(%rsp)
	.p2align 4,,10
	.p2align 3
.L12:
	xorl	%r12d, %r12d
.L11:
	movsd	(%r14,%r12,8), %xmm0
	movl	%r12d, %ecx
	movl	%ebx, %edx
	movq	%r15, %rsi
	movl	$1, %edi
	movl	$1, %eax
	addq	$1, %r12
	call	__printf_chk@PLT
	cmpl	%r12d, %ebp
	jg	.L11
	movl	$10, %edi
	addl	$1, %ebx
	addq	$80000, %r14
	call	putchar@PLT
	cmpl	%ebp, %ebx
	jne	.L12
	leaq	.LC2(%rip), %r15
	movl	$10, %edi
	xorl	%r14d, %r14d
	movq	8(%rsp), %r12
	call	putchar@PLT
	.p2align 4,,10
	.p2align 3
.L15:
	xorl	%ebp, %ebp
.L14:
	movsd	(%r12,%rbp,8), %xmm0
	movl	%ebp, %ecx
	movl	%r14d, %edx
	movq	%r15, %rsi
	movl	$1, %edi
	movl	$1, %eax
	addq	$1, %rbp
	call	__printf_chk@PLT
	cmpl	%ebp, %ebx
	jg	.L14
	movl	$10, %edi
	addl	$1, %r14d
	addq	$80000, %r12
	call	putchar@PLT
	cmpl	%ebx, %r14d
	jl	.L15
	leaq	.LC3(%rip), %r14
	movl	$10, %edi
	xorl	%r12d, %r12d
	call	putchar@PLT
	.p2align 4,,10
	.p2align 3
.L18:
	xorl	%ebp, %ebp
.L17:
	movsd	0(%r13,%rbp,8), %xmm0
	movl	%ebp, %ecx
	movl	%r12d, %edx
	movq	%r14, %rsi
	movl	$1, %edi
	movl	$1, %eax
	addq	$1, %rbp
	call	__printf_chk@PLT
	cmpl	%ebp, %ebx
	jg	.L17
	movl	$10, %edi
	addl	$1, %r12d
	addq	$80000, %r13
	call	putchar@PLT
	cmpl	%ebx, %r12d
	jl	.L18
.L20:
	movl	$10, %edi
	call	putchar@PLT
.L40:
	movsd	(%rsp), %xmm0
	leaq	.LC4(%rip), %rsi
	movl	$1, %edi
	movl	$1, %eax
	call	__printf_chk@PLT
	xorl	%eax, %eax
	movq	88(%rsp), %rbx
	xorq	%fs:40, %rbx
	jne	.L44
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
.L43:
	.cfi_restore_state
	movl	44(%rsp), %r14d
	movq	8(%rsp), %rdi
	leaq	.LC5(%rip), %rsi
	movsd	a(%rip), %xmm0
	movl	$2, %eax
	movslq	%r14d, %rbx
	movl	%r14d, %ecx
	movl	%r14d, %edx
	imulq	$80008, %rbx, %rbx
	movsd	(%rdi,%rbx), %xmm1
	movl	$1, %edi
	call	__printf_chk@PLT
	movsd	0(%rbp,%rbx), %xmm1
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
	movsd	(%rax,%rbx), %xmm1
	movl	$1, %edi
	movl	$2, %eax
	call	__printf_chk@PLT
	jmp	.L40
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
	jmp	.L20
.L44:
	call	__stack_chk_fail@PLT
.L42:
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
