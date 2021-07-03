	.file	"daxpy.c"
	.text
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC0:
	.string	"Modo ejecuci\303\263n: <programa> <dimensi\303\263n> <constante>"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC6:
	.string	"Tiempo: %f\n"
.LC7:
	.string	"r[%d] = %f "
.LC8:
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
	jle	.L46
	movq	8(%rsi), %rdi
	movl	$10, %edx
	movq	%rsi, %rbx
	xorl	%esi, %esi
	call	strtol@PLT
	movq	16(%rbx), %rdi
	xorl	%esi, %esi
	movl	%eax, N(%rip)
	call	strtod@PLT
	movl	N(%rip), %r12d
	movsd	%xmm0, a(%rip)
	movq	%r12, %rbp
	salq	$3, %r12
	movq	%r12, %rdi
	call	malloc@PLT
	movq	%r12, %rdi
	movq	%rax, %rbx
	movq	%rax, x(%rip)
	call	malloc@PLT
	testl	%ebp, %ebp
	movq	%rax, y(%rip)
	je	.L3
	movq	%rbx, %rsi
	leal	-1(%rbp), %edx
	shrq	$3, %rsi
	andl	$1, %esi
	cmpl	$6, %edx
	jbe	.L20
	xorl	%r10d, %r10d
	testl	%esi, %esi
	je	.L5
	movq	.LC1(%rip), %rdi
	movl	$1, %r10d
	movq	%rdi, (%rbx)
	movq	.LC2(%rip), %rdi
	movq	%rdi, (%rax)
.L5:
	movl	%ebp, %r9d
	movapd	.LC3(%rip), %xmm1
	subl	%esi, %r9d
	salq	$3, %rsi
	xorl	%edx, %edx
	movl	%r9d, %r8d
	movapd	.LC4(%rip), %xmm0
	leaq	(%rbx,%rsi), %rdi
	shrl	%r8d
	addq	%rax, %rsi
	xorl	%ecx, %ecx
	.p2align 4,,10
	.p2align 3
.L6:
	addl	$1, %ecx
	movaps	%xmm1, (%rdi,%rdx)
	movups	%xmm0, (%rsi,%rdx)
	addq	$16, %rdx
	cmpl	%ecx, %r8d
	ja	.L6
	movl	%r9d, %ecx
	andl	$-2, %ecx
	cmpl	%ecx, %r9d
	leal	(%rcx,%r10), %edx
	je	.L3
.L4:
	movsd	.LC1(%rip), %xmm1
	movslq	%edx, %rcx
	movsd	.LC2(%rip), %xmm0
	movsd	%xmm1, (%rbx,%rcx,8)
	movsd	%xmm0, (%rax,%rcx,8)
	leal	1(%rdx), %ecx
	cmpl	%ecx, %ebp
	jbe	.L3
	movslq	%ecx, %rcx
	movsd	%xmm1, (%rbx,%rcx,8)
	movsd	%xmm0, (%rax,%rcx,8)
	leal	2(%rdx), %ecx
	cmpl	%ecx, %ebp
	jbe	.L3
	movslq	%ecx, %rcx
	movsd	%xmm1, (%rbx,%rcx,8)
	movsd	%xmm0, (%rax,%rcx,8)
	leal	3(%rdx), %ecx
	cmpl	%ecx, %ebp
	jbe	.L3
	movslq	%ecx, %rcx
	movsd	%xmm1, (%rbx,%rcx,8)
	movsd	%xmm0, (%rax,%rcx,8)
	leal	4(%rdx), %ecx
	cmpl	%ecx, %ebp
	jbe	.L3
	movslq	%ecx, %rcx
	movsd	%xmm1, (%rbx,%rcx,8)
	movsd	%xmm0, (%rax,%rcx,8)
	leal	5(%rdx), %ecx
	cmpl	%ecx, %ebp
	jbe	.L3
	addl	$6, %edx
	movslq	%ecx, %rcx
	cmpl	%edx, %ebp
	movsd	%xmm1, (%rbx,%rcx,8)
	movsd	%xmm0, (%rax,%rcx,8)
	jbe	.L3
	movslq	%edx, %rdx
	movsd	%xmm1, (%rbx,%rdx,8)
	movsd	%xmm0, (%rax,%rdx,8)
.L3:
	xorl	%edi, %edi
	movq	%rsp, %rsi
	call	clock_gettime@PLT
	movl	N(%rip), %r9d
	testl	%r9d, %r9d
	je	.L8
	movq	y(%rip), %rsi
	movq	x(%rip), %r8
	leaq	16(%rsi), %rax
	leaq	16(%r8), %rdx
	cmpq	%rax, %r8
	setnb	%al
	cmpq	%rdx, %rsi
	setnb	%dl
	orl	%edx, %eax
	cmpl	$8, %r9d
	seta	%dl
	testb	%dl, %al
	je	.L9
	movl	%r9d, %eax
	leaq	(%rsi,%rax,8), %rdx
	leaq	a(%rip), %rax
	cmpq	%rax, %rdx
	setbe	%dl
	addq	$8, %rax
	cmpq	%rax, %rsi
	setnb	%al
	orb	%al, %dl
	je	.L9
	movq	%rsi, %rdx
	xorl	%edi, %edi
	shrq	$3, %rdx
	andl	$1, %edx
	je	.L10
	movsd	a(%rip), %xmm0
	movl	$1, %edi
	mulsd	(%r8), %xmm0
	addsd	(%rsi), %xmm0
	movsd	%xmm0, (%rsi)
