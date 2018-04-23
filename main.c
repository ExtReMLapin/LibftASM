#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void ft_bzero(void *s, size_t n);
char *ft_strcat(char *restrict s1, const char *restrict s2);
int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int ft_isascii(int c);
int	ft_isprint(int c);
int ft_toupper(int c);
int ft_tolower(int c);


int	ft_strlen(const char *s);


#define min -21474836
#define max 21474836

int main(void)
{

	int i;

	i = min;
	while (i < max)
	{
		if (isascii(i) != ft_isascii(i))
			printf("\e[31mFail on ft_isascii(%i) expected : 0x%08x  but got 0x%08x \n\e[0m", i, isascii(i) , ft_isascii(i));
		i++;
	}
	printf("%s\n", "Finished test for ft_isascii");


	i = min;
	while (i < max)
	{
		if (isdigit(i) != ft_isdigit(i))
			printf("\e[31mFail on ft_isdigit(%i) expected : 0x%08x  but got 0x%08x \n\e[0m", i, isdigit(i) , ft_isdigit(i));
		i++;
	}
	printf("%s\n", "Finished test for ft_isdigit");

	i = min;
	while (i < max)
	{
		if (isalnum(i) != ft_isalnum(i))
			printf("\e[31mFail on ft_isalnum(%i) expected : 0x%08x  but got 0x%08x \n\e[0m", i, isalnum(i) , ft_isalnum(i));
		i++;
	}
	printf("%s\n", "Finished test for ft_isalnum");


	char str[] = "QUEQU'UN AURAIT VU MA BROSSE A DENTS SVP ????";
	char str2[] = "QUEQU'UN AURAIT VU MA BROSSE A DENTS SVP ????";
	i = strlen(str);
	int i2 = i;
	str[10] = '\0';
	str2[10] = '\0';

	char *_str = strcat(str, "_");
	char *_str2 = ft_strcat(str2, "_");

	bool failed = false; // only print cmp of the two string if it failed
	while (i--) // not using strcmp because of the NULL char at pos 5
	{
		if (_str[i] != _str2[i])
		{
			failed = true;
			printf("\e[31mStrcat failed on char #%i expected %c but got %c\n\e[0m",i, _str[i], _str2[i] );
		}
	}

	if (failed)
	{
		i = 0;
		while (i < i2)
			write(1, &_str[i++], 1);
		i = 0;
		write(1, "\n", 1);
		while (i < i2)
			write(1, &_str2[i++], 1);
		write(1, "\n", 1);
	}

	printf("%s\n", "Finished test for strcat");

	return (1);
}
