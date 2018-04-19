; char *strcat(char *restrict s1, const char *restrict s2);

;char	*ft_strcat(char *s1, const char *s2)
;{
;	int	i;
;	int	j;
;
;	i = 0;
;	j = 0;
;	while (s1[i] != '\0')
;		i++;
;	while (s2[j] != '\0')
;	{
;		s1[i] = s2[j];
;		j++;
;		i++;
;	}
;	s1[i] = '\0';
;	return (s1);
;}
section .text
	global _ft_strcat


_ft_strcat:
	