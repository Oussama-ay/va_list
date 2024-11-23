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
        printf("num = %d\n", va_arg(arg, int));
        print(arg);
    }
    va_end(arg);
}

int main()
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
