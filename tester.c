#include "printf.h"
#include <stdio.h>
#include <limits.h>

int     digit_tester();
int     int_tester();
int     str_tester();
int     test_perc();
int     char_tester();
int     unsint_tester();
int     hexl_tester();
int     hexu_tester();
int     ptr_tester();
int     skip_test();

int     digit_tester()
{
    printf("!!!!!DECIMAL TEST!!!!!\n");
    int boolean = 1;
    int test; int ft_test;
    int group[] = {INT32_MAX, INT32_MIN, 0, 522362};
    for (size_t i = 0; i < 4; i++)
    {
        test = printf("%d" ,group[i]);
        printf("\n");
        ft_test = ft_printf("%d", group[i]);
        if (test == ft_test)
            printf("\nOK\n");
        else
        {
            printf("\nKO\n");
            boolean = 0;
        }
    }
    return (boolean);
}

int     int_tester()
{
    printf("!!!!!INTEGER TEST!!!!!\n");
    int boolean = 1;
    int test; int ft_test;
    int group[] = {INT32_MAX, INT32_MIN, 0, 522362};
    for (size_t i = 0; i < 4; i++)
    {
        test = printf("%i" ,group[i]);
        printf("\n");
        ft_test = ft_printf("%i", group[i]);
        if (test == ft_test)
            printf("\nOK\n");
        else
        {
            printf("\nKO\n");
            boolean = 0;
        }
    }
    return (boolean);
}

int     str_tester()
{
    printf("!!!!!STRING TEST!!!!!\n");
    int boolean = 1;
    int test; int ft_test;
    char *group[] = {0 ,"", "Thisisit", "\t \t \n Kap", "\0 \n \t"};
    for (size_t i = 0; i < 5; i++)
    {
        test = printf("%s" ,group[i]);
        printf("\n");
        ft_test = ft_printf("%s", group[i]);
        printf("\n%d - %d\n", test, ft_test);
        if (test == ft_test)
            printf("\nOK\n");
        else
        {
            printf("\nKO\n");
            boolean = 0;
        }
    }
    return (boolean);
}

int     test_perc()
{
    printf("!!!!!PERCENTAGE TEST!!!!!\n");
    int boolean = 1;
    int test; int ft_test;
    char *group[] = {"%%", "this %d%%", "this %d%s%%%"};
    for (size_t i = 0; i < 3; i++)
    {
        test = printf("%s" ,group[i]);
        printf("\n");
        ft_test = ft_printf("%s", group[i]);
        if (test == ft_test)
            printf("\nOK\n");
        else
        {
            printf("\nKO\n");
            boolean = 0;
        }
    }
    return (boolean);
}

int     char_tester()
{
    printf("!!!!!CHARACTER TEST!!!!!\n");
    int boolean = 1;
    int test; int ft_test;
    char group[] = {'\n', 'd', '\0', ' ', 0};
    for (size_t i = 0; i < 5; i++)
    {
        test = printf("%c" ,group[i]);
        printf("\n");
        ft_test = ft_printf("%c", group[i]);
        if (test == ft_test)
            printf("\nOK\n");
        else
        {
            printf("\nKO\n");
            boolean = 0;
        }
    }
    return (boolean);
}

int     unsint_tester()
{
    printf("!!!!!UNSIGNED INTEGER TEST!!!!!\n");
    int boolean = 1;
    int test; int ft_test;
    unsigned int group[] = {4294967295, 4294967297, 0, 522362, -2};
    for (size_t i = 0; i < 5; i++)
    {
        test = printf("%u" ,group[i]);
        printf("\n");
        ft_test = ft_printf("%u", group[i]);
        if (test == ft_test)
            printf("\nOK\n");
        else
        {
            printf("\nKO\n");
            boolean = 0;
        }
    }
    return (boolean);
}

int     hexl_tester()
{
    printf("!!!!!LOWERCASE HEX TEST!!!!!\n");
    int boolean = 1;
    int test; int ft_test;
    int group[] = {INT32_MAX, INT32_MIN, 4294967295, 0, 522362, -5};
    for (size_t i = 0; i < 6; i++)
    {
        test = printf("%x", group[i]);
        printf("\n");
        ft_test = ft_printf("%x", group[i]);
        printf("\n%d - %d\n", test, ft_test);
        if (test == ft_test)
            printf("\nOK\n");
        else
        {
            printf("\nKO\n");
            boolean = 0;
        }
    }
    return (boolean);
}

int     hexu_tester()
{
    printf("!!!!!UPPERCASE HEX TEST!!!!!\n");
    int boolean = 1;
    int test; int ft_test;
    unsigned int group[] = {INT32_MAX, INT32_MIN, 4294967295, 0, 522362, -5};
    for (size_t i = 0; i < 6; i++)
    {
        test = printf("%X", group[i]);
        printf("\n");
        ft_test = ft_printf("%X", group[i]);
        printf("\n%d - %d\n", test, ft_test);
        if (test == ft_test)
            printf("\nOK\n");
        else
        {
            printf("\nKO\n");
            boolean = 0;
        }
    }
    return (boolean);
}

int     ptr_tester()
{
    printf("!!!!!POINTER TEST!!!!!\n");
    int boolean = 1;
    int test; int ft_test;
    int int_tothis = 29482;
    char *str = "ToThis";
    void *ptr = str;
    void *ptr2 = ptr;
    void *ptr3 = NULL;
    void *group[] = {ptr, ptr2, ptr3};
    for (size_t i = 0; i < 3; i++)
    {
        test = printf("%p", group[i]);
        printf("\n");
        ft_test = ft_printf("%p", group[i]);
        printf("\n%d - %d\n", test, ft_test);
        if (test == ft_test)
            printf("\nOK\n");
        else
        {
            printf("\nKO\n");
            boolean = 0;
        }
    }
    return (boolean);
}
/*
int     skip_test()
{
    int boolean = 1;
    int test; int ft_test;
    char *str = "This is text %%";
    int nbr = INT32_MAX;
    test = printf("%0-10.1824s ---- this is num %--0.32d", str, nbr) - 22;
    printf("\n");
    ft_test = ft_printf("%0-10.1824s ---- this is num %--0.32d", str, nbr);
    printf("\n%d - %d\n", test, ft_test);
    if (test == ft_test)
        printf("\nOK\n");
    else
    {
        printf("\nKO\n");
        boolean = 0;
    }
    return (boolean);
}
*/

int		main(void)
{
    int testgroup[] = {digit_tester(), str_tester(), test_perc(), char_tester(), int_tester(), unsint_tester(),
    hexl_tester(), hexu_tester(), ptr_tester()};
    for (size_t i = 0; i < 9; i++)
    {
        if (testgroup[i] == 1)
        printf("TEST: OK\n");
        else
        printf("TEST: FALSE\n");
    }
}
