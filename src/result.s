sys_call_id = 0x80
exit_syscall = 0x1

.data

.globl str_0
		.section .rodata
		.align 4
.LCstr_0:
		.string "12"
		.data
		.align 4
		.type str_0 @object
str_0:
		.long .LCstr_0

# f222 function
.text
.global f222
		.type	f222,@function
f222:
		pushl	%ebp
		movl	%esp,%ebp
		subl	$8,%esp
		leal	v519,%eax
		pushl	%eax
		movl	$1,%eax
		subl	$1,%eax
		movl	$4,%ecx
		imul	%ecx
		popl	%edx
		addl	%eax,%edx
		pushl	%edx
		movl	$2,%eax
		pushl	%eax
		movl	$4,%eax
		popl	%edx
		imul	%edx,%eax
		popl	%ebx
		movl	%eax,(%ebx)
		movl	$5,%eax
		movl	%eax,n21
		leal	v519,%eax
		pushl	%eax
		movl	$1,%eax
		subl	$1,%eax
		movl	$4,%ecx
		imul	%ecx
		popl	%edx
		addl	%eax,%edx
		pushl	%edx
		popl	%ebx
		movl	(%ebx),%eax
		pushl	%eax
		movl	n21,%eax
		popl	%edx
		cmpl	%eax,%edx
		movl	$1,%eax
		jg	j_LABEL2
		xorl	%eax,%eax
j_LABEL2:
		cmpl	$1,%eax
		jl	if_else_LABEL0
		movl	n21,%eax
		movl	%eax,te20
		jmp	if_exit_LABEL1
if_else_LABEL0:
		leal	v519,%eax
		pushl	%eax
		movl	$1,%eax
		subl	$1,%eax
		movl	$4,%ecx
		imul	%ecx
		popl	%edx
		addl	%eax,%edx
		pushl	%edx
		popl	%ebx
		movl	(%ebx),%eax
		movl	%eax,te20
if_exit_LABEL1:
		movl	$1,%eax
		movl	%eax,i0
for_start_LABEL3:
		movl	i0,%eax
		pushl	%eax
		movl	n21,%eax
		popl	%edx
		cmpl	%eax,%edx
		movl	$1,%eax
		jle	j_LABEL4
		xorl	%eax,%eax
j_LABEL4:
		cmpl	$1,%eax
		jl	for_end_LABEL5
		leal	v519,%eax
		pushl	%eax
		movl	$1,%eax
		subl	$1,%eax
		movl	$4,%ecx
		imul	%ecx
		popl	%edx
		addl	%eax,%edx
		pushl	%edx
		leal	v519,%eax
		pushl	%eax
		movl	$1,%eax
		subl	$1,%eax
		movl	$4,%ecx
		imul	%ecx
		popl	%edx
		addl	%eax,%edx
		pushl	%edx
		popl	%ebx
		movl	(%ebx),%eax
		pushl	%eax
		movl	$1,%eax
		popl	%edx
		addl	%edx,%eax
		popl	%ebx
		movl	%eax,(%ebx)
		incl	i0
		jmp	for_start_LABEL3
for_end_LABEL5:
while_start_LABEL6:
		movl	i0,%eax
		pushl	%eax
		movl	$2,%eax
		popl	%edx
		cmpl	%eax,%edx
		movl	$1,%eax
		jg	j_LABEL8
		xorl	%eax,%eax
j_LABEL8:
		cmpl	$1,%eax
		jl	while_end_LABEL7
		leal	v519,%eax
		pushl	%eax
		movl	$1,%eax
		subl	$1,%eax
		movl	$4,%ecx
		imul	%ecx
		popl	%edx
		addl	%eax,%edx
		pushl	%edx
		leal	v519,%eax
		pushl	%eax
		movl	$1,%eax
		subl	$1,%eax
		movl	$4,%ecx
		imul	%ecx
		popl	%edx
		addl	%eax,%edx
		pushl	%edx
		popl	%ebx
		movl	(%ebx),%eax
		pushl	%eax
		movl	$1,%eax
		popl	%edx
		addl	%edx,%eax
		popl	%ebx
		movl	%eax,(%ebx)
		movl	i0,%eax
		pushl	%eax
		movl	$1,%eax
		popl	%edx
		subl	%eax,%edx
		movl	%edx,%eax
		movl	%eax,i0
		jmp	while_start_LABEL6
while_end_LABEL7:
repeat_LABEL9:
		leal	v519,%eax
		pushl	%eax
		movl	$1,%eax
		subl	$1,%eax
		movl	$4,%ecx
		imul	%ecx
		popl	%edx
		addl	%eax,%edx
		pushl	%edx
		leal	v519,%eax
		pushl	%eax
		movl	$1,%eax
		subl	$1,%eax
		movl	$4,%ecx
		imul	%ecx
		popl	%edx
		addl	%eax,%edx
		pushl	%edx
		popl	%ebx
		movl	(%ebx),%eax
		pushl	%eax
		movl	$1,%eax
		popl	%edx
		addl	%edx,%eax
		popl	%ebx
		movl	%eax,(%ebx)
		movl	i0,%eax
		pushl	%eax
		movl	$1,%eax
		popl	%edx
		addl	%edx,%eax
		movl	%eax,i0
		movl	i0,%eax
		pushl	%eax
		movl	16(%ebp),%eax
		popl	%edx
		cmpl	%eax,%edx
		movl	$1,%eax
		je	j_LABEL10
		xorl	%eax,%eax
j_LABEL10:
		cmpl	$0,%eax
		je	repeat_LABEL9
		leal	v519,%eax
		pushl	%eax
		movl	$1,%eax
		subl	$1,%eax
		movl	$4,%ecx
		imul	%ecx
		popl	%edx
		addl	%eax,%edx
		pushl	%edx
		popl	%ebx
		movl	(%ebx),%eax
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
		pushl	%eax
		movl	str_0,%eax
		pushl	%eax
		pushl	%ebp
		call	f222
		addl	$8,%esp
		movl	%eax,te20
		movl	te20,%eax
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
		.comm	v519,1024,4
		.comm	n21,4,4
		.comm	te20,4,4
		.comm	i0,4,4
