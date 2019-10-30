#include "lemin.h"

void	ft_initialization_lem(t_lem *lem)
{
	ft_bzero(lem, sizeof(t_lem));
}

void	ft_initialization_room(t_room *room)
{
	ft_bzero(room, sizeof(t_room));
}

void	ft_initialization_path(t_path *path)
{
	ft_bzero(path, sizeof(t_path));
}

