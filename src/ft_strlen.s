; size_t	ft_strlen(const char *s) ;

section .text
	global _ft_strlen


_ft_strlen:
					; repne bosse sur rcx
					; scasb compare al avec rdi et bouge rdi

					; scasb -> SCan A String Byte
					; rpne -> RePeat while Not Equal

					; s = rdi
    xor rcx, rcx	; rcx = 0 ; on utilise rcx et pas rbx car repne scasb agit dessus
    cmp rdi, 0x0 	; if (s == NULL)
    jz end			;	goto end
    				; juste pour le debut

    not rcx 		; rcx = ~rcx (rcx = -1)

    xor al, al		; al = 0 avant de loouuuupe
    cld				; faut pas de planter de sens roger

    ; while (*s (al) != '\0') s++; rcx--;
    repne scasb

    not rcx			; rcx = ~rcx
    dec rcx			; rcx--

end:
    ; ret = rcx
    mov rax, rcx
    ; return (ret)
    ret
    