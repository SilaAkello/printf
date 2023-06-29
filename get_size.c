#include "main.h"

/**
 * get_size -  will be used to Calculates the size to cast the argument
 * @format:Will be  Formatted string in which to print the arguments
 * @i:  IS a List of arguments to be printed.
 *
 * Return: Will always show Precision.
 */
int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = S_LONG;
	else if (format[car_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (size);
}



