sys_call_id = 0x80
exit_syscall = 0x1


.global _start
_start:
		call _main
		movl $0,%ebx
		movl $exit_syscall,%eax
		int $sys_call_id
