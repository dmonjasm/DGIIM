	.file	"producto_secuencial_modificado_1.c"
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
	subq	$120, %rsp
	.cfi_def_cfa_offset 176
	movq	%fs:40, %rax
	movq	%rax, 104(%rsp)
	xorl	%eax, %eax
	cmpl	$1, %edi
	jle	.L52
	movq	8(%rsi), %rdi
	movl	$10, %edx
	xorl	%esi, %esi
	call	strtol@PLT
	movq	%rax, %rbx
	movl	%eax, 24(%rsp)
	call	getpid@PLT
	movl	%eax, %edi
	call	srand@PLT
	testl	%ebx, %ebx
	jle	.L3
	leal	-1(%rbx), %eax
	movl	%ebx, 48(%rsp)
	leaq	a(%rip), %rbp
	leaq	b(%rip), %r14
	xorl	%r12d, %r12d
	leaq	1(%rax), %rbx
	leaq	8(,%rax,8), %r13
	movl	%eax, 52(%rsp)
	movq	%rax, 32(%rsp)
	movq	%rbx, 40(%rsp)
	movq	%r13, 16(%rsp)
	imulq	$80000, %rbx, %rbx
	movq	%rbx, 8(%rsp)
	.p2align 4,,10
	.p2align 3
.L4:
	movq	16(%rsp), %rax
	movq	%r12, %r15
	leaq	(%rax,%r12), %rbx
	.p2align 4,,10
	.p2align 3
.L5:
	movl	$1717986919, %r13d
	call	rand@PLT
	movl	%eax, %ecx
	pxor	%xmm0, %xmm0
	imull	%r13d
	movl	%ecx, %eax
	sarl	$31, %eax
	sarl	$2, %edx
	subl	%eax, %edx
	leal	(%rdx,%rdx,4), %eax
	addl	%eax, %eax
	subl	%eax, %ecx
	cvtsi2sd	%ecx, %xmm0
	movsd	%xmm0, 0(%rbp,%r15)
	call	rand@PLT
	movl	%eax, %ecx
	pxor	%xmm0, %xmm0
	imull	%r13d
	movl	%ecx, %eax
	sarl	$31, %eax
	sarl	$2, %edx
	subl	%eax, %edx
	leal	(%rdx,%rdx,4), %eax
	addl	%eax, %eax
	subl	%eax, %ecx
	cvtsi2sd	%ecx, %xmm0
	movsd	%xmm0, (%r14,%r15)
	addq	$8, %r15
	cmpq	%rbx, %r15
	jne	.L5
	addq	$80000, %r12
	cmpq	8(%rsp), %r12
	jne	.L4
	leaq	64(%rsp), %rsi
	xorl	%edi, %edi
	xorl	%r15d, %r15d
	call	clock_gettime@PLT
	leaq	80000+b(%rip), %r9
	movl	24(%rsp), %r8d
	movl	48(%rsp), %r10d
	movl	$1, %edi
	leaq	-80000(%r9), %rax
	movq	%r9, 16(%rsp)
	movq	%rax, %rcx
	movq	%rax, 56(%rsp)
	movq	%rax, %r14
	.p2align 4,,10
	.p2align 3
.L9:
	cmpl	%r15d, %r8d
	jle	.L11
	movl	%r10d, %esi
	movq	%r9, %rdx
	movq	%rdi, %rax
	subl	%edi, %esi
	addq	%rdi, %rsi
	jmp	.L12
	.p2align 4,,10
	.p2align 3
.L8:
	cmpl	%eax, %r15d
	je	.L7
	movsd	(%rcx,%rax,8), %xmm0
	movsd	(%rdx), %xmm1
	movsd	%xmm1, (%rcx,%rax,8)
	movsd	%xmm0, (%rdx)
.L7:
	addq	$1, %rax
	addq	$80000, %rdx
.L12:
	cmpq	%rsi, %rax
	jne	.L8
.L11:
	addl	$1, %r15d
	addq	$1, %rdi
	addq	$80008, %r9
	addq	$80000, %rcx
	cmpl	%r8d, %r15d
	jne	.L9
	imulq	$80000, 32(%rsp), %rax
	leaq	a(%rip), %r13
	leaq	b(%rip), %rbx
	movq	40(%rsp), %rsi
	leaq	res(%rip), %r12
	leaq	80000(%r13), %r11
	movq	%r13, %rbp
	movq	%r13, %rcx
	salq	$3, %rsi
	movq	%r12, %r10
	leaq	80000(%rbx,%rax), %r9
	addq	%rax, %r11
	.p2align 4,,10
	.p2align 3
.L10:
	leaq	b(%rip), %rdx
	movq	%r10, %rdi
	.p2align 4,,10
	.p2align 3
.L16:
	movsd	(%rdi), %xmm1
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L13:
	movsd	(%rcx,%rax), %xmm0
	mulsd	(%rdx,%rax), %xmm0
	addq	$8, %rax
	cmpq	%rsi, %rax
	addsd	%xmm0, %xmm1
	jne	.L13
	addq	$80000, %rdx
	movsd	%xmm1, (%rdi)
	addq	$8, %rdi
	cmpq	%r9, %rdx
	jne	.L16
	addq	$80000, %rcx
	addq	$80000, %r10
	cmpq	%r11, %rcx
	jne	.L10
	leaq	80(%rsp), %rsi
	xorl	%edi, %edi
	xorl	%ebx, %ebx
	call	clock_gettime@PLT
	movq	88(%rsp), %rax
	subq	72(%rsp), %rax
	pxor	%xmm0, %xmm0
	pxor	%xmm1, %xmm1
	cvtsi2sdq	%rax, %xmm0
	movq	80(%rsp), %rax
	subq	64(%rsp), %rax
	cmpl	$5, %r15d
	cvtsi2sdq	%rax, %xmm1
	divsd	.LC8(%rip), %xmm0
	addsd	%xmm1, %xmm0
	movsd	%xmm0, 8(%rsp)
	jg	.L53
	movl	24(%rsp), %ebp
	movq	%r12, 24(%rsp)
	.p2align 4,,10
	.p2align 3
