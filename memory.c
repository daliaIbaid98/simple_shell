#include "shell.h"

/**
 * bfree - Free a pointer and NULLify the address
 * @ptr: Address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0
 */

int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
