section .text
	global _ft_isupper

_ft_isupper:
	cmp rdi, 'A'	; if < 'a' then fuck off
	jl .false
	cmp rdi, 'Z'	; if > 'z' then fuck off
	jg .false
	jmp .true

.false:
	mov rax, 0
	ret

.true:
	mov rax, 1
	ret
