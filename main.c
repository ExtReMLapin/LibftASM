#include <stdio.h>

int ft_isascii(int c);


int main(void)
{
	printf("isascii -1 %i\n", ft_isascii(-1));
	printf("isascii 4 %i\n", ft_isascii(4));
	printf("isascii 120 %i\n", ft_isascii(120));
	printf("isascii 128 %i\n", ft_isascii(128));
	return (1);
}
