#include "../includes/lem_in.h"

void	error(unsigned char e)
{
	if (e)
	{
		write(1, "\e[31mERROR\n\e[0m", 15);
		exit(1);
	}
}
