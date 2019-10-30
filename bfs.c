#include "lemin.h"

int			ft_check_empty(int *tmp, t_lem *lem)
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

void		ft_del_left(int *tmp)
{
	int		i;
	
	i = 0;
	while (tmp[i] == -1)
		i++;
	tmp[i] = -1;
}

void		ft_block_link(int **sets, int i, int j)
{
	int		tmp;
	int		k;

	tmp = sets[i][j];
	k = 0;
	sets[i][j] = sets[i][j] - BLOCK;
	while (sets[tmp][k] != i)
	{
		if (sets[tmp][k] == -1)
			return;
		k++;
	}
	sets[tmp][k] = sets[tmp][k] - BLOCK;
}

void		ft_add_neighbors(int **sets, t_room **room, int *tmp)
{
	int		i;
	int		j;
	int		k;
	int		lvl;

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
		if (sets[i][j] >= 0 && sets[i][j] < BLOCK / 2 && room[sets[i][j]]->fl == 0)
		{
			room[sets[i][j]]->fl = 1;
			tmp[k] = sets[i][j];
			room[tmp[k]]->lvl = lvl;
			ft_block_link(sets, i, j);
			k++;
		}
		j++;
	}
}

void		ft_bfs(int **sets, t_lem *lem, t_room **room, int *tmp)
{
	int i;
	
	i = 0;

	tmp[0] = 0;
	while (ft_check_empty(tmp, lem) != 0)
	{
		ft_add_neighbors(sets, room, tmp);
		ft_del_left(tmp);
		i++;
	}
}
