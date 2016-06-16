sys_call_id = 0x80
exit_syscall = 0x1

.data

.globl str_0
		.section .rodata
		.align 4
.LCstr_0:
		.string "hhhhh"
		.data
		.align 4
		.type str_0 @object
str_0:
		.long .LCstr_0

# inner7 function
.text
.global inner7
		.type	inner7,@function
inner7:
		pushl	%ebp
		movl	%esp,%ebp
		subl	$8,%esp
		pushl	%eax
		pushl	%ebp
		call	_writeln_string
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
		movl	str_0,%eax
		pushl	%eax
		pushl	%ebp
		call	inner7
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
