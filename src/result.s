sys_call_id = 0x80
exit_syscall = 0x1

.data


# test12 function
.text
.global test12
		.type	test12,@function
test12:
		pushl	%ebp
		movl	%esp,%ebp
		subl	$8,%esp
		movl	12(%ebp),%eax
		pushl	%eax
		movl	$2,%eax
		subl	$1,%eax
		movl	$4,%ecx
		imul	%ecx
		popl	%edx
		addl	%eax,%edx
		pushl	%edx
		popl	%ebx
		movl	(%ebx),%eax
		pushl	%eax
		pushl	%ebp
		call	_writeln_int
		addl	$8,%esp
		leave
		ret
# main routine
.text
.global _main
		.type _main,@function
_main:
		pushl	%ebp
		movl	%esp,%ebp
		leal	a8,%eax
		pushl	%eax
		movl	$1,%eax
		subl	$1,%eax
		movl	$4,%ecx
		imul	%ecx
		popl	%edx
		addl	%eax,%edx
		pushl	%edx
		movl	$1,%eax
		popl	%ebx
		movl	%eax,(%ebx)
		leal	a8,%eax
		pushl	%eax
		movl	$2,%eax
		subl	$1,%eax
		movl	$4,%ecx
		imul	%ecx
		popl	%edx
		addl	%eax,%edx
		pushl	%edx
		movl	$2,%eax
		popl	%ebx
		movl	%eax,(%ebx)
		leal	a8,%eax
		pushl	%eax
		pushl	%ebp
		call	test12
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
		.comm	a8,40,4
