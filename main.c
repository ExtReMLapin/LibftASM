#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/* PART 1 */
void	ft_bzero(void *s, size_t n);
char	*ft_strcat(char *restrict s1, const char *restrict s2);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
4
/* PART 2 */
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
char	*strdup(const char *s1);

/* PART 3*/

/* BONUS */
int		ft_isupper(int c);
int		ft_islower(int c);


#define min -4660
#define max 4661

static void fill_with_shit(char *str, size_t size)
{
        size_t i = 0;
        while (i < size)
        {
                str[i] = 33 + (i*2)%94;
                i++;
        }
        str[i] = 0;
}





#ifdef __linux__ // c dégeu mé osef
	void _ft_bzero(void *s, size_t n);
	char *_ft_strcat(char *restrict s1, const char *restrict s2);
	int _ft_isalpha(int c);
	int _ft_isdigit(int c);
	int _ft_isalnum(int c);
	int _ft_isascii(int c);
	int	_ft_isprint(int c);
	int _ft_toupper(int c);
	int _ft_tolower(int c);
	int _ft_isupper(int c);
	int _ft_islower(int c);

	size_t	ft_strlen(const char *s)
	{
		return _ft_strlen(s);
	}

	void ft_bzero(void *s, size_t n)
	{
		return _ft_bzero(s, n);
	}

	char *ft_strcat(char *restrict s1, const char *restrict s2)
	{
		return (_ft_strcat(s1, s2));
	}

	int ft_isalpha(int c)
	{
		return (_ft_isalpha(c));
	}

	int ft_isdigit(int c)
	{
		return (_ft_isdigit(c));
	}

	int ft_isalnum(int c)
	{
		return (_ft_isalnum(c));
	}

	int ft_isascii(int c)
	{
		return (_ft_isascii(c));
	}

	int	ft_isprint(int c)
	{
		return (_ft_isprint(c));
	}

	int ft_toupper(int c)
	{
		return (_ft_toupper(c));
	}

	int ft_tolower(int c)
	{
		return (_ft_tolower(c));
	}

	int ft_isupper(int c)
	{
		return (_ft_isupper(c));
	}

	int ft_islower(int c)
	{
		return (_ft_islower(c));
	}
#endif






int main(void)
{






	int i;

	////////////////////////////////STRCAT//////////////////////////////

	char *str = (char*)malloc(sizeof(char)*501);
	char *str2 = (char*)malloc(sizeof(char)*501);
	fill_with_shit(str, 501);
	fill_with_shit(str2, 501);
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


	////////////////////////////// TOLOWER//////////////////////////////
	i = min;
	while (i < max)
	{
		if (tolower(i) != ft_tolower(i))
			printf("\e[31mFail on ft_tolower(%i) expected : 0x%08x  but got 0x%08x \n\e[0m", i, tolower(i) , ft_tolower(i));
		i++;
	}
	printf("%s\n", "Finished test for ft_tolower");


	////////////////////////////// TOUPPER//////////////////////////////
	i = min;
	while (i < max)
	{
		if (toupper(i) != ft_toupper(i))
			printf("\e[31mFail on ft_toupper(%i) expected : 0x%08x  but got 0x%08x \n\e[0m", i, toupper(i) , ft_toupper(i));
		i++;
	}
	printf("%s\n", "Finished test for ft_toupper");




	//////////////////////////////ISUPPER//////////////////////////////
	i = min;
	while (i < max)
	{
		if (isupper(i) != ft_isupper(i))
			printf("\e[31mFail on ft_isupper(%i) expected : 0x%08x  but got 0x%08x \n\e[0m", i, isupper(i) , ft_isupper(i));
		i++;
	}
	printf("%s\n", "Finished test for ft_isupper");

		//////////////////////////////ISLOWER//////////////////////////////
	i = min;
	while (i < max)
	{
		if (islower(i) != ft_islower(i))
			printf("\e[31mFail on ft_islower(%i) expected : 0x%08x  but got 0x%08x \n\e[0m", i, islower(i) , ft_islower(i));
		i++;
	}
	printf("%s\n", "Finished test for ft_islower");

	i = 0;

	while (i < 500)
	{
		fill_with_shit(str,i);
		if (strlen(str) != ft_strlen(str))
			printf("\e[31mFail on ft_strlen(%i) expected : %lu  but got %lu n\e[0m", i, strlen(str) , ft_strlen(str));
		i++;
	}
	printf("%s\n", "Finished test for ft_strlen");




	return (1);
}
