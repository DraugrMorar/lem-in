#include "lemin.h"

int		ft_valid_str(char *map)
{
	int		i;
	int		fl;
	t_valid	val;

	i = 0;
	fl = 0;

	val.name = 0;
	val.count_x = 0;
	val.count_y = 0;
	val.hyp = 0;
	val.space = 0;
	if (map[0] == 'L')
		return (0);
	else if (map[0] == '#')
		return (3);
	while (map[i])
	{
		if (map[i] == ' ' || map[i] == '-')
		{
			map[i] == ' ' ? val.space++ : val.defice++;
			fl = 0;
			i++;
		}
		else if ((map[i] != ' ' && fl == 0 && val.name < 1))
		{
			val.name++;
			fl = 1;
			i++;
		}
		else if ((map[i] != '-' && fl == 0 && val.name < 2 && val.defice == 1))
		{
			val.name++;
			fl = 1;
			i++;
		}
		else if ((map[i] != ' ' && map[i] != '-') && fl == 0 && val.space == 1) /* для валидации координаты x */
		{
			while(map[i] != ' ')
			{
				if (ft_isdigit(map[i]) == 1)
					i++;
				else if (map[i] == '\0' || ft_isdigit(map[i]) == 0)
					return (0);
			}
			val.count_x++;
		}
		else if ((map[i] != ' ' && map[i] != '-') && fl == 0 && val.space == 2)
		{
			while(map[i] != '\0')
			{
				if (ft_isdigit(map[i]) == 1)
					i++;
				else
					return (0);
			}
			val.count_y++;
		}
		else if (val.name == 1 && fl == 0 && (map[i] != ' ' && map[i] != '-') && val.defice == 1) /* валидируем name2 */
		{
			if (map[i] == '#' || map[i] == 'L')
				return (0);
			val.name++;
			fl = 1;
			i++;
		}
		else if ((map[i] != ' ' && map[i] != '-') && fl == 1) /* находимся в name */
			i++;
		else
		    return (0);
	}
	if (val.space == 2 && val.name == 1 && val.count_x == 1 && val.count_y == 1)
		return (4);
	else if (val.defice == 1 && val.name == 2)
		return (5);
	else
		return (0);
}