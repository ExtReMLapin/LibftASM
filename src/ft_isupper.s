section .text
	global _ft_toupper

_ft_toupper:
	cmp rdi, 'a'	; if < 'a' then fuck off
	jl .false
	cmp rdi, 'z'	; if > 'z' then fuck off
	jg .false
	jmp .true

.false:
	mov rax, 0
	ret

.true:
	mov rax, 1
	ret
