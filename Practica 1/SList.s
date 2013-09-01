	.file	"SList.c"
	.text
.globl slist_append
	.type	slist_append, @function
slist_append:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	movq	%rsp, %rbp
	.cfi_offset 6, -16
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	$16, %edi
	call	malloc
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	-28(%rbp), %edx
	movl	%edx, (%rax)
	movq	-8(%rbp), %rax
	movq	$0, 8(%rax)
	cmpq	$0, -24(%rbp)
	jne	.L2
	movq	-8(%rbp), %rax
	jmp	.L3
.L2:
	movq	-24(%rbp), %rax
	movq	%rax, -16(%rbp)
	jmp	.L4
.L5:
	movq	-16(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -16(%rbp)
.L4:
	movq	-16(%rbp), %rax
	movq	8(%rax), %rax
	testq	%rax, %rax
	jne	.L5
	movq	-16(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	-24(%rbp), %rax
.L3:
	leave
	ret
	.cfi_endproc
.LFE0:
	.size	slist_append, .-slist_append
.globl slist_prepend
	.type	slist_prepend, @function
slist_prepend:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	movq	%rsp, %rbp
	.cfi_offset 6, -16
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	$16, %edi
	call	malloc
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	-8(%rbp), %rax
	movl	-28(%rbp), %edx
	movl	%edx, (%rax)
	movq	-8(%rbp), %rax
	leave
	ret
	.cfi_endproc
.LFE1:
	.size	slist_prepend, .-slist_prepend
.globl slist_destroy
	.type	slist_destroy, @function
slist_destroy:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	movq	%rsp, %rbp
	.cfi_offset 6, -16
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	jmp	.L10
.L11:
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -24(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	free
.L10:
	cmpq	$0, -24(%rbp)
	jne	.L11
	leave
	ret
	.cfi_endproc
.LFE2:
	.size	slist_destroy, .-slist_destroy
.globl slist_foreach
	.type	slist_foreach, @function
slist_foreach:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	movq	%rsp, %rbp
	.cfi_offset 6, -16
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	jmp	.L14
.L15:
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	movq	-40(%rbp), %rdx
	movq	-32(%rbp), %rcx
	movq	%rdx, %rsi
	movl	%eax, %edi
	call	*%rcx
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -8(%rbp)
.L14:
	cmpq	$0, -8(%rbp)
	jne	.L15
	leave
	ret
	.cfi_endproc
.LFE3:
	.size	slist_foreach, .-slist_foreach
.globl slist_has_next
	.type	slist_has_next, @function
slist_has_next:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	movq	%rsp, %rbp
	.cfi_offset 6, -16
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	testq	%rax, %rax
	je	.L18
	movl	$1, %eax
	jmp	.L19
.L18:
	movl	$0, %eax
.L19:
	leave
	ret
	.cfi_endproc
.LFE4:
	.size	slist_has_next, .-slist_has_next
.globl slist_length
	.type	slist_length, @function
slist_length:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	movq	%rsp, %rbp
	.cfi_offset 6, -16
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L22
.L23:
	addl	$1, -4(%rbp)
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -24(%rbp)
.L22:
	cmpq	$0, -24(%rbp)
	jne	.L23
	movl	-4(%rbp), %eax
	leave
	ret
	.cfi_endproc
.LFE5:
	.size	slist_length, .-slist_length
.globl copy
	.type	copy, @function
copy:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	movq	%rsp, %rbp
	.cfi_offset 6, -16
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	jmp	.L26
.L27:
	movq	-8(%rbp), %rax
	movl	(%rax), %edx
	movq	-16(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	slist_append
	movq	%rax, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -8(%rbp)
.L26:
	cmpq	$0, -8(%rbp)
	jne	.L27
	leave
	ret
	.cfi_endproc
.LFE6:
	.size	copy, .-copy
.globl slist_concat
	.type	slist_concat, @function
slist_concat:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	movq	%rsp, %rbp
	.cfi_offset 6, -16
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movl	$16, %edi
	call	malloc
	movq	%rax, -8(%rbp)
	movq	$0, -8(%rbp)
	jmp	.L30
.L31:
	movq	-24(%rbp), %rax
	movl	(%rax), %edx
	movq	-8(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	slist_append
	movq	%rax, -8(%rbp)
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -24(%rbp)
.L30:
	cmpq	$0, -24(%rbp)
	jne	.L31
	jmp	.L32
.L33:
	movq	-32(%rbp), %rax
	movl	(%rax), %edx
	movq	-8(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	slist_append
	movq	%rax, -8(%rbp)
	movq	-32(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -32(%rbp)
.L32:
	cmpq	$0, -32(%rbp)
	jne	.L33
	movq	-8(%rbp), %rax
	leave
	ret
	.cfi_endproc
.LFE7:
	.size	slist_concat, .-slist_concat
.globl slist_insert
	.type	slist_insert, @function
slist_insert:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	movq	%rsp, %rbp
	.cfi_offset 6, -16
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movl	%esi, -44(%rbp)
	movl	%edx, -48(%rbp)
	movl	$1, -4(%rbp)
	movl	$16, %edi
	call	malloc
	movq	%rax, -16(%rbp)
	jmp	.L36
.L37:
	movq	-40(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	-40(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -40(%rbp)
	addl	$1, -4(%rbp)
.L36:
	movl	-4(%rbp), %eax
	cmpl	-48(%rbp), %eax
	jl	.L37
	cmpl	$1, -48(%rbp)
	jne	.L38
	movq	-40(%rbp), %rax
	movq	8(%rax), %rdx
	movq	-16(%rbp), %rax
	movq	%rdx, 8(%rax)
	movq	-40(%rbp), %rax
	movl	(%rax), %edx
	movq	-16(%rbp), %rax
	movl	%edx, (%rax)
	movq	-40(%rbp), %rax
	movl	-44(%rbp), %edx
	movl	%edx, (%rax)
	movq	-40(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, 8(%rax)
	jmp	.L40
.L38:
	movq	-16(%rbp), %rax
	movl	-44(%rbp), %edx
	movl	%edx, (%rax)
	movq	-16(%rbp), %rax
	movq	-40(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	-24(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, 8(%rax)
.L40:
	leave
	ret
	.cfi_endproc
.LFE8:
	.size	slist_insert, .-slist_insert
.globl slist_remove
	.type	slist_remove, @function
slist_remove:
.LFB9:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	movq	%rsp, %rbp
	.cfi_offset 6, -16
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movl	%esi, -44(%rbp)
	movl	$1, -4(%rbp)
	jmp	.L42
.L43:
	movq	-40(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-40(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -40(%rbp)
	addl	$1, -4(%rbp)
.L42:
	movl	-4(%rbp), %eax
	cmpl	-44(%rbp), %eax
	jl	.L43
	cmpl	$1, -44(%rbp)
	jne	.L44
	movq	-40(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -24(%rbp)
	movq	-40(%rbp), %rax
	movq	8(%rax), %rax
	movq	8(%rax), %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, 8(%rax)
	movq	-24(%rbp), %rax
	movl	(%rax), %edx
	movq	-40(%rbp), %rax
	movl	%edx, (%rax)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	free
	jmp	.L46
.L44:
	movq	-16(%rbp), %rax
	movq	8(%rax), %rax
	movq	8(%rax), %rdx
	movq	-16(%rbp), %rax
	movq	%rdx, 8(%rax)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	free
.L46:
	leave
	ret
	.cfi_endproc
.LFE9:
	.size	slist_remove, .-slist_remove
.globl slist_contains
	.type	slist_contains, @function
slist_contains:
.LFB10:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	movq	%rsp, %rbp
	.cfi_offset 6, -16
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	jmp	.L48
.L51:
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	cmpl	-12(%rbp), %eax
	jne	.L49
	movl	$1, %eax
	jmp	.L50
.L49:
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -8(%rbp)
.L48:
	cmpq	$0, -8(%rbp)
	jne	.L51
	movl	$0, %eax
.L50:
	leave
	ret
	.cfi_endproc
.LFE10:
	.size	slist_contains, .-slist_contains
.globl slist_index
	.type	slist_index, @function
slist_index:
.LFB11:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	movq	%rsp, %rbp
	.cfi_offset 6, -16
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	-28(%rbp), %edx
	movq	-24(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	slist_contains
	testl	%eax, %eax
	je	.L54
	movl	$1, -4(%rbp)
	jmp	.L55
.L58:
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	cmpl	-28(%rbp), %eax
	jne	.L56
	movl	-4(%rbp), %eax
	jmp	.L57
.L56:
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -24(%rbp)
	addl	$1, -4(%rbp)
.L55:
	cmpq	$0, -24(%rbp)
	jne	.L58
	jmp	.L53
.L54:
	movl	$-1, %eax
.L57:
.L53:
	leave
	ret
	.cfi_endproc
.LFE11:
	.size	slist_index, .-slist_index
.globl slist_intersect
	.type	slist_intersect, @function
slist_intersect:
.LFB12:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	movq	%rsp, %rbp
	.cfi_offset 6, -16
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movl	$16, %edi
	call	malloc
	movq	%rax, -8(%rbp)
	movq	$0, -8(%rbp)
	jmp	.L61
.L63:
	movq	-24(%rbp), %rax
	movl	(%rax), %edx
	movq	-32(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	slist_contains
	testl	%eax, %eax
	je	.L62
	movq	-24(%rbp), %rax
	movl	(%rax), %edx
	movq	-8(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	slist_contains
	testl	%eax, %eax
	jne	.L62
	movq	-24(%rbp), %rax
	movl	(%rax), %edx
	movq	-8(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	slist_append
	movq	%rax, -8(%rbp)
.L62:
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -24(%rbp)
.L61:
	cmpq	$0, -24(%rbp)
	jne	.L63
	movq	-8(%rbp), %rax
	leave
	ret
	.cfi_endproc
.LFE12:
	.size	slist_intersect, .-slist_intersect
.globl slist_intersect_custom
	.type	slist_intersect_custom, @function
slist_intersect_custom:
.LFB13:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	movq	%rsp, %rbp
	.cfi_offset 6, -16
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%rdx, -56(%rbp)
	movl	$16, %edi
	call	malloc
	movq	%rax, -16(%rbp)
	movq	$0, -16(%rbp)
	jmp	.L66
.L70:
	movq	-48(%rbp), %rax
	movq	%rax, -24(%rbp)
	jmp	.L67
.L69:
	movq	-48(%rbp), %rax
	movl	(%rax), %edx
	movq	-40(%rbp), %rax
	movl	(%rax), %eax
	movq	-56(%rbp), %rcx
	movl	%edx, %esi
	movl	%eax, %edi
	call	*%rcx
	testl	%eax, %eax
	je	.L68
	movq	-40(%rbp), %rax
	movl	(%rax), %edx
	movq	-16(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	slist_contains
	testl	%eax, %eax
	jne	.L68
	movq	-40(%rbp), %rax
	movl	(%rax), %edx
	movq	-16(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	slist_append
	movq	%rax, -16(%rbp)
.L68:
	movq	-48(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -48(%rbp)
.L67:
	cmpq	$0, -48(%rbp)
	jne	.L69
	movq	-24(%rbp), %rax
	movq	%rax, -48(%rbp)
	movq	-40(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -40(%rbp)
.L66:
	cmpq	$0, -40(%rbp)
	jne	.L70
	movq	-16(%rbp), %rax
	leave
	ret
	.cfi_endproc
.LFE13:
	.size	slist_intersect_custom, .-slist_intersect_custom
.globl slist_sort
	.type	slist_sort, @function
slist_sort:
.LFB14:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	movq	%rsp, %rbp
	.cfi_offset 6, -16
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$64, %rsp
	movq	%rdi, -72(%rbp)
	movq	%rsi, -80(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movq	%rsp, %rax
	movq	%rax, %r12
	.cfi_offset 3, -32
	.cfi_offset 12, -24
	movq	-72(%rbp), %rax
	movq	%rax, %rdi
	call	slist_length
	movl	%eax, -28(%rbp)
	movl	-28(%rbp), %eax
	movslq	%eax,%rdx
	subq	$1, %rdx
	movq	%rdx, -48(%rbp)
	cltq
	salq	$2, %rax
	addq	$15, %rax
	addq	$15, %rax
	shrq	$4, %rax
	salq	$4, %rax
	subq	%rax, %rsp
	movq	%rsp, %rax
	addq	$15, %rax
	shrq	$4, %rax
	salq	$4, %rax
	movq	%rax, -56(%rbp)
	movq	-72(%rbp), %rax
	movq	%rax, -40(%rbp)
	movl	$0, -32(%rbp)
	jmp	.L73
.L74:
	movl	-32(%rbp), %edx
	movq	-72(%rbp), %rax
	movl	(%rax), %ecx
	movq	-56(%rbp), %rax
	movslq	%edx,%rdx
	movl	%ecx, (%rax,%rdx,4)
	movq	-72(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -72(%rbp)
	addl	$1, -32(%rbp)
.L73:
	movl	-32(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jl	.L74
	movq	-40(%rbp), %rax
	movq	%rax, -72(%rbp)
	movl	-28(%rbp), %eax
	movslq	%eax,%rbx
	movq	-56(%rbp), %rax
	movq	-80(%rbp), %rdx
	movq	%rdx, %rcx
	movl	$4, %edx
	movq	%rbx, %rsi
	movq	%rax, %rdi
	call	qsort
	movl	$0, -32(%rbp)
	jmp	.L75
.L76:
	movl	-32(%rbp), %edx
	movq	-56(%rbp), %rax
	movslq	%edx,%rdx
	movl	(%rax,%rdx,4), %edx
	movq	-72(%rbp), %rax
	movl	%edx, (%rax)
	movq	-72(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -72(%rbp)
	addl	$1, -32(%rbp)
.L75:
	movl	-32(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jl	.L76
	movq	%r12, %rsp
	movq	-24(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L78
	call	__stack_chk_fail
.L78:
	leaq	-16(%rbp), %rsp
	addq	$0, %rsp
	popq	%rbx
	popq	%r12
	leave
	ret
	.cfi_endproc
.LFE14:
	.size	slist_sort, .-slist_sort
	.ident	"GCC: (Ubuntu 4.4.3-4ubuntu5) 4.4.3"
	.section	.note.GNU-stack,"",@progbits
