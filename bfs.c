/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 13:35:36 by draudrau          #+#    #+#             */
/*   Updated: 2020/01/07 15:13:41 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			nul_fl(t_room **room, t_lem *lem)
{
	int i;

	i = 0;
	while (i < lem->count_rooms)
	{
		room[i]->fl = 0;
		room[i]->lvl = 0;
		i++;
	}
}

static int		check_empty(int *tmp, t_lem *lem)
{
	int i;

	i = 0;
	while (i < lem->count_rooms)
	{
		if (tmp[i] != -1)
			return (1);
		i++;
	}
	return (0);
}

static void		add_neighbors(int **sets, t_room **room, int *tmp)
{
	int i;
	int j;
	int k;
	int lvl;

	j = 0;
	k = 0;
	while (tmp[k] == -1)
		k++;
	i = tmp[k];
	lvl = room[i]->lvl + 1;
	while (tmp[k] != -1)
		k++;
	while (sets[i][j] != -1)
	{
		if (sets[i][j] >= 0 && sets[i][j] < BLOCK && room[sets[i][j]]->fl == 0)
		{
			room[sets[i][j]]->fl = 1;
			tmp[k] = sets[i][j];
			room[tmp[k]]->lvl = lvl;
			block_link(sets, i, j);
			k++;
		}
		j++;
	}
}

static void		del_left(int *tmp)
{
	int i;

	i = 0;
	while (tmp[i] == -1)
		i++;
	tmp[i] = -1;
}

void			bfs2(int **sets, t_lem *lem, t_room **room, int *tmp)
{
	int i;

	i = 0;
	tmp[0] = 0;
	while (check_empty(tmp, lem) != 0)
	{
		add_neighbors(sets, room, tmp);
		del_left(tmp);
		i++;
	}
}
