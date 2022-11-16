#include <stdio.h>
#include "ft_printf.h"
#include <stdio.h>


int main()
{
	char *str ="\n|| %10.5X ||\n";
    ft_printf(str,-1);
    printf(str,-1);
    //printf("%d   %s\n",ft_putnbr_base_originalTEST(BASE_X_min), BASE_X_min);
    return 0;
}