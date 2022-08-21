global	_ft_strcmp

section	.text

_ft_strcmp:
	mov	rax, 0
	mov	rdx, 0

while:
	mov	al,	byte[rdi]
	mov	dl,	byte[rsi]
	sub	rax, rdx
	cmp	rax, 0
	jne	return
	cmp	byte[rdi], 0
	je	return
	inc	rdi
	inc	rsi
	jmp	while

return:
	ret