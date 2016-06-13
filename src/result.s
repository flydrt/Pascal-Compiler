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
		leal	a0,%eax
		pushl	%eax
		movl	$7,%eax
		subl	$6,%eax
		movl	$4,%ecx
		imul	%ecx
		popl	%edx
		addl	%eax,%edx
		pushl	%edx
		movl	$3,%eax
		popl	%ebx
		movl	%eax,(%ebx)
		leal	a0,%eax
		pushl	%eax
		movl	$7,%eax
		subl	$6,%eax
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

.global _start
_start:
		call _main
		movl $0,%ebx
		movl $exit_syscall,%eax
		int $sys_call_id

#bss section
		.comm	a0,20,4
