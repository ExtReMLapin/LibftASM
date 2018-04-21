#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int _ft_isascii(int c);
int _ft_isdigit(int c);
int _ft_isalnum(int c);
void _ft_bzero(void *s, size_t n);
int	_ft_strlen(const char *s);
int	_ft_isprint(int c);

#define min -5000
#define max 1300

int main(void)
{



	int i = min;
	while (i < max)
	{
		if ((bool)isascii(i) != (bool)_ft_isascii(i))
			printf("Fail on ft_isascii(%i) expected : 0x%08x  but got 0x%08x \n", i, (bool)isascii(i) , (bool)_ft_isascii(i));
		i++;
	}
	printf("%s\n", "Finished test for ft_isascii");


	i = min;
	while (i < max)
	{
		if ((bool)isprint(i) != (bool)_ft_isprint(i))
			printf("Fail on ft_isprint(%i) expected : 0x%08x  but got 0x%08x \n", i, isprint(i) , _ft_isprint(i));
		i++;
	}
	printf("%s\n", "Finished test for ft_isprint");

	return (1);
}
