;void	*ft_memset(void *rdi, int rsi, size_t rdx);
global _ft_memset
	section .text

_ft_memset:
	cld 			; left to right, c'est une string quoi
	mov rcx, rdx
	mov r8, rdi		; backup rdi in r8
	mov rax, rsi	
	rep stosb		; repeat util rcx = zero, copy rax into cur
	mov rax, r8		; return rdi that was saved in r8
	ret
