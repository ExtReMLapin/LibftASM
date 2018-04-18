section .text
	global _ft_isdigit

_ft_isdigit:
	cmp rdi, 48 ; if rdi < 48 then fail
	jl .false 
	cmp rdi, 57 ; if rdi > 57 then fail
	jg .false
	jmp .true ; if two other conditions were not triggered then return true

.true:
	mov rax, 1
	jmp .end

.false:
	mov rax, 0
	jmp .end

.end:
	ret
