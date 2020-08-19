segment .text
	global ft_strcmp

ft_strcmp:
	mov	rax, 0
	jmp .while

.while:
	mov al, BYTE [rdi]
	mov bl, BYTE [rsi]
	cmp al, 0
	je .ret
	cmp bl, 0
	je .ret
	cmp al, bl
	jne .ret
	inc rdi
	inc rsi
	jmp .while

.ret:
	movzx rax, al
	movzx rbx, bl
	sub rax, rbx
	ret	
