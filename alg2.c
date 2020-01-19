/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:54:05 by draudrau          #+#    #+#             */
/*   Updated: 2020/01/07 15:13:54 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	path_overwrite(int i, t_path *path)
{
	int j;

	j = 0;
	while (path->path[i][j] > -1)
	{
		path->path[i][j] = -1;
		j++;
	}
}

int		check_1(int **sets, t_lem *lem, t_path *path)
{
	if (units_present(sets[0]) == 0 ||
	units_present(sets[lem->count_rooms - 1]) == 0)
	{
		path->path[path->i][0] = -1;
		return (0);
	}
	return (1);
}

int		next_link_2(int *str, t_lem *lem, t_room **room)
{
	int j;
	int tmp;
	int lvl;

	j = 0;
	lem->fl = 0;
	while (str[j] != -1)
	{
		if (str[j] >= 0 && str[j] < BLOCK)
		{
			if (lem->fl == 0)
			{
				tmp = str[j];
				lvl = room[str[j]]->lvl;
				lem->fl = 1;
			}
			else if (lem->fl == 1 && (room[str[j]]->lvl) < lvl)
			{
				tmp = str[j];
				lvl = room[str[j]]->lvl;
			}
		}
		j++;
	}
	return (tmp);
}

int		units_present(int *str)
{
	int i;

	i = 0;
	while (str[i] != -1)
	{
		if (str[i] >= 0 && str[i] < BLOCK)
			return (1);
		else
			i++;
	}
	return (0);
}

int		*first_path(t_path *path, t_room **room, t_lem *lem, int **sets)
{
	path->i = -1;
	while (1)
	{
		path->i++;
		path->j = 0;
		if (check_path_2(room, sets, lem, path) == 0)
			break ;
		nul_fl(room, lem);
		bfs2(sets, lem, room, lem->qu);
		unblock_link(sets, '7');
	}
	count_iter(path, lem);
	unblock_all(sets);
	return (path->path[0]);
}
