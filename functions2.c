#include "main.h"

/******************WILL BE USED TO PRINT POINTER ******************/
/**
 * print_pointer -Will be used to  Prints the value of a pointer variable
 * @types: will be used to show  List  of arguments
 * @buffer: IS the Buffer array to handle print
 * @flags:  Will be used toCalculates active flags
 * @width: USed to get width
 * @precision: IS a  Precision specification
 * @size: Is a Size specifier
 * Return: IS the Number of chars printed.
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; 
	unsigned long num_addrs;
	char map_to[] = "0123456789cdefghi";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	ind++;


	return (write_pointer(buffer, ind, length,
		width, flags, padd, extra_c, padd_start));
}

/**
 * print_non_printable -Will be  used to  Prints ascii codes in hexa of non printable chars
 * @types: IS a list  of arguments
 * @buffer: IS the Buffer array to handle print
 * @flags:  Will be used to Calculates active flags
 * @width: is used to get width
 * @precision: IS a Precision specification
 * @size:is a  Size specifier
 * Return:IS the  Number of chars printed
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}


/**
 * print_reverse - Will be used to Prints reverse string.
 * @types: IS a  List of arguments
 * @buffer: Is the Buffer array to handle print
 * @flags: Will be used to  Calculates active flags
 * @width: Used to get width
 * @precision:Is the Precision specification
 * @size: IS the Size specifier
 * Return: IS theNumbers of chars printed
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int i, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/*************************HERE WE WILL BE  PRINTING A STRING IN ROT13 *************************/
/**
 * print_rot13string - Print a string in rot13.
 * @types: IS a  List of arguments
 * @buffer:  IS the Buffer array to handle print
 * @flags:   WILL be used to Calculates active flags
 * @width: WIll be used to get width
 * @precision: This is the Precision specification
 * @size: Here we have the Size specifier
 * Return:  IS the Numbers of chars printed
i */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}


