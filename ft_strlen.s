section .text
	global ft_strlen

ft_strlen:
	push rcx
	xor rcx, rcx

.while:
	cmp [rdi], byte 0
	jz .ret
	inc	rcx
	inc	rdi
	jmp .while

.ret:
	mov rax, rcx
	pop rcx
	ret
