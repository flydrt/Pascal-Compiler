sys_call_id = 0x80
exit_syscall = 0x1

.data


.text
.global _main
		.type _main,@function
_main:
		pushl	%ebp
		movl	%esp,%ebp
		leal	intc1,%eax
		pushl	%eax
		pushl	%ebp
		call	_read_int
		addl	$8,%esp
while_start_LABEL0:
		movl	intc1,%eax
		pushl	%eax
		movl	$0,%eax
		popl	%edx
		cmpl	%eax,%edx
		movl	$1,%eax
		jg	j_LABEL2
		xorl	%eax,%eax
j_LABEL2:
		cmpl	$1,%eax
		jl	while_end_LABEL1
		movl	intc1,%eax
		pushl	%eax
		movl	$1,%eax
		popl	%edx
		subl	%eax,%edx
		movl	%edx,%eax
		movl	%eax,intc1
		jmp	while_start_LABEL0
while_end_LABEL1:
		movl	intc1,%eax
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
		.comm	intc1,4,4
