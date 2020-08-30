segment .text
	global ft_write
	extern __errno_location

ft_write:
	mov r8, rdx
	mov rax, 1
	syscall
	cmp rax, 0
	jl .error
	mov rax, r8
	ret

.error:
	push rax
	call __errno_location
	pop rbx
	neg rbx
	mov [rax], rbx
	mov rax, -1
	ret
