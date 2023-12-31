#include "shell.h"

/**
 * _custom_eputs - Print a given input string
 * @str: The string to be printed
 *
 * Return: Nothing
 */

void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _custom_eputchar - Write the character 'c' to stderr
 * @c: The character to print
 *
 * Return: On success, 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _custom_putfd - Write the character 'c' to the given file descriptor (fd)
 * @c: The character to print
 * @fd: The file descriptor to write to
 *
 * Return: On success, 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _custom_putsfd - Print a given input string to the specified file descriptor (fd)
 * @str: The string to be printed
 * @fd: The file descriptor to write to
 *
 * Return: The number of characters put
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
