;int	ft_isprint(int c)
;{
;	if ((c >= 32) && (c <= 126))
;		return (1);
;	return (0);
;}

section .text
	global _ft_isprint

_ft_isprint:
	cmp rdi, 32
	jl .false
	cmp rdi, 127 ; if rdi > 127 then fail
	jl .true
	jmp .false
.true:
	mov rax, 1
	ret

.false:
	mov rax, 0
	ret