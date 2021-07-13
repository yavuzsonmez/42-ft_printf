
#include <stdio.h>
#include "printf.h"

int main(void)
{
	//int number = 54;
	//char *str = "Bonjour";
	//int *ptr;

	int returnedprintf;
	int returnedft_printf;

	//ptr = &number;

	returnedft_printf = ft_printf("%d\n", 56);
	returnedprintf = printf("%d\n", 56);
	//printf("%d\n", returnedft_printf);
	printf("My return : %d\nPrintf return : %d\n", returnedft_printf, returnedprintf);

	return (0);
}