.L18:
	xorl	%r12d, %r12d
.L17:
	movsd	0(%r13,%r12,8), %xmm0
	leaq	.LC1(%rip), %rsi
	movl	%r12d, %ecx
	movl	%ebx, %edx
	movl	$1, %edi
	movl	$1, %eax
	addq	$1, %r12
	call	__printf_chk@PLT
	cmpl	%r12d, %r15d
	jg	.L17
	movl	$10, %edi
	addl	$1, %ebx
	addq	$80000, %r13
	call	putchar@PLT
	cmpl	%ebp, %ebx
	jne	.L18
	movq	24(%rsp), %r12
	movq	16(%rsp), %r9
	leaq	b(%rip), %rcx
	movl	48(%rsp), %r10d
	movl	$1, %r8d
	xorl	%esi, %esi
	.p2align 4,,10
	.p2align 3
.L19:
	cmpl	%esi, %ebx
	jle	.L23
	movl	%r10d, %edi
	movq	%r9, %rdx
	movq	%r8, %rax
	subl	%r8d, %edi
	addq	%r8, %rdi
	jmp	.L24
	.p2align 4,,10
	.p2align 3
.L21:
	cmpl	%eax, %esi
	je	.L20
	movsd	(%rcx,%rax,8), %xmm0
	movsd	(%rdx), %xmm1
	movsd	%xmm1, (%rcx,%rax,8)
	movsd	%xmm0, (%rdx)
.L20:
	addq	$1, %rax
	addq	$80000, %rdx
.L24:
	cmpq	%rdi, %rax
	jne	.L21
.L23:
	addl	$1, %esi
	addq	$1, %r8
	addq	$80008, %r9
	addq	$80000, %rcx
	cmpl	%ebx, %esi
	jl	.L19
	leaq	.LC2(%rip), %r15
	movl	$10, %edi
	xorl	%r13d, %r13d
	call	putchar@PLT
	.p2align 4,,10
	.p2align 3
.L26:
	xorl	%ebp, %ebp
.L25:
	movsd	(%r14,%rbp,8), %xmm0
	movl	%ebp, %ecx
	movl	%r13d, %edx
	movq	%r15, %rsi
	movl	$1, %edi
	movl	$1, %eax
	addq	$1, %rbp
	call	__printf_chk@PLT
	cmpl	%ebp, %ebx
	jg	.L25
	movl	$10, %edi
	addl	$1, %r13d
	addq	$80000, %r14
	call	putchar@PLT
	cmpl	%ebx, %r13d
	jl	.L26
	leaq	.LC3(%rip), %r14
	movl	$10, %edi
	xorl	%r13d, %r13d
	call	putchar@PLT
	.p2align 4,,10
	.p2align 3
.L29:
	xorl	%ebp, %ebp
.L28:
	movsd	(%r12,%rbp,8), %xmm0
	movl	%ebp, %ecx
	movl	%r13d, %edx
	movq	%r14, %rsi
	movl	$1, %edi
	movl	$1, %eax
	addq	$1, %rbp
	call	__printf_chk@PLT
	cmpl	%ebp, %ebx
	jg	.L28
	movl	$10, %edi
	addl	$1, %r13d
	addq	$80000, %r12
	call	putchar@PLT
	cmpl	%ebx, %r13d
	jl	.L29
.L31:
	movl	$10, %edi
	call	putchar@PLT
.L50:
	movsd	8(%rsp), %xmm0
	leaq	.LC4(%rip), %rsi
	movl	$1, %edi
	movl	$1, %eax
	call	__printf_chk@PLT
	xorl	%eax, %eax
	movq	104(%rsp), %rbx
	xorq	%fs:40, %rbx
	jne	.L54
	addq	$120, %rsp
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
.L53:
	.cfi_restore_state
	movl	52(%rsp), %r14d
	movsd	a(%rip), %xmm0
	leaq	.LC5(%rip), %rsi
	movl	$1, %edi
	movl	$2, %eax
	movslq	%r14d, %rbx
	movl	%r14d, %ecx
	movl	%r14d, %edx
	imulq	$80008, %rbx, %rbx
	movsd	0(%rbp,%rbx), %xmm1
	call	__printf_chk@PLT
	movq	56(%rsp), %rax
	movsd	b(%rip), %xmm0
	leaq	.LC6(%rip), %rsi
	movl	%r14d, %ecx
	movl	%r14d, %edx
	movl	$1, %edi
	movsd	(%rax,%rbx), %xmm1
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
	jmp	.L50
.L3:
	leaq	64(%rsp), %rsi
	xorl	%edi, %edi
	call	clock_gettime@PLT
	leaq	80(%rsp), %rsi
	xorl	%edi, %edi
	call	clock_gettime@PLT
	movq	88(%rsp), %rax
	subq	72(%rsp), %rax
	movl	$10, %edi
	pxor	%xmm0, %xmm0
	pxor	%xmm1, %xmm1
	cvtsi2sdq	%rax, %xmm0
	movq	80(%rsp), %rax
	subq	64(%rsp), %rax
	cvtsi2sdq	%rax, %xmm1
	divsd	.LC8(%rip), %xmm0
	addsd	%xmm1, %xmm0
	movsd	%xmm0, 8(%rsp)
	call	putchar@PLT
	movl	$10, %edi
	call	putchar@PLT
	jmp	.L31
.L54:
	call	__stack_chk_fail@PLT
.L52:
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
