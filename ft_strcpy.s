section .text
	global ft_strcpy
	extern ft_strlen

ft_strcpy:
	push rdi
	mov rdi, rsi
	call ft_strlen
	mov rcx, rax
	pop rdi
	cld
	mov rax, rdi
	rep movsb
	mov BYTE [rdi], 0
	jmp .ret

.ret:
	ret
