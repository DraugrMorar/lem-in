/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 13:58:59 by draudrau          #+#    #+#             */
/*   Updated: 2020/01/07 15:13:59 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_write(char *map, t_room **room, int k)
{
	int co;

	co = 0;
	while (map[co] != ' ')
		co++;
	if (!(room[k]->name = ft_strnew(co)))
	{
		leave();
	}
	ft_strncpy(room[k]->name, map, co);
	room[k]->x = ft_atoi(&map[co]);
	co++;
	while (map[co] != ' ')
		co++;
	room[k]->y = ft_atoi(&map[co]);
}

void	unblock_link(int **sets, char sign)
{
	int i;
	int j;

	i = 0;
	while (sets[i][0] != -1)
	{
		j = 0;
		while (sets[i][j] != -1)
		{
			if (sets[i][j] < -1 && sign == '7')
				sets[i][j] = sets[i][j] + BLOCK;
			else if (sets[i][j] > BLOCK && sign == '9')
				sets[i][j] = sets[i][j] - BLOCK;
			j++;
		}
		i++;
	}
}
