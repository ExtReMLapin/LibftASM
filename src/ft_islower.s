section .text
	global _ft_islower

_ft_islower:
	cmp rdi, 'a'	; if < 'A' then fuck off
	jl .false
	cmp rdi, 'a'	; if > 'Z' then fuck off
	jg .false
	jmp .true

.false:
	mov rax, 0
	ret

.true:
	mov rax, 1
	ret
