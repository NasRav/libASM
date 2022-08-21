global	_ft_strcpy

section	.text

_ft_strcpy:
	mov	rax, rdi

while:
	mov	dl, byte[rsi]
	mov	byte[rdi], dl
	cmp	byte[rsi], 0
	je	return
	inc	rsi
	inc	rdi
	jmp	while

return:
	ret