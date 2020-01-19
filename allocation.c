/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 23:31:50 by waddam            #+#    #+#             */
/*   Updated: 2020/01/07 15:13:34 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		*alloc_qu(int len, t_lem *lem)
{
	int	*tmp;

	if (!(tmp = (int *)malloc(sizeof(int) * len)))
		leave();
	ft_memset(tmp, -1, sizeof(int) * len);
	lem->qu = tmp;
	return (tmp);
}

t_room	**alloc_rooms(t_lem *lem)
{
	int		i;
	t_room	**room;

	i = 0;
	if (!(room = (t_room **)malloc(sizeof(t_room *) * (lem->count_rooms + 1))))
		leave();
	while (i < (lem->count_rooms))
	{
		if (!(room[i] = (t_room *)malloc(sizeof(t_room))))
		{
			free_room(&room, i);
			leave();
		}
		init(room[i], sizeof(t_room));
		i++;
	}
	room[i] = NULL;
	return (room);
}

t_path	**alloc_path(int len, int count_rooms)
{
	int		i;
	t_path	**path;

	i = 0;
	if (!(path = (t_path **)malloc(sizeof(t_path *) * (len))))
		leave();
	while (i < len)
	{
		if (!(path[i] = (t_path *)malloc(sizeof(t_path))))
		{
			free_path(count_rooms, path, i);
			leave();
		}
		init(path[i], sizeof(t_path));
		path[i]->path = alloc_matrix(count_rooms, count_rooms);
		i++;
	}
	return (path);
}

int		**alloc_matrix(int x, int y)
{
	int		i;
	int		**matrix;

	i = 0;
	if (!(matrix = (int **)malloc(sizeof(int *) * (y + 1))))
		leave();
	while (i < (y + 1))
	{
		if (!(matrix[i] = (int *)malloc(sizeof(int) * (x + 1))))
		{
			free_matrix(&matrix, i);
			leave();
		}
		ft_memset(matrix[i], -1, sizeof(int) * (x + 1));
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}
