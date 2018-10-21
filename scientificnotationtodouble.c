#include <ctype.h>
#include <math.h>
#include <stdio.h>

double	MyAtof(char *str, int *main_cpt)
{
	double	result	= 0.;
	double	div		= 10.;
	int		neg		= 1;
	int		cpt		= *main_cpt;

	if (str[cpt] == '-')
	{
		neg = -1;
		cpt++;
	}
	else if (str[cpt] == '+')
		cpt++;
	while (isdigit(str[cpt]))
	{
		result *= 10;
		result += str[cpt++] - '0';
	}
	if ((str[cpt] == '.' || str[cpt] == ','))
	{
		cpt++;
		while (isdigit(str[cpt]))
		{
			result += (str[cpt] - '0') / div;
			div *= 10;
			cpt++;
		}
	}
	*main_cpt = cpt;
	return (result * neg);
}

double	PowerOfTen(char *str, int *main_cpt)
{
	double	out = 0.;
	int		cpt = *main_cpt;

	if (str[cpt] == 'e' || str[cpt] == 'E')
	{
		cpt++;
		*main_cpt = cpt;
		return (pow(10, MyAtof(str, main_cpt)));
	}
	return (1);
}

double	ScientificNotationToDouble(char *str)
{
	double	output	= 0.;
	int		cpt = 0;

	if (str == NULL)
		return (0.);
	output = MyAtof(str, &cpt);
	output *= PowerOfTen(str, &cpt);
	return (output);
}
