#include <stdio.h>

/**
 * before_main - Prints a message before the main function is executed.
 */
void __attribute__((constructor)) before_main(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}

