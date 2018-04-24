section .text
	global _ft_isdigit

_ft_isdigit:
	cmp rdi, '0' ; if rdi < 48 then fail
	jl .false 
	cmp rdi, '9' ; if rdi > 57 then fail
	jg .false
	jmp .true ; if two other conditions were not triggered then return true

.true:
	mov rax, 1
	ret

.false:
	mov rax, 0
	ret

