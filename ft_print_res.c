#include "lemin.h"


void	ft_print_path(int *path)
{
	int i = 0;

	while (path[i] > -1)
	{
		printf("%d ", path[i]);
		i++;
	}
	printf("\n");
}


// Печатаем матрицу смежности
void	ft_print_matrix(char **matrix, t_lem *lem)
{
	int i;

	i = 0;
	while (i < lem->count_rooms)
	{
		printf("%s\n", matrix[i]);
		i++;
	}
	printf("\n\n");
}

// Печатаем имя, level, count_rooms
void	ft_print_name_lvl(t_lem *lem, t_room **room)
{
	int i;

	i = 0;
	printf("\nCOUNT_ROOMS = %d\n", lem->count_rooms);
	printf("\nCOUNT_ANTS = %d\n", lem->ants);
	while (i < lem->count_rooms)
	{
		printf("name = %s, lvl = %d\n", room[i]->name, room[i]->lvl);
		i++;
	}
}

// Печатаем путь по индексу
void		ft_print_path_index(t_path *path)
{
	int i;
	int j;

	i = 0;
	while (path->path[i][0] >= 0)
	{
		j = 0;
		while (path->path[i][j] >= 0)
		{
			printf("path %d:  %d \n", i, path->path[i][j]);
			j++;
		}
		printf("\nLEN_PATH = %d \n", j - 1);
		printf("\n");
		i++;
	}
}

// Печатаем путь по имени
void		ft_print_path_name(t_path *path, t_room **room)
{
	int i;
	int j;

	i = 0;
	if (path->path[0][0] == -1)
	{
		printf("Пустой набор путей\n"); /* ПРОВЕРКА УБРАТЬ */
		return ;
	}
	while (path->path[i][0] >= 0)
	{
		j = 0;
		while (path->path[i][j] >= 0)
		{
			printf("path %d:  %s \n", i, room[path->path[i][j]]->name);
			j++;
		}
		printf("\nLEN_PATH = %d \n", j);
		printf("\n");
		i++;
	}
}


int		**ft_create_res_matrix(t_lem *lem, t_path *path, int iter)
{
	int	i;
	int	**matrix_res;
	int ants;

	i = 0;
	path->i = 0;
	path->j = 0;
	ants = lem->ants;
	matrix_res = ft_allocate_matrix_int_new(ants + 1, iter + 3); // несимметричная матрица
	while (ants)
	{
		while (path->path[i][0] != -1)
		{
			if (path->path[i][1] > 0)
			{
				add_path_in_matrix(path, i, matrix_res);
				path->j++;
				path->path[i][1]--; // отняли муравья из пути в массиве
				ants--; // отняли муравья от общего количества муравьев
			}
			i++;
		}
		path->i++;
		i = 0;
	}
	return (matrix_res);
}

void		ft_print_res(int **res, t_lem *lem, t_room **rm)
{
	int i;
	int j;
	int ants;

	i = 0;
	j = 0;
	ants = lem->ants;
	while (path_present(res[i], ants) == 1)
	{
		while (j < ants)
		{
			if (res[i][j] > 0)
			{
				printf("L%d-", j + 1);
				printf("%s ", rm[res[i][j]]->name);
			}
			j++;
		}
		i++;
		j = 0;
		printf("\n");
	}
	printf("count_iter=%d\n", i);
}
