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
int 	ft_puts( char* rdi);

/* PART 2 */
size_t	ft_strlen(const char *s);

void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
char	*ft_strdup(const char *s1);

/* PART 3*/
int 	ft_cat(int fd);

/* BONUS */
int		ft_isupper(int c);
int		ft_islower(int c);
size_t	ft_strlen2(const char *s); // ?



#define max 401
#define min -max

/*
** On linux (or at least bash for windows with ubuntu), the libc does segfault with non chars even if man says it can takes int
*/

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

void checkintegrity(char *str1, char* str2, int testid)
{
	int i = 0;
	while (i < 500)
	{
		if (str1[i] != str2[i])
		{
			printf("Integrity Fail for text #%i on char #%i\n", testid, i);
			break;
		}
		i++;
	}

}




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
	checkintegrity(str, str2, 1);

	////////////////////////////// ISALPHA//////////////////////////////
	i = min;
	while (i < max)
	{
		if (isalpha(i) != ft_isalpha(i))
			printf("\e[31mFail on ft_isalpha(%i) expected : 0x%08x  but got 0x%08x \n\e[0m", i, isalpha(i) , ft_isascii(i));
		i++;
	}
	printf("%s\n", "Finished test for ft_isalpha");
	checkintegrity(str, str2, 2);

	////////////////////////////////ISDIGIT///////////////////////////////
	i = min;
	while (i < max)
	{
		if (isdigit(i) != ft_isdigit(i))
			printf("\e[31mFail on ft_isdigit(%i) expected : 0x%08x  but got 0x%08x \n\e[0m", i, isdigit(i) , ft_isdigit(i));
		i++;
	}
	printf("%s\n", "Finished test for ft_isdigit");

	checkintegrity(str, str2, 3);
		//////////////////////////////////ISALNUM///////////////////////////
	i = min;
	while (i < max)
	{
		if (isalnum(i) != ft_isalnum(i))
			printf("\e[31mFail on ft_isalnum(%i) expected : 0x%08x  but got 0x%08x \n\e[0m", i, isalnum(i) , ft_isalnum(i));
		i++;
	}
	printf("%s\n", "Finished test for ft_isalnum");
	checkintegrity(str, str2, 4);
	////////////////////////////// ISASCII//////////////////////////////
	i = min;
	while (i < max)
	{
		if (isascii(i) != ft_isascii(i))
			printf("\e[31mFail on ft_isascii(%i) expected : 0x%08x  but got 0x%08x \n\e[0m", i, isascii(i) , ft_isascii(i));
		i++;
	}
	printf("%s\n", "Finished test for ft_isascii");

	checkintegrity(str, str2, 5);
	////////////////////////////// ISPRINT//////////////////////////////
	i = min;
	while (i < max)
	{
		if (isprint(i) != ft_isprint(i))
			printf("\e[31mFail on ft_isprint(%i) expected : 0x%08x  but got 0x%08x \n\e[0m", i, isprint(i) , ft_isprint(i));
		i++;
	}
	printf("%s\n", "Finished test for ft_isprint");

	checkintegrity(str, str2, 6);
	////////////////////////////// TOLOWER//////////////////////////////
	i = min;
	while (i < max)
	{
		if (tolower(i) != ft_tolower(i))
			printf("\e[31mFail on ft_tolower(%i) expected : 0x%08x  but got 0x%08x \n\e[0m", i, tolower(i) , ft_tolower(i));
		i++;
	}
	printf("%s\n", "Finished test for ft_tolower");
	checkintegrity(str, str2, 7);

	////////////////////////////// TOUPPER//////////////////////////////
	i = min;
	while (i < max)
	{
		if (toupper(i) != ft_toupper(i))
			printf("\e[31mFail on ft_toupper(%i) expected : 0x%08x  but got 0x%08x \n\e[0m", i, toupper(i) , ft_toupper(i));
		i++;
	}
	printf("%s\n", "Finished test for ft_toupper");
	checkintegrity(str, str2, 8);



	//////////////////////////////ISUPPER//////////////////////////////
	i = min;
	while (i < max)
	{
		if (isupper(i) != ft_isupper(i))
			printf("\e[31mFail on ft_isupper(%i) expected : 0x%08x  but got 0x%08x \n\e[0m", i, isupper(i) , ft_isupper(i));
		i++;
	}
	printf("%s\n", "Finished test for ft_isupper");
	checkintegrity(str, str2, 9);

	//////////////////////////////ISLOWER//////////////////////////////
	i = min;
	while (i < max)
	{
		if (islower(i) != ft_islower(i))
			printf("\e[31mFail on ft_islower(%i) expected : 0x%08x  but got 0x%08x \n\e[0m", i, islower(i) , ft_islower(i));
		i++;
	}
	printf("%s\n", "Finished test for ft_islower");
	checkintegrity(str, str2, 10);


	//////////////////////////////STRLEN//////////////////////////////
	i = 0;

	while (i < 500)
	{
		fill_with_shit(str,i);
		fill_with_shit(str2,i); // only used for integrity
		if (strlen(str) != ft_strlen(str))
			printf("\e[31mFail on ft_strlen(%i) expected : %lu  but got %lu n\e[0m", i, strlen(str) , ft_strlen(str));
		i++;
	}
	printf("%s\n", "Finished test for ft_strlen");
	checkintegrity(str, str2, 11);

		//////////////////////////////STRLEN2//////////////////////////////
	i = 0;

	while (i < 500)
	{
		fill_with_shit(str,i);
		fill_with_shit(str2,i); // only used for integrity
		if (strlen(str) != ft_strlen2(str))
			printf("\e[31mFail on ft_strlen2(%i) expected : %lu  but got %lu n\e[0m", i, strlen(str) , ft_strlen2(str));
		i++;
	}
	printf("%s\n", "Finished test for ft_strlen2");
	checkintegrity(str, str2, 11);


	//////////////////////////////MEMSET//////////////////////////////
	i = 2;

		fill_with_shit(str,500);
		fill_with_shit(str2,500);

	while (i < 127)
	{

		memset((void*)str, i/2, i/2);
		memset((void*)str2, i/2, i/2);

		int ibite = 0;
		while (ibite < i)
		{
			if (str[ibite] != str2[ibite])
			{
				failed = true;
				printf("\e[31mMemset failed on char #%i expected %c but got %c\n\e[0m",ibite, str[ibite], str2[ibite] );
			}
			ibite++;
		}


		i++;
	}
	printf("%s\n", "Finished test for ft_memset");
	checkintegrity(str, str2, 12);

	//////////////////////////////MEMCPY//////////////////////////////
	i = 10;

		fill_with_shit(str,500);
		fill_with_shit(str2,500);
		char bite[] = "sdfjas;dfjas; dfjasdkfaj sd;fasd.cas;l asdf apeuw89e4ry twero97tqe9rfhqlsd;adf/a.sdfa sdWDWEF ";
		int max1 = strlen(bite);

	while (i < max1)
	{


		memcpy(str, bite, i);
		ft_memcpy(str2, bite, i);

		int ibite = 0;
		while (ibite < i)
		{
			if (str[ibite] != str2[ibite])
			{
				failed = true;
				printf("\e[31mMemcpy failed on char #%i expected %c but got %c\n\e[0m",ibite, str[ibite], str2[ibite] );
			}
			ibite++;
		}

		i++;

	}
	printf("%s\n", "Finished test for ft_memcpy");
	checkintegrity(str, str2, 13);

	//////////////////////////////STRDUP//////////////////////////////


	while (i < max)
	{
		char ololmdr[] = "QUELAUN AURAY VU MA BROSS A DEN?????????????????";
		char *bitoe = ft_strdup(ololmdr);
		if (strcmp(strdup(ololmdr), bitoe) != 0)
			printf("%s\n", "fail sur ft_strdup");
		if (bitoe[strlen(ololmdr)] != 0)
			printf("%s %c\n", "end of it is not 0, expected 0, got ", bitoe[strlen(ololmdr)]);
	
		i++;
	}



	printf("%s\n", "Finished test for ft_strdup");
	printf("%s\n", "Les lignes suivantes sont-elles identiques ?");
	char olol[] = "mdr                                                                     ";
	puts(olol);
	ft_puts(olol);

	char olol2[] = "sdfjsdfj;asdfja;sdjfapiwejfp[iwejfpad;zsdz;'sdcz's;dfasdf4asd89fa4ds+fasdf";
	puts(olol2);
	ft_puts(olol2);


	char *olol5 = NULL;
	printf(	"Check return -> %i == %i ?\n", puts(olol5) ,ft_puts(olol5));


	printf("Batterie de tests nazis pour ft_cat avec des fd_bidon, de %i à %i puis avec des vrais fichiers\n",min, max);

	i = min;
	while (i < max)
	{

		
		if (i == 0 || i == 1 || i == 2)
			printf("Skipping file description %i cuz these values are taken by the system/shell \n",i );
		else
		{
			printf("Test fd = %i\n", i);
			ft_cat(i);
		}
		i++;
	}

	int biteo = open("libftasm.a", O_RDONLY);
	ft_cat(biteo);


	


	return (1);
}
