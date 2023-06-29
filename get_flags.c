
#include "main.h"

/**
 * get_flags - Will be used to Calculates active flags
 * @format: This is the  Formatted string in which to print the arguments
 * @i: Will take a parameter.
 * Return: Will always show Flags:
 */
int get_flags(const char *format, int *i)
{
	
	/
	int j, car_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (car_i = *i + 1; format[car_i] != '\0'; car_i++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[car_i] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = car_i - 1;

	return (flags);
}

