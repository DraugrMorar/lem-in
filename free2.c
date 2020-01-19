/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 13:10:50 by draudrau          #+#    #+#             */
/*   Updated: 2020/01/07 15:11:40 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		free_room(t_room ***room, int i)
{
	while (--i >= 0)
	{
		free((*room)[i]);
		(*room)[i] = NULL;
	}
	free(*room);
	*room = NULL;
}

void		free_matrix(int ***matrix, int i)
{
	while (--i >= 0)
	{
		free((*matrix)[i]);
		(*matrix)[i] = NULL;
	}
	free(*matrix);
	*matrix = NULL;
}

static void	free_matrix_i(int **matrix, int len)
{
	int i;

	i = 0;
	while (i <= len)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void		free_path(int count, t_path **path, int i)
{
	int **tmp;
	int len;

	len = i;
	while (--i >= 0)
	{
		tmp = path[i]->path;
		free_matrix_i(tmp, count);
		free(path[i]);
	}
	free(path);
}
