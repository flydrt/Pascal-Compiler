sys_call_id = 0x80
exit_syscall = 0x1

.data

.globl str_0
		.section .rodata
		.align 4
.LCstr_0:
		.string "abs:"
		.data
		.align 4
		.type str_0 @object
str_0:
		.long .LCstr_0
.globl str_1
		.section .rodata
		.align 4
.LCstr_1:
		.string "succ:"
		.data
		.align 4
		.type str_1 @object
str_1:
		.long .LCstr_1
.globl str_2
		.section .rodata
		.align 4
.LCstr_2:
		.string "ord:"
		.data
		.align 4
		.type str_2 @object
str_2:
		.long .LCstr_2
.globl str_3
		.section .rodata
		.align 4
.LCstr_3:
		.string "chr:"
		.data
		.align 4
		.type str_3 @object
str_3:
		.long .LCstr_3
.globl str_4
		.section .rodata
		.align 4
.LCstr_4:
		.string "odd:"
		.data
		.align 4
		.type str_4 @object
str_4:
		.long .LCstr_4
.globl str_5
		.section .rodata
		.align 4
.LCstr_5:
		.string "pred:"
		.data
		.align 4
		.type str_5 @object
str_5:
		.long .LCstr_5
.globl str_6
		.section .rodata
		.align 4
.LCstr_6:
		.string "sqr:"
		.data
		.align 4
		.type str_6 @object
str_6:
		.long .LCstr_6

# main routine
.text
.global _main
		.type _main,@function
_main:
		pushl	%ebp
		movl	%esp,%ebp
		leal	a0,%eax
		pushl	%eax
		pushl	%ebp
		call	_read_int
		addl	$8,%esp
		movl	$97,%eax
		movl	%eax,b1
		movl	str_0,%eax
		pushl	%eax
		pushl	%ebp
		call	_write_string
		addl	$8,%esp
		movl	a0,%eax
		pushl	%eax
		pushl	%ebp
		call	_abs_int
		addl	$8, %esp
		pushl	%eax
		pushl	%ebp
		call	_writeln_int
		addl	$8,%esp
		movl	str_1,%eax
		pushl	%eax
		pushl	%ebp
		call	_write_string
		addl	$8,%esp
		movl	a0,%eax
		addl	$1,%eax
		pushl	%eax
		pushl	%ebp
		call	_writeln_int
		addl	$8,%esp
		movl	str_2,%eax
		pushl	%eax
		pushl	%ebp
		call	_write_string
		addl	$8,%esp
		movl	b1,%eax
		pushl	%eax
		pushl	%ebp
		call	_writeln_int
		addl	$8,%esp
		movl	str_3,%eax
		pushl	%eax
		pushl	%ebp
		call	_write_string
		addl	$8,%esp
		movl	a0,%eax
		movl	$0,%edx
		subl	%eax,%edx
		movl	%edx,%eax
		pushl	%eax
		pushl	%ebp
		call	_writeln_char
		addl	$8,%esp
		movl	str_4,%eax
		pushl	%eax
		pushl	%ebp
		call	_write_string
		addl	$8,%esp
		movl	a0,%eax
		pushl	%eax
		pushl	%ebp
		call	_writeln_int
		addl	$8,%esp
		movl	str_5,%eax
		pushl	%eax
		pushl	%ebp
		call	_write_string
		addl	$8,%esp
		movl	a0,%eax
		subl	$1,%eax
		pushl	%eax
		pushl	%ebp
		call	_writeln_int
		addl	$8,%esp
		movl	str_6,%eax
		pushl	%eax
		pushl	%ebp
		call	_write_string
		addl	$8,%esp
		movl	a0,%eax
		pushl	%eax
		popl	%edx
		imul	%edx,%eax
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
		.comm	b1,4,4
		.comm	a0,4,4
