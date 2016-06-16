sys_call_id = 0x80
exit_syscall = 0x1

.data


# inner10 function
.text
.global inner10
		.type	inner10,@function
inner10:
		pushl	%ebp
		movl	%esp,%ebp
		subl	$8,%esp
		movl	12(%ebp),%eax
		pushl	%eax
		pushl	%ebp
		call	_writeln_int
		addl	$8,%esp
		leave
		ret
# test16 function
.text
.global test16
		.type	test16,@function
test16:
		pushl	%ebp
		movl	%esp,%ebp
		subl	$8,%esp
		movl	12(%ebp),%eax
		pushl	%eax
		movl	$1,%eax
		popl	%edx
		addl	%edx,%eax
		movl	%eax,12(%ebp)
		movl	12(%ebp),%eax
		pushl	%eax
		pushl	%ebp
		call	inner10
		addl	$8,%esp
		movl	12(%ebp),%eax
		pushl	%eax
		movl	$2,%eax
		popl	%edx
		addl	%edx,%eax
		movl	%eax,12(%ebp)
		movl	%eax,-4(%ebp)
		leave
		ret
# main routine
.text
.global _main
		.type _main,@function
_main:
		pushl	%ebp
		movl	%esp,%ebp
		movl	$10,%eax
		movl	%eax,a14
		movl	a14,%eax
		pushl	%eax
		pushl	%ebp
		call	test16
		addl	$8,%esp
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
		.comm	a14,4,4
