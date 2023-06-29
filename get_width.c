#include "main.h"

/**
 * get_width - THis one Calculates the width for printing
 * @format: THis is the Formatted string in which to print the arguments.
 * @i:  THis is the List of arguments to be printed.
 *
 * Return:Will always show the width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int car_i;
	int width = 0;

	for (car_i = *i + 1; format[car_i] != '\0'; car_i++)
	{
		if (is_digit(format[car_i]))
		{
			width *= 10;
			width += format[car_i] - '0';
		}
		else if (format[car_i] == '*')
		{
			car_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = car_i - 1;

	return (width);
}


