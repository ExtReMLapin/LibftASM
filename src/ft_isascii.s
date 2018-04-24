section .text
	global _ft_isascii

_ft_isascii:
	cmp rdi, 0		; if rdi < 0 then fail
	jl .false 
	cmp rdi, 127	; if rdi > 127 then fail
	jg .false
	 				; implicit true

.true:
	mov rax, 1
	ret

.false:
	mov rax, 0
	ret