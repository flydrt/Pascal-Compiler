sys_call_id = 0x80
exit_syscall = 0x1

.data


.text
.global _main
		.type _main,@function
_main:
		pushl	%ebp
		movl	%esp,%ebp
		movl	$0,%eax
		movl	%eax,a0
		movl	$1,%eax
		movl	%eax,b1
for_start_LABEL0:
		movl	b1,%eax
		pushl	%eax
		movl	$10,%eax
		popl	%edx
		cmpl	%eax,%edx
		movl	$1,%eax
		jle	j_LABEL1
		xorl	%eax,%eax
j_LABEL1:
		cmpl	$1,%eax
		jl	for_end_LABEL2
		movl	a0,%eax
		pushl	%eax
		movl	$1,%eax
		popl	%edx
		addl	%edx,%eax
		movl	%eax,a0
		incl	b1
		jmp	for_start_LABEL0
for_end_LABEL2:
		movl	a0,%eax
		pushl	%eax
		pushl	%ebp
		call	_writeln_int
		addl	$8,%esp
		leave
		ret

.global _start
_start:
		call _main
		movl $0,%ebx
		movl $exit_syscall,%eax
		int $sys_call_id

#bss section
		.comm	a0,4,4
		.comm	b1,4,4
