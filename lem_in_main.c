#include "lemin.h"
#include <stdio.h>
# include "./libft/libft.h"

void ft_nul_fl(t_room **room, t_lem *lem)
{
	int i = 0;
	while (i < lem->count_rooms)
	{
		room[i]->fl = 0;
		room[i]->lvl = 0;
		i++;
	}
}



int		*ft_alloc_qu(int len)
{
	int *tmp;

	tmp = (int *)malloc(sizeof(int) * len);
	ft_memset(tmp, -1, len * 4);
	return (tmp);
}


int		ft_valid_ants(char **map, t_lem *lem)
{
	int	i;
	int	j;

	i = 0;
	while (map[i][0] == '#')
		i++;
	if (map[i][0] >= '1' && map[i][0] <= '9')
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (ft_isdigit(map[i][j]) == 1)
				j++;
			else
				ft_leave();
		}
		lem->ants = ft_atoi(map[i]);
		if (lem->ants < 1)
			ft_leave();
		i++;
		return (i);
	}
	else
	{
		ft_leave();
		return (0);
	}
}



void	ft_free_room(t_room ***room, int i)
{
	while (--i >= 0)
	{
		free((*room)[i]);
		(*room)[i] = NULL;
	}
	free(*room);
	*room = NULL;
}



// Записывает Name x y
void 	ft_write(char *map, t_room **room, int k)
{
    int co;

    co = 0;
    while (map[co] != ' ')
        co++;
    room[k]->name = ft_strnew(co);
    ft_strncpy(room[k]->name, map, co);
    room[k]->x = ft_atoi(&map[co]);
    co++;
    while (map[co] != ' ')
        co++;
    room[k]->y = ft_atoi(&map[co]);
}



void	ft_create_str(char *matrix, t_lem *lem, int ***tmp, int k)
{
	int j;

	j = 0;
	while (matrix[j])
	{
		if (matrix[j] == '1')
		{
			(*tmp)[k + 1][lem->n] = j;
			lem->n++;
		}
		j++;
	}
}

void	ft_find(int ***tmp, int i, int j, int k)
{
	int		l;
	int		m;
	int		num;

	l = 0;
	num = (*tmp)[i][j];
	while (l < k + 1)
	{
		m = 0;
		while ((*tmp)[l][m] >= 0)
		{
			if (((*tmp)[l][m] == num) && !(i == l && j == m))
			{
				while ((*tmp)[l][m] >= 0)
				{
					(*tmp)[l][m] = (*tmp)[l][m + 1];
					m++;
				}
				m = 0;
			}
			m++;
		}
		l++;
	}
}

int		ft_del_repeat(int ***tmp, int k) /* возвращает длину последней строки */
{
	int		i;
	int		j;

	i = 0;
	while (i < k + 1)
	{
		j = 0;
		while ((*tmp)[i][j] >= 0)
		{
			ft_find(tmp, i, j, k);
			j++;
		}
		i++;
	}
	j = 0;
	i--;
	while ((*tmp)[i][j] >= 0)
		j++;
	return (j); /* если не зашли в while => строка пустая (все удалили), в противном случае человеческая длина (+1) */
}

int ft_check_repeat(t_room **room, t_lem *lem)
{
	int		i;
	int		k;
	char	tmp[1000];

	i = 0;
	//if (tmp = (char*)malloc(sizeof(char * 100) == NULL))
	//	ft_leave();
	while (i < lem->count_rooms)
	{
		k = 0;
		ft_strcpy(tmp, room[i]->name);
		while (k < lem->count_rooms)
		{
			if(ft_strcmp(tmp, room[k]->name) == 0 && k != i)
			{
				printf("Повтор\n");
				return (1);
			}
			k++;
		}
		i++;
	}
	return (0);
}

int		ft_no_start_end(t_room **room, t_lem *lem)
{
	int tmp;

	tmp = lem->count_rooms - 1;
	if (room[0]->name == NULL || room[tmp]->name == NULL)
		return (1);
	else if(ft_strcmp(room[0]->name, room[tmp]->name) == 0)
		return (1);
	else
		return (0);
}

