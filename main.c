
#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int number = 54;
	char *str = "This is text %%";
	int *ptr;
	ptr = &number;

	int returnedprintf;
	int returnedft_printf;

	returnedft_printf = ft_printf("%.3d\n", -99);
	returnedprintf = 	printf("%.3d\n", -99);
	//printf("%d\n", returnedft_printf);
	printf("My return : %d\nPrintf return : %d\n", returnedft_printf, returnedprintf);
	return (0);
}
