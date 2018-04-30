
;int ft_puts( char* rdi)
; calling ssize_t write(int rdi, const void *rsi, size_t rdx);

section .data
	NL:			db	012o	; new line
	NULLSTR:	db	"(null)"; bein ui

section .text
	global _ft_puts
	extern _ft_strlen2
	extern _write

_ft_puts:
	enter 16, 0
	cmp rdi, 0 			; checking is rdi is null
	je .fail			; c'est un choix de considérer qu'il faut return un fail
	push rdi			; backup rdi cuz we never know
	call _ft_strlen2

	;priting the string sent as parameter
	mov rdi, 1			
	mov rdx, rax		; rdx = string length that was in parameter
	pop rsi				; rsi = string that was in ft_puts parameter
	call _write			; write(1, str, strlen(str))

	;now adding a \n at the and of the string
	mov rdi, 1			; \n len = 1 , amirite ???
	mov rdx, 1			; rdx = string length that was in parameter
	mov rsi, NL			; rsi = string that was in ft_puts parameter
	call _write			; write(1, str, strlen(str))


.success:
	mov rax, 10
	leave
	ret

.fail:
	;priting the string sent as parameter
	mov rdi, 1			
	mov rdx, 6			; rdx = string length that was in parameter
	mov rsi, NULLSTR	; rsi = string that was in ft_puts parameter
	call _write			; write(1, str, strlen(str))

	;now adding a \n at the and of the string
	mov rdi, 1			; \n len = 1 , amirite ???
	mov rdx, 1			; rdx = string length that was in parameter
	mov rsi, NL			; rsi = string that was in ft_puts parameter
	call _write			; write(1, str, strlen(str))

	mov rax, -1
	leave
	ret