t_room 	**ft_record(char **map, t_lem *lem) /* записываем name и координаты (без связей) */
{
	int			i;
	int			k;
	int			valid_resh;
	t_room		**room;

	i = 0; /* 0 строка - это кол-во муравьев - ИСПРАВИТЬ! - там может быть коммент */
	k = 1; /* индекс для массива структур room */
	room = ft_allocate_memory(lem);
	while (map[i])
	{
		valid_resh = ft_valid_resh(map[i], lem);
		if (map[i][0] == '#' && valid_resh == 1)
		{
			while (ft_valid_resh(map[i + 1], lem) == 3)
				i++;
			i++;
		    ft_write(map[i], room, 0); /* записать старт на 0 место */
		}
		else if ((map[i][0] == '#' && valid_resh == 2))
		{
			while (ft_valid_resh(map[i + 1], lem) == 3)
				i++;
			i++;
			ft_write(map[i], room, lem->count_rooms - 1); /*записать end на *room[lem->count_rooms - 1] */
		}
		else if (ft_valid_str(map[i]) == 4)
		{
			ft_write(map[i], room, k);
            k++;
		}
		i++;
	}
	if (ft_check_repeat(room, lem) == 1 || ft_no_start_end(room, lem) == 1)
	{
		// надо зафришить комнаты
		ft_leave();
	}
	return (room);
}



int		ft_search_name(char **map, t_room **room, char end)
{
	int		len_name;
	int		index;
	char	*name;
	char	*temp;

	len_name = 0;
	index = 0;
	temp = *map;
	name = NULL;
	while (**map != end)
	{
		(*map)++;
		len_name++;
	}
	name = ft_strnew(len_name);
	ft_strncpy(name, temp, len_name);
	while (room[index])
	{
		if (ft_strcmp(name, room[index]->name) == 0)
			break ;
		index++;
	}
	if (room[index] == NULL)
		return (-1); 
	return (index);
}

// Записываем линки между комнатами на соответствующие позиции матрицы смежности
void	ft_write_links(char *map, t_room **room, int **set)
{
	int		name1_ind;
	int		name2_ind;
	int		i;

	if ((name1_ind = ft_search_name(&map, room, '-')) == -1)
	{
		//зафришить все
		ft_leave();
	}
	map++;
	if ((name2_ind = ft_search_name(&map, room, '\0')) == -1)
	{
		//зафришить все
		ft_leave();
	}
	i = 0;
	while (set[name1_ind][i] != -1)
		i++;
	set[name1_ind][i] = name2_ind;
	i = 0;
	while (set[name2_ind][i] != -1)
		i++;
	set[name2_ind][i] = name1_ind;
}

/* Функция считает кол-во итераций для каждого набора из путей и записывает в res.
Исходя их наименьшего 'res' затем выберем лучший набор путей.
Считаем res по формуле:
Кол-во итераций = (кол-во шагов по всем путям + (кол-во муравьев - кол-во путей))/кол-во путей */

void	ft_count_iter(t_path *path, t_lem *lem) /* кол-во строк = кол-ву путей, кол-во символов в строке - 1 = кол-во шагов в пути */
{
	int i;
	int j;
	int count_iter;
	int	count_steps;
	int	count_paths;

	i = 0;
	j = 0;
	count_iter = 0;
	count_steps = 0;
	count_paths = 0;
	if (path->path[0][0] == -1) /* защита */
		return ;
	while (path->path[i][0] >= 0)
	{
		j = 0;
		//count_steps--;
		while (path->path[i][j] >= 0)
		{
			count_steps++;
			j++;
		}
		count_paths++;
		i++;
	}
	count_steps = count_steps - count_paths;
	path->res = ((count_steps + (lem->ants - count_paths)) / count_paths);
	path->count_paths = count_paths;
}

// void	ft_del_link(char **matrix, int i, int j)
// {
// 	matrix[i][j] = '9';
// 	matrix[j][i] = '9';
// }

void	ft_del_link(int **sets, int i, int j)
{
	int		k;

	k = 0;
	while (sets[i][k] != j)
	{
		if (sets[i][k] == -1)
			return;
		k++;
	}
	sets[i][k] = j + BLOCK;
	k = 0;
	while (sets[j][k] != i)
	{
		if (sets[j][k] == -1)
			return;
		k++;
	}
	sets[j][k] = sets[j][k] + BLOCK;
}

int ft_units_present(int *str) // наличие связей у вершины
{
    int i;

    i = 0;
    while (str[i] != -1)
    {
        if (str[i] >= 0 && str[i] < BLOCK / 2) // просто BLOCK
            return(1);
        else
            i++;
    }
    return (0);
}

