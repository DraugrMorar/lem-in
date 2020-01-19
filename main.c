/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 22:12:32 by waddam            #+#    #+#             */
/*   Updated: 2020/01/07 15:13:05 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			init(void *data, size_t size)
{
	ft_bzero(data, size);
}

void			leave(void)
{
	ft_printf("ERROR\n");
	exit(0);
}

static int		strsrch(char *str, char chr)
{
	int		i;

	i = 0;
	while (str[i + 1] != '\0')
	{
		if (str[i] == chr && str[i + 1] == chr)
			return (1);
		i++;
	}
	return (0);
}

static void		ft_read_map(char ***map, t_lem *lem)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];
	char	*temp;
	char	*line;

	lem->fl = 0;
	if (!(line = ft_strnew(0)))
		leave();
	while ((ret = read(0, buff, BUFF_SIZE)) > 0)
	{
		lem->fl = 1;
		buff[ret] = '\0';
		if (strsrch(buff, '\n') == 1)
			leave();
		temp = line;
		line = ft_strjoin(line, buff);
		free(temp);
	}
	if (lem->fl == 0)
		leave();
	if (line == NULL)
		leave();
	*map = ft_strsplit(line, '\n');
	free(line);
}

int				main(void)
{
	t_lem	lem;
	char	**map;
	int		*qu;
	t_room	**room;
	t_path	**path;

	init(&lem, sizeof(t_lem));
	ft_read_map(&map, &lem);
	validation(map, &lem) == 1 ? room = record(map, &lem) : exit(0);
	make_sets(map, room, &lem);
	qu = alloc_qu(lem.count_rooms + 3, &lem);
	bfs2(lem.sets, &lem, room, qu);
	if (room[lem.count_rooms - 1]->lvl == 0)
		leave();
	unblock_all(lem.sets);
	path = alloc_path(3, lem.count_rooms + 1);
	all_paths(path, room, &lem, qu);
	result(path, &lem, room, map);
	free(qu);
	return (0);
}
