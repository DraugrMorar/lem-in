/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:11:10 by dmorar            #+#    #+#             */
/*   Updated: 2020/01/07 15:11:13 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		cycle(t_room **room, t_lem *lem, t_path **path, int *qu)
{
	while (1)
	{
		nul_fl(room, lem);
		bfs2(lem->sets, lem, room, qu);
		unblock_link(lem->sets, '7');
		path[lem->k]->i++;
		path[lem->k]->j = 0;
		if (check_path_2(room, lem->sets, lem, path[lem->k]) == 0)
			break ;
	}
}

static void		apply_bfs(t_lem *lem, int *first, t_room **room, int *qu)
{
	del_link(lem->sets, first[lem->i], first[lem->i + 1]);
	nul_fl(room, lem);
	bfs2(lem->sets, lem, room, qu);
	unblock_link(lem->sets, '7');
}

static void		all_start(t_lem *lem)
{
	lem->i = 1;
	lem->k = 1;
	lem->len = 0;
}

void			all_paths(t_path **path, t_room **room, t_lem *lem, int *qu)
{
	int		i;
	int		flag;
	int		*first;

	all_start(lem);
	flag = 0;
	first = first_path(path[0], room, lem, lem->sets);
	while (first[lem->len] >= 0)
		lem->len++;
	lem->len = lem->len - 3;
	while (lem->len > 0)
	{
		path[lem->k]->i = 0;
		apply_bfs(lem, first, room, qu);
		if (check_path_2(room, lem->sets, lem, path[lem->k]) == 0)
		{
			unblock_link(lem->sets, '7');
			i++;
			lem->len--;
			continue ;
		}
		cycle(room, lem, path, qu);
		all_flag(&flag, lem, path, &i);
	}
	lem->k = choose_set_of_paths(path);
}