int		ft_next_link_2(int *str, t_lem *lem, t_room **room)
{
	int j;
	int tmp;
	int lvl;
	int fl;

	j = 0;
	fl = 0;
	lem->count_rooms = lem->count_rooms;
	while (str[j] != -1)
	{
		if (str[j] >= 0  && str[j] <= BLOCK / 2)
		{
			if (fl == 0) /* записываем первую встретившуюся вершину, не смотря на левел */
			{
				tmp = str[j];
				lvl = room[str[j]]->lvl;
				fl = 1;
			}
			else if (fl == 1 && (room[str[j]]->lvl) < lvl)
			{
				tmp = str[j];
				lvl = room[str[j]]->lvl;
			}
		}
		j++;
	}
	return (tmp);
}


// 02.09 удаление из набора очень длинного пути
void ft_path_overwrite(int i, t_path *path)
{
	int j;
	j = 0;
	while (path->path[i][j] > -1)
	{
		path->path[i][j] = -1;
		j++;
	}
}

int ft_check_path_2(t_room **room, int **sets, t_lem *lem, t_path *path)
{
    int str;

    path->j = 0;
    str = lem->count_rooms - 1;
    path->path[path->i][path->j] = str;
    path->j++;
	if (ft_units_present(sets[0]) == 0 || ft_units_present(sets[lem->count_rooms - 1]) == 0)
	{
		path->path[path->i][0] = -1;
		return (0); // мб в функцию, которая вызывает ft_check_path_2 добавить флаг, чтобы не было бесконечного цикла
	}
    while (str != 0) /* выполняем пока не пришли в строку start */
    {
		//ft_print_path(path->path[path->i]);
		if (path->j > 100) // 02.09 заглушка на длиннющий путь
		{
			ft_path_overwrite(path->i, path);
			path->i--;
			return (1);
		}
		if (ft_units_present(sets[str]) == 1)
		{
			str = ft_next_link_2(sets[str], lem, room);
			path->path[path->i][path->j] = str;
			ft_del_link(sets, path->path[path->i][path->j - 1], path->path[path->i][path->j]);
			path->j++;
			continue ;
		}
		else
		{
			if (str == lem->count_rooms - 1)
			{
				path->path[path->i][0] = -1;
				return (0);
			}
			else
			{
				path->j--;
				str = path->path[path->i][path->j];
				path->path[path->i][path->j + 1] = -1;
				if (ft_units_present(sets[str]) == 1)
				{
					path->j++;
				}
			}
		}
    }
    return (1);
}

void	ft_free_path(t_path ***path, int i)
{
	while (--i >= 0)
	{
		free((*path)[i]);
		(*path)[i] = NULL;
	}
	free(*path);
	*path = NULL;
}

t_path		**ft_allocate_memory_path(int len, int count_rooms)
{
	int		i;
	t_path	**path;

	i = 0;
	if (!(path = (t_path**)malloc(sizeof(t_path*) * (len + 1))))
		ft_leave();
	while (i < len)
	{
		if (!(path[i] = (t_path*)malloc(sizeof(t_path))))
		{
			ft_free_path(&path, i);
			return (NULL);
		}
		ft_initialization_path(path[i]);
		path[i]->path = ft_allocate_matrix_int(count_rooms);
		i++;
	}
	path[i] = NULL;
	return (path);
}

void	ft_free_matrix(char ***matrix)
{
	int i;

	i = 0;
	while ((*matrix)[i] != NULL)
	{
		free((*matrix)[i]);
		(*matrix)[i] = NULL;
		i++;
	}
	free(*matrix);
	*matrix = NULL;
}

// void		ft_unblock_all(char **matrix)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (matrix[i] != NULL)
// 	{
// 		j = 0;
// 		while (matrix[i][j] != '\0')
// 		{
// 			if (matrix[i][j] == '7' || matrix[i][j] == '9')
// 				matrix[i][j] = '1';
// 			j++;
// 		}
// 		i++;
// 	}
// }

void		ft_unblock_all(int **sets)
{
	int i;
	int j;

	i = 0;
	while (sets[i][0] != -1)
	{
		j = 0;
		while (sets[i][j] != -1)
		{
			if (sets[i][j] < -BLOCK / 2) // заменить BLOCK / 2 на -1
				sets[i][j] = sets[i][j] + BLOCK;
			j++;
		}
		i++;
	}
}


