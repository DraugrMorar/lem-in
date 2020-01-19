/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:11:18 by dmorar            #+#    #+#             */
/*   Updated: 2020/01/07 15:11:20 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# define BLOCK 100000
# include "./libft/libft.h"

typedef struct	s_room
{
	char		*name;
	int			x;
	int			y;
	int			fl;
	int			lvl;
}				t_room;

typedef struct	s_lem
{
	int			i;
	int			n;
	int			k;
	int			vld;
	int			start;
	int			end;
	int			ants;
	int			count_rooms;
	int			links;
	int			fl;
	int			**sets;
	int			*tmp;
	int			len;
	int			str;
	int			*qu;
}				t_lem;

typedef struct	s_valid
{
	int			name;
	int			sp;
	int			hyp;
	int			count_x;
	int			count_y;
}				t_valid;

typedef struct	s_path
{
	int			i;
	int			j;
	int			res;
	int			count_paths;
	int			**path;
}				t_path;

/**
***				main.c
**/
void			init(void *data, size_t size);
void			leave(void);
int				main(void);
/**
***				validation1.c
**/
int				validation(char **map, t_lem *lem);
int				valid_sharp(char *map, t_lem *lem);
/**
***				validation2.c 
**/
int				valid_str(char *map);
/**
***				validation3.c
**/
void			helper_1(char map_i, t_valid *val, int *i, int *fl);
void			helper_2(t_valid *val, int *i, int *fl);
int				helper_3(char *map, t_valid *val, int *i);
int				helper_4(char *map, t_valid *val, int *i);
int				helper_5(char *map, t_valid *val, int *i, int *fl);
/**
***				record.c
**/
t_room			**record(char **map, t_lem *lem);
/**
***				sets.c
**/
void			make_sets(char **map, t_room **room, t_lem *lem);
/**
***				allocation.c
**/
int				*alloc_qu(int len, t_lem *lem);
t_room			**alloc_rooms(t_lem *lem);
int				**alloc_matrix(int x, int y);
t_path			**alloc_path(int len, int count_rooms);
/**
***				free1.c
**/
void			free_map(char ***map);
void			result(t_path **path, t_lem *lem, t_room **room, char **map);
/**
***				free2.c
**/
void			free_room(t_room ***room, int i);
void			free_matrix(int ***matrix, int i);
void			free_path(int count, t_path **path, int i);
/**
***				 print_res1.c
**/
void			print_res(int **matrix_res, t_lem *lem,
				t_room **room, char **map);
int				**create_res_matrix(t_lem *lem, t_path *path, int iter);
/**
***				print_res2.c
**/
void			put_ants_in_path(t_lem *lem, t_path *path);
void			reverse_path(t_path *path);
void			count_iter(t_path *path, t_lem *lem);
int				choose_set_of_paths(t_path **path);
/**
***		 		bfs.c
**/
void			nul_fl(t_room **room, t_lem *lem);
void			bfs2(int **sets, t_lem *lem, t_room **room, int *tmp);
/**
***				block_del.c
**/
void			block_link(int **sets, int i, int j);
void			del_link(int **sets, int i, int j);
void			all_flag(int *flag, t_lem *lem, t_path **path, int *i);
void			unblock_all(int **sets);
/**
***				add.c
**/
void			ft_write(char *map, t_room **room, int k);
void			unblock_link(int **sets, char sign);
/**
***				alg1.c
**/
int				check_path_2(t_room **room, int **sets,
				t_lem *lem, t_path *path);
/**
***				alg2.c	
**/
void			path_overwrite(int i, t_path *path);
int				check_1(int **sets, t_lem *lem, t_path *path);
int				next_link_2(int *str, t_lem *lem, t_room **room);
int				units_present(int *str);
int				*first_path(t_path *path, t_room **room,
				t_lem *lem, int **sets);
/**
***				alg3.c
**/
void			all_paths(t_path **path, t_room **room, t_lem *lem, int *qu);

#endif
