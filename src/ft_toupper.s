section .text
	global _ft_toupper

_ft_toupper:
	cmp rdi, 'a'	; if < 'a' then fuck off
	jl .false
	cmp rdi, 'z'	; if > 'z' then fuck off
	jg .false
	jmp .true

.false:
	mov rax, rdi	; return original letter
	ret

.true:
	sub rdi, 32		; ret (rdi - 32)
	mov rax, rdi
	ret
