#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

void	MoveCharsToLeft(char **str)
{
	int		i = 0;
	char	*ptr = *str;
	
	while (ptr[i] != '\0')
	{
		ptr[i] = ptr[i + 1];
		i++;
	}
}

void	FixFormatting(char **str)
{
	char	*pt			= *str;

	/*cleanup if exp == 0*/
	if ((pt = strchr(pt, 'e')) != NULL && atoi(pt + 2) == 0)
		while (*pt != '\0')
			*(pt++) = '\0';
	/*+ sign and useless zeros in exp*/
	if (pt && *pt != '\0')
	{
		pt++;
		if (*pt == '-')
			pt++;
		while (*pt == '+' || *pt == '0')
			MoveCharsToLeft(&pt);
	}
	/*cleanup trailing zeros in floating number*/
	pt = *str;
	while (*(pt + 1) != 'e' && *(pt + 1) != '\0')
		pt++;
	while (*pt == '0')
	{
		MoveCharsToLeft(&pt);
		pt--;
	}
	if (*pt == '.')
		MoveCharsToLeft(&pt);
}

char	*DoubleToScientificNotation(double number, int type)
{
	char	*out = NULL;
	size_t	out_size = 0;
	if (type == 0)
	{
	/*scientific notation*/
		out_size = snprintf(out, 0, "%.12e", number) + 1;
		if (!(out = malloc(sizeof(*out) * (out_size))))
			return (NULL);
		bzero (out, out_size);
		snprintf(out, out_size, "%.12e", number);
		FixFormatting(&out);
	}
	else
	{
	/*Standard notation*/
		out_size = snprintf(out, 0, "%f", number) + 1;
		if (!(out = malloc(sizeof(*out) * (out_size))))
			return (NULL);
		bzero (out, out_size);
		snprintf(out, out_size, "%f", number);
		FixFormatting(&out);
	}
	return (out);
}
