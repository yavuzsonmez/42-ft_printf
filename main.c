
#include <stdio.h>
#include "printf.h"

int main(void)
{
	int number = 54;
	char *str = "Bonjour";
	int *ptr;
	ptr = &number;

	int returnedprintf;
	int returnedft_printf;

	returnedft_printf = ft_printf("%5.4i %.s\n", 81, str);
	returnedprintf = 	printf("%5.4i %.s\n", 81, str);
	//printf("%d\n", returnedft_printf);
	printf("My return : %d\nPrintf return : %d\n", returnedft_printf, returnedprintf);
	return (0);
}

//returnedprintf = 	printf("%-3d %i %u %c %s %p %x %#X %-3%\n", 5, -1, 4294967, 'q', str, ptr, 4294967, 4294967);
