#include "lemin.h"



int		**ft_make_sets(char **map, t_room **room, t_lem *lem)
{
	int		i;
	int		**set;

	i = 0;
	set = ft_allocate_matrix_int(lem->count_rooms);
	while (map[i])
	{
		if (ft_valid_str(map[i]) == 5)
			ft_write_links(map[i], room, set);
		i++;
	}
	return (set);
}


char	**ft_allocate_matrix_char(int dim)
{
	int		i;
	char	**matrix;

	i = 0;
	matrix = NULL;
	matrix = (char **)malloc(sizeof(char *) * (dim + 1));
	while (i < dim)
	{
		matrix[i] = ft_strnew(dim);
		ft_memset(matrix[i], '0', dim);
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}

int		**ft_allocate_matrix_int(int dim)
{
	int		i;
	int		**matrix;

	i = 0;
	dim++;
	matrix = (int **)malloc(sizeof(int *) * dim);
	while (i < dim)
	{
		matrix[i] = (int *)malloc(sizeof(int) * dim); // 02.09 удалил дополнительное умножение на dim
		ft_memset(matrix[i], -1, dim * 4);
		i++;
	}
	return (matrix);
}

// Создает несимметричную int матрицу и заполняет ее "-1"
// x длина, y высота

int		**ft_allocate_matrix_int_new(int x, int y)
{
	int		i;
	int		**matrix;

	i = 0;
	matrix = (int **)malloc(sizeof(int *) * y);
	while (i < y)
	{
		matrix[i] = (int *)malloc(sizeof(int) * x);
		ft_memset(matrix[i], -1, x * 4);
		i++;
	}
	return (matrix);
}



t_room	**ft_allocate_memory(t_lem *lem)
{
	int		i;
	t_room	**room;

	i = 0;
	if (!(room = (t_room**)malloc(sizeof(t_room*) * (lem->count_rooms + 1))))
		ft_leave();
	while (i < lem->count_rooms)
	{
		if (!(room[i] = (t_room *)malloc(sizeof(t_room))))
		{
			ft_free_room(&room, i);
			return (NULL);
		}
		ft_initialization_room(room[i]);
		i++;
	}
	return (room);
}

