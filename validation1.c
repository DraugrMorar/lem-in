/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:11:29 by dmorar            #+#    #+#             */
/*   Updated: 2020/01/07 15:11:31 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	valid_ants(char **map, t_lem *lem)
{
	int		i;
	int		j;

	i = 0;
	while (map[i][0] == '#')
		i++;
	if (map[i][0] >= '1' && map[i][0] <= '9')
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (ft_isdigit(map[i][j]) == 1)
				j++;
			else
				leave();
		}
		lem->ants = ft_atoi(map[i]);
		if (lem->ants < 1)
			leave();
		i++;
		return (i);
	}
	leave();
	return (0);
}

static void	helper(char *map_i1, char *map_i2, t_lem *lem, int *i)
{
	if (map_i1[0] == '#')
	{
		lem->vld = valid_sharp(map_i1, lem);
		if (((lem->vld == 1 || lem->vld == 2) && (map_i2 != NULL)
			&& (valid_str(map_i2) == 4)) || lem->vld == 3)
			(*i)++;
		else if ((lem->vld == 1 || lem->vld == 2) && (map_i2 != NULL)
			&& valid_sharp(map_i2, lem))
			(*i)++;
		else
			leave();
	}
	else if (valid_str(map_i1) == 4)
	{
		lem->count_rooms++;
		(*i)++;
	}
	else if (valid_str(map_i1) == 5)
	{
		lem->links++;
		(*i)++;
	}
	else
		leave();
}

int			validation(char **map, t_lem *lem)
{
	int i;

	i = valid_ants(map, lem);
	while (map[i])
		helper(map[i], map[i + 1], lem, &i);
	if (lem->start == 1 && lem->end == 1 && lem->links > 0)
		return (1);
	else
		leave();
	return (0);
}

int			valid_sharp(char *map, t_lem *lem)
{
	int		i;

	i = 0;
	if (map == NULL)
		leave();
	else if (ft_strcmp(map, "##start") == 0)
	{
		lem->start++;
		return (1);
	}
	else if (ft_strcmp(map, "##end") == 0)
	{
		lem->end++;
		return (2);
	}
	else if (map[0] == '#' && map[1] != '\0')
		return (3);
	return (0);
}
