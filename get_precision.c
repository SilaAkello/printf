#include "main.h"

/**
 * get_precision -Will be used to Calculates the precision for printing
 * @format: This is  the Formatted string in which to print the arguments
 * @i: Here is a list of arguments to be printed.
 * @list: THis is list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int car_i = *i + 1;
	int precision = -1;

	if (format[car_i] != '.')
		return (precision);

	precision = 0;

	for (car_i += 1; format[car_i] != '\0'; car_i++)
	{
		if (is_digit(format[car_i]))
		{
			precision *= 10;
			precision += format[car_i] - '0';
		}
		else if (format[car_i] == '*')
		{
			car_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = car_i - 1;

	return (precision);
}

