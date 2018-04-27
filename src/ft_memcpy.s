;void	*ft_memcpy(void *restrict rdi, const void *restrict rsi, size_t rdx);


global _ft_memcpy
	section .text

_ft_memcpy:
	push rdi			; backup rdi qu'on va return dans rax à la fin
	cld					; kom dab
	mov rcx, rdx		; on move rdx (size) dans rcx paskeu rep check rcx
	rep movsb			; rep parcourt la chaine jusqu'à e que rcx == 0
						; movsb -> ES:DI, DS:SI c'est majik com instruction

end:
	pop rax
	ret