void		ft_free_str(int **sets, int *path)
{
	int	i;
	int j;
	int tmp;

	i = 1; /* берем из пути индексы (начиная с 1го чтобы не занулять строку end и зануляем соответствующие строки матрицы смежности*/
	while (path[i] != 0)
	{
		tmp = path[i];
		j = 0;
		while (sets[tmp][j] != -1)
		{
			if (sets[tmp][j] >= 0 && sets[tmp][j] < BLOCK / 2)
			{
				sets[tmp][j] = sets[tmp][j] + BLOCK;
			}
			j++;
		}
		i++;
	}
}

// Функция записывает первый набор путей
int		*ft_first_path(t_path *path, t_room **room, t_lem *lem, int **sets, int *tmp)
{
	path->i = -1;
	while (1)
	{
		path->i++;
		path->j = 0;
		if (ft_check_path_2(room, sets, lem, path) == 0)
			break ;
		//else
		//	ft_free_str(sets, path->path[path->i]); /* блокируем пути '9' */
		ft_nul_fl(room, lem);
		ft_bfs2(sets, lem, room, tmp);
		ft_unblock_link(sets, '7');
	}
	ft_count_iter(path, lem);
	ft_unblock_all(sets);
	return (path->path[0]);
}

// // Заменяем либо '7', либо '9' на '1'
// void		ft_unblock_link(char **matrix, char num)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (matrix[i] != NULL)
// 	{
// 		j = 0;
// 		while (matrix[i][j] != '\0')
// 		{
// 			if (matrix[i][j] == num)
// 				matrix[i][j] = '1';
// 			j++;
// 		}
// 		i++;
// 	}
// }

// вернуться к ней
void		ft_unblock_link(int **sets, char sign)
{
	int i;
	int j;

	i = 0;
	while (sets[i][0] != -1)
	{
		j = 0;
		while (sets[i][j] != -1)
		{
			if (sets[i][j] < -BLOCK / 2 && sign == '7')
				sets[i][j] = sets[i][j] + BLOCK;
			else if (sets[i][j] > BLOCK && sign == '9')
				sets[i][j] = sets[i][j] - BLOCK;
			j++;
		}
		i++;
	}
}

// Зануление структуры t_path
void		ft_del_info_path(t_path *path, t_lem *lem)
{
	int i;

	i = 0;
	path->i = 0;
	path->j = 0;
	path->count_paths = 0;
	path->res = 0;
	while (i < lem->count_rooms)
	{
		ft_memset(path->path[i], -1, lem->count_rooms * 4);
		i++;
	}

}

int			choose_set_of_paths(t_path **path)
{
	int tmp;

	tmp = ((path[0]->res) > (path[1]->res) && (path[1]->res != 0) ? 1 : 0);
	tmp = (tmp > (path[2]->res) && (path[2]->res != 0) ? 2 : tmp);
	return (tmp);
}

// Устанавливаем на все позиции матрицы "-1"
void		ft_clear_matrix_int(int **matrix, int len)
{
	int i = 0;

	while (i < len)
	{
		ft_memset(matrix[i], -1, len * 4);
		i++;
	}
}

int		ft_all_paths(t_path **path, t_room **room, t_lem *lem, int **sets, int *first, int *temp)
{
	int		i;
	int		k;
	int		len;
	int		flag;

	i = 1;
	k = 1;
	len = 0;
	flag = 0;

	while (first[len] >= 0)
		len++;
	len = len - 3; /* кол-во ребер, которое будем удалять = (кол-во вершин - 1) и еще (- 2) (т.к. не удаляем ребра у start и end) */
	while (len > 0)
	{
		path[k]->i = 0;
		//ft_block_link(matrix, first[i], first[i + 1]);
		ft_del_link(sets, first[i], first[i + 1]);
		ft_nul_fl(room, lem);
		ft_bfs2(sets, lem, room, temp);
		ft_unblock_link(sets, '7');
		if (ft_check_path_2(room, sets, lem, path[k]) == 0)
		{
			ft_unblock_link(sets, '7');
			i++;
			len--;
			continue ;
		}

		while (1)
		{
			ft_nul_fl(room, lem);
			ft_bfs2(sets, lem, room, temp);
			ft_unblock_link(sets, '7');
			path[k]->i++;
			path[k]->j = 0;
			if (ft_check_path_2(room, sets, lem, path[k]) == 0)
				break ;
			//else
			//	ft_free_str(sets, path[k]->path[path[k]->i]); /* заменяем "1" на "9" */
		}
		ft_count_iter(path[k], lem);
		if (flag == 1 && (len - 1))
		{
			k = (path[1]->res > path[2]->res ? 1 : 2);
			ft_del_info_path(path[k], lem); /* только зануляем информацию (не фришим) чтобы перезаписывать поверх */
		}
		if (flag == 0)
		{
			flag = 1;
			k++;
		}
		len--;
		i++;
		ft_unblock_all(sets);
	}
	k = choose_set_of_paths(path);
	return(k);
}

