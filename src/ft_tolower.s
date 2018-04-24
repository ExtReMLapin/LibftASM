section .text
	global _ft_tolower

_ft_tolower:
	cmp rdi, 'A'	; if < 'A' then fuck off
	jl .false
	cmp rdi, 'Z'	; if > 'Z' then fuck off
	jg .false
	jmp .true

.false:
	mov rax, rdi	; return original letter
	ret

.true:
	add rdi, 32		; ret (rdi + 32)
	mov rax, rdi
	ret
