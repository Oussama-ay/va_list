/* **************************************************** */
/*   floating_argument.c                                */
/*                                                      */
/*       :::::     ::::::::    ::::::::    ::::::::     */
/*        :+:          :+:         :+:         :+:      */
/*       +:+          +:+         +:+         +:+       */
/*      +#+      ++:++#+     #++:++#         +#+        */
/*     +#+          +#+         +#+         +#+         */
/*    #+#         #+#         #+#         #+#           */
/*   ###      #######    #######        ###             */
/*                                                      */
/*   By: oayyoub <oayyoub@student.1337.ma>              */
/* **************************************************** */

#include <stdio.h>
#include <stdarg.h>

#define BLUE    "\x1b[34m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define RESET   "\x1b[0m"

void	print(va_list arg)
{
	printf("%sfp_offset: %d%s\n", BLUE, arg->fp_offset, RESET);
	printf("%sgp_offset: %d%s\n", BLUE, arg->gp_offset, RESET);
	printf("%soverflow_arg_area: %p%s\n", GREEN, arg->overflow_arg_area, RESET);
	printf("%sreg_save_area: %p%s\n", GREEN, arg->reg_save_area, RESET);
}

void	foo(int max, ...)
{
	va_list	arg;

	printf("%s=== Before (va_start): ===%s\n", YELLOW, RESET);
	print(arg);
	
	va_start(arg, max);
	printf("\n%s=== After (va_start): ===%s\n", YELLOW, RESET);
	print(arg);
	
	for (int i = 0; i < max; i++)
	{
		printf("\n%s=== Processing arg %d ===%s\n", YELLOW, i + 1, RESET);
		printf("Value = %.1f\n", va_arg(arg, double));
		print(arg);
	}
	va_end(arg);
}

int main()
{
    foo(18,
        1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0,
        11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0);
	return (0);
}
