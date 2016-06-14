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
		leal	b1,%eax
		pushl	%eax
		pushl	%ebp
		call	_read_int
		addl	$8,%esp
		movl	b1,%eax
		pushl	%eax
		pushl	%ebp
		call	_writeln_char
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
		.comm	b1,4,4
