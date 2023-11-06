#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

//leakcheck
__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}

int main()
{
	int	a;
	int	count;
	int	ftcount;
	char *str = "abcdef";

	a = 123456;
	count = printf("%x %X\n", a, a);
	ftcount = ft_printf("%x %X\n", a, a);

	printf("%i\n", a);
	ft_printf("%i\n", a);

	count = printf("address:%p/content:%s\n", str,str);
	ftcount = ft_printf("address:%p/content:%s\n", str,str);

	printf("%d\n", count);
	ft_printf("%d\n", ftcount);

	// printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%% %X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	// ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%% %X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);

	// count = printf("%u\n", a);
	// ftcount = ft_printf("%u\n", a);
	// printf("count:%d\n", count);
	// ft_printf("count:%d\n", ftcount);

	// printf("%X\n", a);
	// ft_printf("%X\n", a);

	// puts("countlen");
	// printf("%d\n", count);
	// ft_printf("%d\n", ftcount);

	// printf("%X\n", a);
	// ft_printf("%X\n", a);

	// count = printf("start%%correct\n");
	// ftcount = ft_printf("start%%correct\n");

	// puts("countlen");
	// printf("%d\n", count);
	// ft_printf("%d\n", ftcount);

}