section .text
	global _ft_islower

_ft_islower:
	cmp rdi, 'A'	; if < 'A' then fuck off
	jl .false
	cmp rdi, 'Z'	; if > 'Z' then fuck off
	jg .false
	jmp .true

.false:
	mov rax, 0
	ret

.true:
	mov rax, 1
	ret
