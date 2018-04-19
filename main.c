#include <stdio.h>
#include <string.h>

int ft_isascii(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
void ft_bzero(void *s, size_t n);
int	ft_strlen(const char *s);

int main(void)
{
	printf("isascii -1 %i\n", ft_isascii(-1));
	printf("isascii 4 %i\n", ft_isascii(4));
	printf("isascii 120 %i\n", ft_isascii(120));
	printf("isascii 128 %i\n", ft_isascii(128));

	printf("isdigit a %i\n", ft_isdigit('a'));
	printf("isdigit B %i\n", ft_isdigit('B'));
	printf("isdigit 0 %i\n", ft_isdigit('0'));
	printf("isdigit 9 %i\n", ft_isdigit('9'));
	printf("isdigit 5 %i\n", ft_isdigit('5'));

	printf("isalnum a %i\n", ft_isalnum('a'));
	printf("isalnum B %i\n", ft_isalnum('B'));
	printf("isalnum 0 %i\n", ft_isalnum('0'));
	printf("isalnum 9 %i\n", ft_isalnum('9'));
	printf("isalnum 5 %i\n", ft_isalnum('5'));
	printf("isalnum / %i\n", ft_isalnum('/'));
	printf("isalnum ! %i\n", ft_isalnum('!'));

	char d[] = "raaaa";

	printf("%s\n", d);

	ft_bzero(d, strlen(d));
	printf("%i\n", ft_strlen("lol425"));



	return (1);
}
