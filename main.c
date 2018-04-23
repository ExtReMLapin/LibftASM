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





	////////////////////////////////STRCAT//////////////////////////////

	char str[] = "zzzzzZdfsZdasdfafsdfagdf sdfZgs dfgs dfgsdfgZZZZZZZZgs dfgZsdfg sdfsdgfgsdfgjfghjf6gh54654  ZZZ654 fg6s4f65g 4sdf56gZZZZZZZZZZZZZZZZZZZZZZZZZZZZ";
	char str2[] = "zzzzzZdfsZdasdfafsdfagdf sdfZgs dfgs dfgsdfgZZZZZZZZgs dfgZsdfg sdfsdgfgsdfgjfghjf6gh54654  ZZZ654 fg6s4f65g 4sdf56gZZZZZZZZZZZZZZZZZZZZZZZZZZZZ";
	i = strlen(str);
	int i2 = i;
	str[35]= '\0';
	str2[35] = '\0';

	char *_str = strcat(str, "fsdfdfasdfa");
	char *_str2 = ft_strcat(str2, "fsdfdfasdfa");

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

	printf("%s\n", "Finished test for ft_strcat");

	////////////////////////////// ISALPHA//////////////////////////////
	i = min;
	while (i < max)
	{
		if (isalpha(i) != ft_isalpha(i))
			printf("\e[31mFail on ft_isalpha(%i) expected : 0x%08x  but got 0x%08x \n\e[0m", i, isalpha(i) , ft_isascii(i));
		i++;
	}
	printf("%s\n", "Finished test for ft_isalpha");


	////////////////////////////////ISDIGIT///////////////////////////////
	i = min;
	while (i < max)
	{
		if (isdigit(i) != ft_isdigit(i))
			printf("\e[31mFail on ft_isdigit(%i) expected : 0x%08x  but got 0x%08x \n\e[0m", i, isdigit(i) , ft_isdigit(i));
		i++;
	}
	printf("%s\n", "Finished test for ft_isdigit");


		//////////////////////////////////ISALNUM///////////////////////////
	i = min;
	while (i < max)
	{
		if (isalnum(i) != ft_isalnum(i))
			printf("\e[31mFail on ft_isalnum(%i) expected : 0x%08x  but got 0x%08x \n\e[0m", i, isalnum(i) , ft_isalnum(i));
		i++;
	}
	printf("%s\n", "Finished test for ft_isalnum");

	////////////////////////////// ISASCII//////////////////////////////
	i = min;
	while (i < max)
	{
		if (isascii(i) != ft_isascii(i))
			printf("\e[31mFail on ft_isascii(%i) expected : 0x%08x  but got 0x%08x \n\e[0m", i, isascii(i) , ft_isascii(i));
		i++;
	}
	printf("%s\n", "Finished test for ft_isascii");


	////////////////////////////// ISPRINT//////////////////////////////
	i = min;
	while (i < max)
	{
		if (isprint(i) != ft_isprint(i))
			printf("\e[31mFail on ft_isprint(%i) expected : 0x%08x  but got 0x%08x \n\e[0m", i, isprint(i) , ft_isprint(i));
		i++;
	}
	printf("%s\n", "Finished test for ft_isprint");











	return (1);
}
