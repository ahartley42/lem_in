#include "../includes/lem_in.h"
#include "../libft/libft.h"

int	check_int(char *s)
{
	char *tmp;

	if (!(tmp = ft_itoa(ft_atoi(s))))
		return (-1);
	if (!ft_strequ(tmp, s))
	{
		free(tmp);
		return (0);
	}
	free(tmp);
	return (1);
}
