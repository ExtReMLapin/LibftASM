section .text
	global _ft_isalpha

_ft_isalpha:
	cmp rdi, 'A' ; etc
	jl .false
	cmp rdi, '['
	jl .true
	cmp rdi, 'a'
	jl .false
	cmp rdi, '{'
	jl .true
	jmp .false ; sinon, rip false gros

.true:
	mov rax, 1
	ret

.false:
	mov rax, 0
	ret
