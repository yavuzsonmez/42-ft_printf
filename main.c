
#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";

	int returnedprintf;
	int returnedft_printf;

	returnedft_printf = ft_printf("%2.s,%2.s,%2.s,%2.s,%2.s\n", n, o, p, q, r);
	returnedprintf = 	printf("%2.s,%2.s,%2.s,%2.s,%2.s\n", n, o, p, q, r);
	//printf("%d\n", returnedft_printf);
	printf("My return : %d\nPrintf return : %d\n", returnedft_printf, returnedprintf);
	return (0);
}
