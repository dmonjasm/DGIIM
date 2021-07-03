	.file	"SumaVectoresC.c"
	.text
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC0:
	.string	"Faltan n\302\272 componentes del vector"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC1:
	.string	"Tama\303\261o Vectores:%u (%u B)\n"
	.section	.rodata.str1.8
	.align 8
.LC2:
	.string	"No hay suficiente espacio para los vectores "
	.align 8
.LC4:
	.string	"/ V1[%d]+V2[%d]=V3[%d](%8.6f+%8.6f=%8.6f) /\n"
	.align 8
.LC5:
	.string	"Tiempo:%11.9f\t / Tama\303\261o Vectores:%u\t/ V1[0]+V2[0]=V3[0](%8.6f+%8.6f=%8.6f) / / V1[%d]+V2[%d]=V3[%d](%8.6f+%8.6f=%8.6f) /\n"
	.align 8
.LC6:
	.string	"Tiempo:%11.9f\t / Tama\303\261o Vectores:%u\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB20:
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
	subq	$56, %rsp
	.cfi_def_cfa_offset 112
	cmpl	$1, %edi
	jle	.L26
	movq	8(%rsi), %rdi
	movl	$10, %edx
	xorl	%esi, %esi
	call	strtol
	movl	$4, %edx
	movl	$.LC1, %edi
	movq	%rax, %rbx
	movl	%eax, %esi
	movl	%eax, %r13d
	xorl	%eax, %eax
	call	printf
	movl	%ebx, %r14d
	leaq	0(,%r14,8), %r15
	movq	%r15, %rdi
	call	malloc
	movq	%r15, %rdi
	movq	%rax, %rbp
	call	malloc
	movq	%r15, %rdi
	movq	%rax, %r12
	call	malloc
	movq	%rax, %r15
	testq	%rbp, %rbp
	je	.L3
	testq	%r12, %r12
	je	.L3
	testl	%ebx, %ebx
	je	.L27
	pxor	%xmm1, %xmm1
	movsd	.LC3(%rip), %xmm3
	xorl	%eax, %eax
	cvtsi2sdq	%r14, %xmm1
	leal	-1(%rbx), %r14d
	movq	%r14, %rdx
	mulsd	%xmm3, %xmm1
	.p2align 4,,10
	.p2align 3
.L8:
	pxor	%xmm0, %xmm0
	movapd	%xmm1, %xmm2
	movapd	%xmm1, %xmm7
	movq	%rax, %rcx
	cvtsi2sdl	%eax, %xmm0
	mulsd	%xmm3, %xmm0
	addsd	%xmm0, %xmm2
	subsd	%xmm0, %xmm7
	movsd	%xmm2, 0(%rbp,%rax,8)
	movsd	%xmm7, (%r12,%rax,8)
	addq	$1, %rax
	cmpq	%rcx, %r14
	jne	.L8
	leaq	16(%rsp), %rsi
	xorl	%edi, %edi
	movl	%edx, 12(%rsp)
	call	clock_gettime
	movl	12(%rsp), %edx
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L10:
	movsd	0(%rbp,%rax,8), %xmm0
	addsd	(%r12,%rax,8), %xmm0
	movq	%rax, %rcx
	movsd	%xmm0, (%r15,%rax,8)
	addq	$1, %rax
	cmpq	%rcx, %r14
	jne	.L10
	xorl	%edi, %edi
	leaq	32(%rsp), %rsi
	movl	%edx, 12(%rsp)
	call	clock_gettime
	movq	40(%rsp), %rax
	pxor	%xmm0, %xmm0
	subq	24(%rsp), %rax
	cvtsi2sdq	%rax, %xmm0
	pxor	%xmm1, %xmm1
	movq	32(%rsp), %rax
	subq	16(%rsp), %rax
	cvtsi2sdq	%rax, %xmm1
	cmpl	$9, %ebx
	divsd	.LC7(%rip), %xmm0
	movl	12(%rsp), %edx
	addsd	%xmm1, %xmm0
	jbe	.L28
	movsd	(%r15,%r14,8), %xmm6
	movsd	(%r12,%r14,8), %xmm5
	movl	%edx, %ecx
	movl	%ebx, %esi
	movsd	0(%rbp,%r14,8), %xmm4
	movsd	(%r15), %xmm3
	movl	%edx, %r8d
	movl	$.LC5, %edi
	movsd	(%r12), %xmm2
	movsd	0(%rbp), %xmm1
	movl	$7, %eax
	call	printf
.L13:
	movq	%rbp, %rdi
	call	free
	movq	%r12, %rdi
	call	free
	movq	%r15, %rdi
	call	free
	addq	$56, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	xorl	%eax, %eax
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
.L28:
	.cfi_restore_state
	movl	%ebx, %esi
	movl	$.LC6, %edi
	movl	$1, %eax
	xorl	%ebx, %ebx
	call	printf
	.p2align 4,,10
	.p2align 3
.L12:
	movsd	0(%rbp,%rbx,8), %xmm0
	movsd	(%r15,%rbx,8), %xmm2
	movl	%ebx, %ecx
	movl	%ebx, %edx
	movsd	(%r12,%rbx,8), %xmm1
	movl	%ebx, %esi
	movl	$.LC4, %edi
	movl	$3, %eax
	addq	$1, %rbx
	call	printf
	cmpl	%ebx, %r13d
	ja	.L12
	jmp	.L13
.L27:
	leaq	16(%rsp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	leaq	32(%rsp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	movq	40(%rsp), %rax
	pxor	%xmm0, %xmm0
	xorl	%esi, %esi
	subq	24(%rsp), %rax
	pxor	%xmm1, %xmm1
	movl	$.LC6, %edi
	cvtsi2sdq	%rax, %xmm0
	movq	32(%rsp), %rax
	subq	16(%rsp), %rax
	divsd	.LC7(%rip), %xmm0
	cvtsi2sdq	%rax, %xmm1
	movl	$1, %eax
	addsd	%xmm1, %xmm0
	call	printf
	jmp	.L13
.L26:
	movl	$.LC0, %edi
	call	puts
	orl	$-1, %edi
	call	exit
.L3:
	movl	$.LC2, %edi
	call	puts
	movl	$-2, %edi
	call	exit
	.cfi_endproc
.LFE20:
	.size	main, .-main
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC3:
	.long	2576980378
	.long	1069128089
	.align 8
.LC7:
	.long	0
	.long	1104006501
	.ident	"GCC: (GNU) 9.2.0"
	.section	.note.GNU-stack,"",@progbits
