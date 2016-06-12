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
		movl	$0,%eax
		movl	%eax,a0
		movl	$1,%eax
		movl	%eax,b1
		movl	a0,%eax
		pushl	%eax
		movl	b1,%eax
		popl	%edx
		andl	%edx,%eax
		pushl	%eax
		pushl	%ebp
		call	_writeln_int
		addl	$8,%esp
		movl	b1,%eax
		pushl	%eax
		movl	b1,%eax
		popl	%edx
		andl	%edx,%eax
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
