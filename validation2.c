/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 23:07:23 by waddam            #+#    #+#             */
/*   Updated: 2020/01/07 15:12:29 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	helpers(char *map, t_valid *val, int *i, int *fl)
{
	int		helper;

	helper = -1;
	if (map[*i] == ' ' || map[*i] == '-')
		helper_1(map[*i], val, i, fl);
	else if ((map[*i] != ' ' && (*fl) == 0 && val->name < 1)
		|| (map[*i] != '-' && (*fl) == 0 && val->name < 2 && val->hyp == 1))
		helper_2(val, i, fl);
	else if ((map[*i] != ' ' && map[*i] != '-') && (*fl) == 0 && val->sp == 1)
		helper = helper_3(map, val, i);
	else if ((map[*i] != ' ' && map[*i] != '-') && (*fl) == 0 && val->sp == 2)
		helper = helper_4(map, val, i);
	else if (val->name == 1 && (*fl) == 0
		&& (map[*i] != ' ' && map[*i] != '-') && val->hyp == 1)
		helper = helper_5(map, val, i, fl);
	else if ((map[*i] != ' ' && map[*i] != '-') && (*fl) == 1)
		(*i)++;
	else
		helper = 0;
	return (helper);
}

int			valid_str(char *map)
{
	int		i;
	int		fl;
	t_valid	val;

	i = 0;
	fl = 0;
	init(&val, sizeof(t_valid));
	if (map[0] == 'L')
		return (0);
	else if (map[0] == '#')
		return (3);
	while (map[i])
	{
		if (helpers(map, &val, &i, &fl) == 0)
			return (0);
	}
	if (val.sp == 2 && val.name == 1 && val.count_x == 1 && val.count_y == 1)
		return (4);
	else if (val.hyp == 1 && val.name == 2)
		return (5);
	else
		return (0);
}
