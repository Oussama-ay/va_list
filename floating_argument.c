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
#define RED     "\x1b[31m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define WHITE   "\x1b[37m"
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
	printf("%s[NOTE: At this point, va_list is not initialized. Values shown are random memory.]%s\n", RED, RESET);
	
	getchar();
	va_start(arg, max);
	printf("\n%s=== After (va_start): ===%s\n", YELLOW, RESET);
	print(arg);
	printf("\n%sIn this part, fp_offset is initialized to 0, which marks the offset to access the first floating-point register in the register save area.\nThe gp_offset is initialized to 8, which is the offset to access the first general-purpose register in the register save area.%s\n", RED, RESET);
	printf("%sUnlike integer arguments, floating-point arguments are stored in XMM registers (from XMM0 to XMM7) on x86_64 systems.%s\n", RED, RESET);
	printf("%sThe reg_save_area points to a memory area containing copies of the registers, and overflow_arg_area points to the stack location where additional\narguments (beyond what fits in registers) are stored.%s\n", RED, RESET);
	getchar();
	
	for (int i = 0; i < max; i++)
	{
		printf("\n%s=== Processing arg %d ===%s\n", MAGENTA, i + 1, RESET);
		printf("%sValue = %s%.1f%s\n", CYAN, RED, va_arg(arg, double), RESET);
		print(arg);
		if (i == 0)
			printf("\n%s[NOTE: Notice how fp_offset increases by 16 bytes (size of XMM register) after each floating-point arg is processed]%s\n", YELLOW, RESET);
		else if (i == 7)
			printf("\n%s[NOTE: Notice how overflow_arg_area increases after each arg is processed, now that we've used all available XMM registers]%s\n", YELLOW, RESET);	
		getchar();
	
		if (i == 6)
		{
			printf(RED"\nIMPORTANT: Now after 8 floating-point arguments, we will switch to the stack!\n"RESET);
			printf(RED"On most x86_64 systems, the first 8 floating-point arguments use XMM registers,\nand any additional arguments will be passed on the stack via overflow_arg_area.%s\n", RESET);
			printf(RED"You'll notice that fp_offset will stop changing after this point\nand overflow_arg_area pointer will start to increment instead.%s\n", RESET);
			printf(RED"Press enter to continue\n"RESET);
			getchar();
		}
	}
	
	printf(GREEN"\nCleaning up with va_end to release any resources allocated by va_start\n"RESET);
	va_end(arg);
}

int	main()
{
	printf("%s*** In this program you will notice that for the first 8 arguments\nthe fp_offset increases as we access each floating-point argument through XMM registers.\nAfter that, we switch to accessing arguments from the stack via overflow_arg_area. ***%s\n\n", RED, RESET);
	printf("%s*** This demonstrates how variadic functions handle floating-point arguments ***%s\n", YELLOW, RESET);
	printf("%s*** Press Enter to start ***%s\n", GREEN, RESET);
	getchar();
	
	foo(18,
		1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0,
		11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0);
	
	printf("\n%s*** Demo completed successfully ***%s\n", GREEN, RESET);
	printf("%s*** Key learnings: ***%s\n", YELLOW, RESET);
	printf("%s1. va_start initializes the va_list structure with information about the argument layout%s\n", WHITE, RESET);
	printf("%s2. First 8 floating-point arguments (on x86_64) are passed in XMM registers%s\n", WHITE, RESET);
	printf("%s3. Additional floating-point arguments are passed on the stack via overflow_arg_area%s\n", WHITE, RESET);
	printf("%s4. fp_offset tracks our position in the floating-point registers and increases by 16 bytes per argument%s\n", WHITE, RESET);
	printf("%s5. va_arg correctly handles the switch from register to stack-based arguments%s\n", WHITE, RESET);
	printf("%s6. va_end cleans up any resources used by the va_list%s\n", WHITE, RESET);
	
	return (0);
}
