#include <limits.h>
#include <stdio.h>
#include "ft_printf.h"


int main()
{
	int i;
	//char *str = "%010.6d\n"; //does not act like flag 0 it act like width
	//char *str = "%-0.6d\n";  //it only activate pressision
	//char *str = "%.0d\n"    Any%;  //it only activate pressision
	// ft_printf("%14i%20i%2i%i", (int)-2147483648, 3, 30, -1);
	
	//tester 1
	//- d good x good
	//0 d good x good
	//. d good x good
	
	//tester 2
	//width d good x good
	//- d good x good
	//. d good x good
	//0 d good x good
	
	//i = ft_printf(str,(int)-2147483648);
	//
	//char *str = "%.4d%.2d%.20d%.0d%.0d%.d%.d%.d\n";
	char *str = "%.5d\n";

	i = ft_printf(str,0);
	printf("ft_printf: %d\n",i);
	printf("================\n");
	i = printf(str,0);
	printf("printf: %d\n",i);
	// printf("================\n");
	// i = ft_printf("%20d\n",69);
	// printf("result: %d\n",i);
	// i = printf("%20d\n",69);
	// printf("result: %d\n",i);
	// printf("\n================\n");
	// i = ft_printf("%020d\n",69);
	// printf("result: %d\n",i);
	// i = printf("%020d\n",69);
	// printf("result: %d\n",i);
	// printf("\n================\n");
	// i = ft_printf("%.20d\n",69);
	// printf("result: %d\n",i);
	// i = printf("%.20d\n",69);
	// printf("result: %d\n",i);
	// printf("\n================\n");
	// i = ft_printf("%-20d\n",69);
	// printf("result: %d\n",i);
	// i = printf("%-20d\n",69);
	// printf("result: %d\n",i);
	// printf("\n================\n");
	return 0;
}