#include "lemin.h"

char	**ft_read_map()
{
	int		ret;
    char	buff[BUFF_SIZE + 1];
	char	*del;
	char	*temp;
	int 	fl;
	char	**map;

	fl = 0;
	temp = ft_strnew(0);
	while ((ret = read(0, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		del = temp;
		temp = ft_strjoin(temp, buff);
		free(del);
		fl = 1;
	}
	if (fl == 0)
		ft_leave(); /* если пустая карта */
	map = ft_strsplit(temp, '\n');
	return (map);
}

