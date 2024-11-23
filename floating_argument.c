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

void print(va_list arg)
{
    printf("fp_offset :%d\n", arg->fp_offset);
    printf("gp_offset :%d\n", arg->gp_offset);
    printf("overflow_arg_area :%p\n", arg->overflow_arg_area);
    printf("reg_save_area : %p\n", arg->reg_save_area);
}

void foo(int max, ...)
{
    va_list arg;

    printf("Before (va_start):\n");
    print(arg);
    va_start(arg, max);
    printf("After (va_start):\n");
    print(arg);
    for (int i = 0; i < max; i++)
    {
        printf("----------------------------\n");
        printf("num = %.1f\n", va_arg(arg, double));
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
