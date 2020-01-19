/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:13:44 by dmorar            #+#    #+#             */
/*   Updated: 2020/01/07 15:13:47 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	check_len_path(t_path *path)
{
	if (path->j > 100)
	{
		path_overwrite(path->i, path);
		path->i--;
		return (1);
	}
	return (0);
}

static void	start_check_path(t_path *path, t_lem *lem)
{
	path->j = 0;
	lem->str = lem->count_rooms - 1;
	path->path[path->i][path->j] = lem->str;
	path->j++;
}

static void	check_2(t_lem *lem, int **sets, t_path *path, t_room **room)
{
	lem->str = next_link_2(sets[lem->str], lem, room);
	path->path[path->i][path->j] = lem->str;
	del_link(sets, path->path[path->i][path->j - 1],
	path->path[path->i][path->j]);
	path->j++;
}

static void	check_3(t_lem *lem, int **sets, t_path *path)
{
	path->j--;
	lem->str = path->path[path->i][path->j];
	path->path[path->i][path->j + 1] = -1;
	if (units_present(sets[lem->str]) == 1)
		path->j++;
}

int			check_path_2(t_room **room, int **sets, t_lem *lem, t_path *path)
{
	start_check_path(path, lem);
	if (check_1(sets, lem, path) == 0)
		return (0);
	while (lem->str != 0)
	{
		if (check_len_path(path) == 1)
			return (1);
		if (units_present(sets[lem->str]) == 1)
		{
			check_2(lem, sets, path, room);
			continue ;
		}
		else
		{
			if (lem->str == lem->count_rooms - 1)
			{
				path->path[path->i][0] = -1;
				return (0);
			}
			else
				check_3(lem, sets, path);
		}
	}
	return (1);
}
