
#include <stdio.h>
#include "printf.h"

int main(void)
{
	//int number = 54;
	//char *str = "Bonjour";
	//int *ptr;
	//ptr = &number;

	//int returnedprintf;
	int returnedft_printf;

	returnedft_printf = ft_printf("%d %u\n", 1, -50);
	//printf("%% %d\n", 56, 17);
	printf("%d\n", returnedft_printf);
	//printf("My return : %d\nPrintf return : %d\n", returnedft_printf, returnedprintf);

	return (0);
}
