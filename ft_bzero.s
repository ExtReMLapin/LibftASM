; ft_bzero( void *data, size_t n)
section	.text
	global _ft_bzero

_ft_bzero:
		mov	rbx, rdi		;rdi copy which is the value of void*
		mov	rcx, 0			; rcx is like i that will be compared to rbx which is n

.loop:
		cmp	rcx, rsi 		;checking if i == n
		je	.end			; if yes then break
		mov	byte [rbx], 0	; (*rbx) = 0
		inc	rbx				; *rbx++
		inc	rcx				; rcx++
		jmp	.loop			; while (true) // reloop

.end:
		ret					;return