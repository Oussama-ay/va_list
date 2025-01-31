/* **************************************************** */
/*   general_argument.c                                 */
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
		printf("Value = %d\n", va_arg(arg, int));
		print(arg);
	}
	va_end(arg);
}

int	main()
{
	foo(60,
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
		11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
		21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
		31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
		41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
		51, 52, 53, 54, 55, 56, 57, 58, 59, 60);
	return (0);
}
