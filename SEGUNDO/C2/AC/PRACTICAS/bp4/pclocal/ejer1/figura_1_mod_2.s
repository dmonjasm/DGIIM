	.file	"figura_1_mod_2.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC1:
	.string	"Tiempo: %f\n"
.LC2:
	.string	"R[0]=%d -- R[%d]=%d\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB52:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	leaq	s(%rip), %rbp
	subq	$56, %rsp
	.cfi_def_cfa_offset 80
	movq	%rbp, %rbx
	movq	%fs:40, %rax
	movq	%rax, 40(%rsp)
	xorl	%eax, %eax
	leaq	40000(%rbp), %rax
	.p2align 4,,10
	.p2align 3
.L2:
	movl	$1, (%rbx)
	movl	$1, 4(%rbx)
	addq	$8, %rbx
	cmpq	%rbx, %rax
	jne	.L2
	movq	%rsp, %rsi
	xorl	%edi, %edi
	call	clock_gettime@PLT
	leaq	R(%rip), %r9
	xorl	%r8d, %r8d
	.p2align 4,,10
	.p2align 3
.L3:
	movl	%r8d, %edx
	movq	%rbp, %rax
	xorl	%ecx, %ecx
	xorl	%edi, %edi
	.p2align 4,,10
	.p2align 3
.L4:
	movl	(%rax), %esi
	addq	$40, %rax
	leal	(%rdx,%rsi,2), %esi
	addl	%esi, %edi
	movl	-32(%rax), %esi
	leal	(%rdx,%rsi,2), %esi
	addl	%esi, %edi
	movl	-24(%rax), %esi
	leal	(%rdx,%rsi,2), %esi
	addl	%edi, %esi
	movl	-16(%rax), %edi
	leal	(%rdx,%rdi,2), %edi
	addl	%edi, %esi
	movl	-8(%rax), %edi
	leal	(%rdx,%rdi,2), %edi
	addl	%esi, %edi
	movl	-36(%rax), %esi
	leal	(%rsi,%rsi,2), %esi
	subl	%edx, %esi
	addl	%esi, %ecx
	movl	-28(%rax), %esi
	leal	(%rsi,%rsi,2), %esi
	subl	%edx, %esi
	addl	%esi, %ecx
	movl	-20(%rax), %esi
	leal	(%rsi,%rsi,2), %esi
	subl	%edx, %esi
	addl	%ecx, %esi
	movl	-12(%rax), %ecx
	leal	(%rcx,%rcx,2), %ecx
	subl	%edx, %ecx
	addl	%ecx, %esi
	movl	-4(%rax), %ecx
	leal	(%rcx,%rcx,2), %ecx
	subl	%edx, %ecx
	addl	%esi, %ecx
	cmpq	%rax, %rbx
	jne	.L4
	cmpl	%ecx, %edi
	jge	.L5
	movl	%edi, (%r9,%r8,4)
.L6:
	addq	$1, %r8
	cmpq	$40000, %r8
	jne	.L3
	leaq	16(%rsp), %rsi
	xorl	%edi, %edi
	call	clock_gettime@PLT
	movq	24(%rsp), %rax
	subq	8(%rsp), %rax
	leaq	.LC1(%rip), %rsi
	pxor	%xmm0, %xmm0
	movl	$1, %edi
	pxor	%xmm1, %xmm1
	cvtsi2sdq	%rax, %xmm0
	movq	16(%rsp), %rax
	subq	(%rsp), %rax
	cvtsi2sdq	%rax, %xmm1
	movl	$1, %eax
	divsd	.LC0(%rip), %xmm0
	addsd	%xmm1, %xmm0
	call	__printf_chk@PLT
	movl	159996+R(%rip), %r8d
	movl	R(%rip), %edx
	leaq	.LC2(%rip), %rsi
	xorl	%eax, %eax
	movl	$39999, %ecx
	movl	$1, %edi
	call	__printf_chk@PLT
	xorl	%eax, %eax
	movq	40(%rsp), %rbx
	xorq	%fs:40, %rbx
	jne	.L13
	addq	$56, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
.L5:
	.cfi_restore_state
	movl	%ecx, (%r9,%r8,4)
	jmp	.L6
.L13:
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE52:
	.size	main, .-main
	.comm	R,160000,32
	.comm	s,40000,32
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC0:
	.long	0
	.long	1104006501
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