// Функция записывает путь в правильном порядке (от start к end), т.к. изначально путь хранится наоборот
// На нулевом месте хранится длина пути
void		ft_reverse_path(t_path *path)
{
	int i;
	int j;
	int k;
	int tmp;

	i = 0;
	k = 0;
	j = 0;
	while (path->path[k][0] >= 0)
	{
		while (path->path[k][j] >= 0)
				j++;
		path->path[k][j] = j;
		while (i < j)
		{
			tmp = path->path[k][i];
			path->path[k][i] = path->path[k][j];
			path->path[k][j] = tmp;
			i++;
			j--;
		}
		k++;
		i = 0;
		j = 0;
	}
}

// В каждый путь кладем количество муравьев, которые пойдут по этому пути
// path->path[i][0] хранится len массива
// path->path[i][1] хранится кол-во муравьев
void		ft_put_ants_in_path(t_lem *lem, t_path *path)
{
	int		i;
	int 	sum;
	int		ants;

	sum = 0;
	ants = lem->ants;
	while (ants > 0)
	{
		i = 0;
		while (path->path[i][0] != -1)
		{
			if (sum > path->path[i][0] + path->path[i][1])
			{
				path->path[i][1]++;
				ants--;
				if (ants == 0)
					break ;
			}
			i++;
		}
		sum++;
	}
}

void		add_path_in_matrix(t_path *path, int index, int **matrix_res)
{
	int i;
	int j;

	i = path->i; // смещение вниз по столбцу матрицы
	j = 2; // смещение влево по пути, начинаем с 2х т к на 0м месте len, на 1м количество муравьев
	while (path->path[index][j] > 0)
	{
		matrix_res[i][path->j] = path->path[index][j];
		i++;
		j++;
	}
}



int	path_present(int *str, int ants)
{
	int j = 0;

	while(j < ants)
	{
		if(str[j] > 0)
			return (1);
		j++;
	}
	return (0);
}



int			main(void)
{
	int		k = 0;
	t_lem	lem;
	char	**map; 			// карта
	int		**sets;			// списки смежности
	int		*tmp;
	t_room	**room; 		// массив структур для комнат
	t_path	**path; 		// массив структур набора путей
	int		*first;			// кратчайший путь из 1-го набора путей (из него будем удалть ребра)
	int		**matrix_res;	// конечная матрица для вывода

	ft_initialization_lem(&lem);
	map = ft_read_map();
	ft_validation(map, &lem) == 1 ? room = ft_record(map, &lem) : exit (0);
	sets = ft_make_sets(map, room, &lem);
	tmp = ft_alloc_qu(lem.count_rooms + 3);
	ft_bfs2(sets, &lem, room, tmp);
	ft_unblock_all(sets);
	path = ft_allocate_memory_path(3, lem.count_rooms + 1); // выделяем память под 3 структуры, чтобы перезаписывать
	first = ft_first_path(path[0], room, &lem, sets, tmp); // записываем первый набор путей (без удаления ребер)
	k = ft_all_paths(path, room, &lem, sets, first, tmp); // возвращает индекс набора путей
	ft_reverse_path(path[k]); // разворачивает путь и записывает длину пути на 0 место
	ft_put_ants_in_path(&lem, path[k]); // на 1 место каждого пути кладем кол-во муравьев
	matrix_res = ft_create_res_matrix(&lem, path[k], path[k]->res); // Создаем матрицу из путей для всех меравьев, которую будем выводить построчно
	ft_print_res(matrix_res, &lem, room); // Печатаем вывод
	printf("OK\n");
    return (0);
}