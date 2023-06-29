#include "main.h"

/**
 * is_printable - Will be used to  Evaluates if a char is printable
 * @c:  THIs is the Char to be evaluated.
 *
 * Return: 1 if c is printable else  0 
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Will be used to  Append ascci in hexadecimal code to buffer
 * @buffer: Is an array of chars.
 * @i:  THis is the index at which to start appending.
 * @ascii_code: THis is the  ASSCI CODE.
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit -Will be used to  Verifies if a char is a digit
 * @c:  This is the Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Will be used to  Casts a number to the specified size
 * @num: This is the  Number to be casted.
#include "main.h"

/**
 * is_printable -Will be used to  Evaluates if a char is printable
 * @c: This is the Char to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
OAOAOA */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
OAOAOA		return (1);

	return (0);
}


int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
OAOAOA	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
OAOAOA	buffer[i] = map_to[ascii_code % 16];

	return (3);
OAOAOA}

/**
 * is_digit -Will be used to  Verifies if a char is a digit
 * @c:  This is the Char to be evaluated
 *
OAOAOA * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number -USed to Casts a number to the specified size
 * @num:  Is the number to be casted.
 * @size: Is the Number indicating the type to be casted.
 *
 * Return:Will be the  Casted value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd -Will always Casts a number to the specified size
 * @num: Number to be casted
 * @size:Is  Number indicating the type to be casted
 *
 * Return: Will show Casted value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);
OAOAOA
	return ((unsigned int)num);
}
 
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - Will be used to  Casts a number to the specified size
 * @num:  Is the Number to be casted
 * @size:IS the  Number indicating the type to be casted
 *
 * Return:Will be  Casted value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}

