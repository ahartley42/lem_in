#include "../includes/lem_in.h"

unsigned char	rinit(char **cmd, int *x, t_base *base, unsigned char e)
{
	int	i;
	int	j;
	int	k;

	i = *x;
	j = 0;
	k = 0;
	while (cmd[i])
	{
		j = 0;
		if (cmd[i][0] == '#')
		{
			if (strequ(cmd[i], "##start"))
				(*base)->r |= 4;
			if (strequ(cmd[i], "##end"))
				(*base)->r |= 2;
			if (((*base)->r & 6) = 6)
				return (e | 64);
			i++;
		}
		(*base)->id = ++k;
		(*base)->name = NULL; //test
		(*base) = (*base)->next;
	}
	return (e);
}

unsigned char	pinit(char **cmd, int *x, t_base *base, unsigned char e)
{
	int	i;
	int	j;
	int	k;

	i = *x;
	j = 0;
	k = 0;
	while (cmd[i])
	{
		j = 0;
		if (cmd[i][0] == '#')
		{
			if (strequ(cmd[i], "##start") || strequ(cmd[i], "##end"))
				return (e | 64);
			i++;
		}
		(*base)->id = ++k;
		(*base)->name = NULL; //test
		(*base) = (*base)->next;
	}
	return (e);
}

unsigned char	init(char **cmd, t_base *base, unsigned char e)
{
	int	i;

	i = 0;
	while (cmd[i][0] == '#')
	{
		if (strequ(cmd[i], "##start") || strequ(cmd[i], "##end"))
			return (e | 128);
		i++;
	}
	if (check_int(cmd[i]) < 1)
		return (e | 128);
	else
		(*base)->ants = ft_atoi(cmd[i]);
	e = rinit(cmd, &i, base, e);
	e = pinit(cmd, &i, base, e);
	return (e);
}
