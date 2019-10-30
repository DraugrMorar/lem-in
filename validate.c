#include "lemin.h"

void	ft_leave(void)
{
	printf("ERROR\n");
	exit(0);
}

int		ft_valid_resh(char *map, t_lem *lem) /* проверяем start, end и comment*/
{
	int i;

	i = 0;
	if (map == NULL)
		ft_leave();
	else if (ft_strcmp(map, "##start") == 0)
	{
		lem->start++;
		return (1);
	}
	else if (ft_strcmp(map, "##end") == 0)
	{
		lem->end++;
		return (2);
	}
	else if (map[0] == '#' && map[1] != '\0')
		return (3);
	return (0);
}

int		ft_validation(char **map, t_lem *lem)
{
	int i;
	int	valid_resh;
	int valid_next;

	i = ft_valid_ants(map, lem);
	while (map[i])
	{
		if (map[i][0] == '#')
		{
			valid_resh = ft_valid_resh(map[i], lem);
			valid_next = ft_valid_resh(map[i + 1], lem);
			if (valid_resh == 3)
				i++;
			else if (((valid_resh == 1 || valid_resh == 2) && (map[i + 1] != NULL))
			&& ((valid_next == 4) || valid_next == 3)) /* проверяем что после start или end идет строка с координатами комнаты (4) */
				i++;
			else
			{
				printf("2\n"); // УБРАТЬ
				ft_leave();
			}
		}
		else if (ft_valid_str(map[i]) == 4)
		{
			lem->count_rooms++;
			i++;
		}
		else if (ft_valid_str(map[i]) == 5)
			i++;
		else
		{
			printf("3\n"); // УБРАТЬ
			ft_leave();
		}
	}
	if (lem->start == 1 && lem->end == 1)
		return (1);
	else
	{
		ft_leave();
		return (0);
	}
}