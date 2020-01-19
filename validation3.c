/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 00:07:53 by waddam            #+#    #+#             */
/*   Updated: 2020/01/07 15:12:11 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	helper_1(char map_i, t_valid *val, int *i, int *fl)
{
	map_i == ' ' ? val->sp++ : val->hyp++;
	(*fl) = 0;
	(*i)++;
}

void	helper_2(t_valid *val, int *i, int *fl)
{
	val->name++;
	(*fl) = 1;
	(*i)++;
}

int		helper_3(char *map, t_valid *val, int *i)
{
	while (map[*i] != ' ')
	{
		if (ft_isdigit(map[*i]) == 1)
			(*i)++;
		else if (map[*i] == '\0' || ft_isdigit(map[*i]) == 0)
			return (0);
	}
	val->count_x++;
	return (-1);
}

int		helper_4(char *map, t_valid *val, int *i)
{
	while (map[*i] != '\0')
	{
		if (ft_isdigit(map[*i]) == 1)
			(*i)++;
		else
			return (0);
	}
	val->count_y++;
	return (-1);
}

int		helper_5(char *map, t_valid *val, int *i, int *fl)
{
	if (map[*i] == '#' || map[*i] == 'L')
		return (0);
	helper_1(map[*i], val, i, fl);
	return (-1);
}
