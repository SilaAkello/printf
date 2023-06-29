#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - Will be used to  Prints an unsigned number
 * @types:  Showcase a list a of arguments
 * @buffer: is a  Buffer array to handle print
 * @flags:   Will be sed to Calculates active flags
 * @width: used to get width
 * @precision: Is a Precision specification
 * @size:  Is a Size specifier
 * Return:  Is a number of chars printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}


/**
 * print_octal - USed to  Prints an unsigned number in octal notation
 * @types: Will showcase a list of arguments
 * @buffer:  Is a Buffer array to handle print
 * @flags:   Will be used to Calculates active flags
 * @width: USed to get width
 * @precision:Is a  Precision specification
 * @size:This is the  Size specifier
 * Return:Will return the number of chars to be printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}


/**
 * print_hexadecimal -Will be used to  Prints an unsigned number in hexadecimal notation
 * @types: This is a list of arguments
 * @buffer: THis is a  Buffer array to handle print
 * @flags:  Used to Calculate active flags
 * @width: Used to get width
 * @precision: Is a Precision specification
 * @size:IS a  Size specifier
 * Return:IS the  Number of chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}


/**
 * print_hexa_upper -Will be used to  Prints an unsigned number in upper hexadecimal notation
 * @types: IS a List of arguments
 * @buffer: Is a Buffer array to handle print
 * @flags:  Used to Calculates active flags
 * @width: used to get width
 * @precision: Is a Precision specification
 * @size:  Is a Size specifier
 * Return: Will show number of chars printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hexa -USed to  Prints a hexadecimal number in lower or upper
 * @types: Is a list  of arguments
 * @map_to: An array of values to map the number to
 * @buffer:Is the  Buffer array to handle print
 * @flags:  USed to Calculate active flags
 * @flag_ch: USed to  Calculate active flags
 * @width:USed to  get width
 * @precision: Used as a Precision specification
 * @size: Is a Size specifier
 * Return:IS the  Number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

