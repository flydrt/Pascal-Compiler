sys_call_id = 0x80
exit_syscall = 0x1

.data

.globl str_0
		.section .rodata
		.align 4
.LCstr_0:
		.string "yes"
		.data
		.align 4
		.type str_0 @object
str_0:
		.long .LCstr_0

# main routine
.text
.global _main
		.type _main,@function
_main:
		pushl	%ebp
		movl	%esp,%ebp
		leal	c2,%eax
		pushl	%eax
		pushl	%ebp
		call	_read_char
		addl	$8,%esp
		movl	c2,%eax
		pushl	%eax
		movl	$65,%eax
		popl	%edx
		cmpl	%eax,%edx
		movl	$1,%eax
		jg	j_LABEL2
		xorl	%eax,%eax
j_LABEL2:
		cmpl	$1,%eax
		jl	if_else_LABEL0
		movl	str_0,%eax
		pushl	%eax
		pushl	%ebp
		call	_writeln_string
		addl	$8,%esp
		jmp	if_exit_LABEL1
if_else_LABEL0:
if_exit_LABEL1:
		movl	c2,%eax
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
		.comm	c2,4,4
