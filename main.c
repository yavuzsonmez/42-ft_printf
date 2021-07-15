
#include <stdio.h>
#include "printf.h"

int main(void)
{
	int number = 54;
	char *str = "This is text %%";
	int *ptr;
	ptr = &number;

	int returnedprintf;
	int returnedft_printf;

	returnedft_printf = ft_printf("%0-10.3s ---- this is num %--0.32d\n", str, number);
	returnedprintf = 	printf("%0-10.3s ---- this is num %--0.32d\n", str, number);
	//printf("%d\n", returnedft_printf);
	printf("My return : %d\nPrintf return : %d\n", returnedft_printf, returnedprintf);
	return (0);
}

//returnedprintf = 	printf("%-3d %i %u %c %s %p %x %#X %-3%\n", 5, -1, 4294967, 'q', str, ptr, 4294967, 4294967);


//%.1d 0
//%2.d 0


//("%0-10.1824s ---- this is num %--0.32d", "This is text %%", 2147483647);
//ft_printf("%1.1d\n", 0);
//returnedft_printf = ft_printf("%12.12i\n", -42);
