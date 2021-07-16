
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

	returnedft_printf = ft_printf("% d\n", -22);
	returnedprintf = 	printf("% d\n", -22);
	//printf("%d\n", returnedft_printf);
	printf("My return : %d\nPrintf return : %d\n", returnedft_printf, returnedprintf);
	return (0);
}