.L10:
	movsd	a(%rip), %xmm1
	movl	%r9d, %ebx
	xorl	%eax, %eax
	subl	%edx, %ebx
	movl	%edx, %edx
	xorl	%ecx, %ecx
	unpcklpd	%xmm1, %xmm1
	salq	$3, %rdx
	movl	%ebx, %r11d
	leaq	(%r8,%rdx), %r10
	addq	%rsi, %rdx
	shrl	%r11d
	.p2align 4,,10
	.p2align 3
.L11:
	movupd	(%r10,%rax), %xmm0
	addl	$1, %ecx
	mulpd	%xmm1, %xmm0
	addpd	(%rdx,%rax), %xmm0
	movaps	%xmm0, (%rdx,%rax)
	addq	$16, %rax
	cmpl	%ecx, %r11d
	ja	.L11
	movl	%ebx, %eax
	andl	$-2, %eax
	addl	%eax, %edi
	cmpl	%eax, %ebx
	je	.L8
	movslq	%edi, %rdx
	addl	$1, %edi
	movsd	(%r8,%rdx,8), %xmm0
	leaq	(%rsi,%rdx,8), %rax
	cmpl	%r9d, %edi
	mulsd	a(%rip), %xmm0
	addsd	(%rax), %xmm0
	movsd	%xmm0, (%rax)
	jnb	.L8
	movslq	%edi, %rdi
	movsd	(%r8,%rdi,8), %xmm0
	leaq	(%rsi,%rdi,8), %rax
	mulsd	a(%rip), %xmm0
	addsd	(%rax), %xmm0
	movsd	%xmm0, (%rax)
.L8:
	leaq	16(%rsp), %rsi
	xorl	%edi, %edi
	call	clock_gettime@PLT
	movq	24(%rsp), %rax
	subq	8(%rsp), %rax
	leaq	.LC6(%rip), %rsi
	pxor	%xmm0, %xmm0
	movl	$1, %edi
	pxor	%xmm1, %xmm1
	cvtsi2sdq	%rax, %xmm0
	movq	16(%rsp), %rax
	subq	(%rsp), %rax
	cvtsi2sdq	%rax, %xmm1
	movl	$1, %eax
	divsd	.LC5(%rip), %xmm0
	addsd	%xmm1, %xmm0
	call	__printf_chk@PLT
	movl	N(%rip), %edx
	cmpl	$5, %edx
	ja	.L15
	testl	%edx, %edx
	je	.L16
	leaq	.LC7(%rip), %r12
	xorl	%ebp, %ebp
	xorl	%ebx, %ebx
	.p2align 4,,10
	.p2align 3
.L17:
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
	jb	.L17
.L16:
	movl	$10, %edi
	call	putchar@PLT
.L18:
	xorl	%eax, %eax
	movq	40(%rsp), %rbx
	xorq	%fs:40, %rbx
	jne	.L47
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
.L15:
	.cfi_restore_state
	movq	y(%rip), %rax
	leal	-1(%rdx), %ecx
	leaq	.LC8(%rip), %rsi
	movl	$1, %edi
	movq	%rcx, %rdx
	movsd	(%rax,%rcx,8), %xmm1
	movsd	(%rax), %xmm0
	movl	$2, %eax
	call	__printf_chk@PLT
	jmp	.L18
.L9:
	leal	-1(%r9), %eax
	leaq	8(,%rax,8), %rdx
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L13:
	movsd	a(%rip), %xmm0
	mulsd	(%r8,%rax), %xmm0
	addsd	(%rsi,%rax), %xmm0
	movsd	%xmm0, (%rsi,%rax)
	addq	$8, %rax
	cmpq	%rdx, %rax
	jne	.L13
	jmp	.L8
.L20:
	xorl	%edx, %edx
	jmp	.L4
.L47:
	call	__stack_chk_fail@PLT
.L46:
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	orl	$-1, %edi
	call	exit@PLT
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
	.section	.rodata.cst16,"aM",@progbits,16
	.align 16
.LC3:
	.long	0
	.long	1072693248
	.long	0
	.long	1072693248
	.align 16
.LC4:
	.long	0
	.long	1074790400
	.long	0
	.long	1074790400
	.section	.rodata.cst8
	.align 8
.LC5:
	.long	0
	.long	1104006501
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
