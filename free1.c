/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 12:55:47 by draudrau          #+#    #+#             */
/*   Updated: 2020/01/07 15:13:15 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		free_rooms(t_room **room, t_lem *lem)
{
	int i;

	i = 0;
	while (i < lem->count_rooms)
	{
		free(room[i]->name);
		free(room[i]);
		i++;
	}
	free(room);
}

static void		free_sets(int **sets, t_lem *lem)
{
	int i;

	i = 0;
	while (i < lem->count_rooms + 1)
	{
		free(sets[i]);
		i++;
	}
	free(sets);
}

static void		free_res_matrix(int **matrix, int iter)
{
	int i;

	i = 0;
	while (i < iter + 3)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void			free_map(char ***map)
{
	int i;

	i = 0;
	while ((*map)[i])
	{
		free((*map)[i]);
		i++;
	}
	free(*map);
}

void			result(t_path **path, t_lem *lem, t_room **room, char **map)
{
	int **matrix_res;

	reverse_path(path[lem->k]);
	put_ants_in_path(lem, path[lem->k]);
	matrix_res = create_res_matrix(lem, path[lem->k], path[lem->k]->res);
	print_res(matrix_res, lem, room, map);
	free_rooms(room, lem);
	free_res_matrix(matrix_res, path[lem->k]->res);
	free_path(lem->count_rooms + 1, path, 3);
	free_sets(lem->sets, lem);
}
