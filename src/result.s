sys_call_id = 0x80
exit_syscall = 0x1

.data


# main routine
.text
.global _main
		.type _main,@function
_main:
		pushl	%ebp
		movl	%esp,%ebp
		leal	b0,%eax
		pushl	%eax
		pushl	%ebp
		call	_read_int
		addl	$8,%esp
		movl	b0,%eax
		pushl	%eax
		movl	$1,%eax
		popl	%edx
		cmpl	%edx,%eax
		pushl	%edx
		jne	case_LABEL0
		movl	$1,%eax
		movl	%eax,c1
case_LABEL0:
		movl	$2,%eax
		popl	%edx
		cmpl	%edx,%eax
		pushl	%edx
		jne	case_LABEL1
		movl	$2,%eax
		movl	%eax,c1
case_LABEL1:
		movl	$3,%eax
		popl	%edx
		cmpl	%edx,%eax
		pushl	%edx
		jne	case_LABEL2
		movl	$3,%eax
		movl	%eax,c1
case_LABEL2:
		movl	c1,%eax
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
		.comm	b0,4,4
		.comm	c1,4,4
