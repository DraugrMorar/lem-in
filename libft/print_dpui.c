/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dpui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 19:56:37 by dmorar            #+#    #+#             */
/*   Updated: 2019/03/28 16:48:43 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		printint3(t_form *fo, char **str, int i, int n)
{
	if (fo->cut == 0 && fo->wide > 0 && fo->flags[0] != '0'
	&& fo->acu == -1)
		fo->wide++;
	if (fo->cut == 1 && fo->wide > 0 && fo->flags[0] == '0'
	&& fo->acu == -1)
		fo->wide++;
	if (fo->cut != 1 && fo->wide > 0 && *str[0] != '-' && fo->acu == -1 &&
	fo->flags[0] != '0')
		fo->wide--;
	if (fo->wide > n)
		i += wideforint(fo, fo->wide - n - fo->cut);
	if (((*str[0] == '-' || (fo->flags[3] == '+' && *str[0] != '-')) &&
	fo->flags[0] == ' ') || (fo->type == 2 && fo->flags[2] == '#' &&
	fo->flags[0] == ' '))
		i += printsign(fo, &(*str));
	if (fo->acu > (int)ft_strlen(*str))
	{
		i += n - (int)ft_strlen(*str) - fo->m;
		while ((fo->acu - (int)ft_strlen(*str)) > 0)
		{
			write(1, "0", 1);
			fo->acu--;
		}
	}
	return (i += write(1, *str, ft_strlen(*str)));
}

int		printint2(t_form *fo, char **str, int i)
{
	if (fo->acu >= 0)
		fo->flags[0] = ' ';
	if ((*str[0] == '-' || (ft_strchr(fo->flags, '+') != NULL) ||
	fo->flags[1] == ' ') || (fo->type == 2 && fo->flags[2] == '#'))
	{
		fo->m = 1;
		if (fo->type == 2 && fo->flags[2] == '#')
			fo->m = 2;
		if (fo->flags[1] == ' ' && *str[0] != '-' &&
		(ft_strchr(fo->flags, '+') == NULL))
			i += write(1, " ", 1);
		if (fo->wide > fo->acu && *str[0] == '-' &&
		ft_strlen(*str) > (unsigned long)fo->acu)
			fo->m = 0;
	}
	if (((*str[0] == '-' || (ft_strchr(fo->flags, '+') != NULL && *str[0]
	!= '-')) && fo->flags[0] == '0') || (fo->type == 2 && fo->flags[2]
	== '#' && fo->flags[0] == '0'))
		i += printsign(fo, &(*str));
	if (fo->acu >= (int)ft_strlen(*str))
		return (printint3(fo, &(*str), i, (fo->acu + fo->m)));
	else if (fo->acu < (int)ft_strlen(*str))
		return (printint3(fo, &(*str), i, ((int)ft_strlen(*str) + fo->m)));
	return (0);
}

int		printint(t_form *fo, char **str)
{
	int	i;

	i = 0;
	if (fo->type == 2 && *str[0] == '0' && ft_strlen(*str) == 1 &&
	fo->acu == 0)
		return (write(1, "0x", 2));
	if (*str[0] == '0' && ft_strlen(*str) == 1 && fo->acu == 0)
	{
		if (fo->flags[1] == ' ')
			i += write(1, " ", 1);
		if (ft_strchr(fo->flags, '+') != NULL)
		{
			fo->wide--;
			i += write(1, "+", 1);
		}
		fo->acu = -1;
		if (fo->wide != 0)
			while (fo->wide-- > 0)
				i += write(1, " ", 1);
		return (i);
	}
	else if (ft_strchr(fo->flags, '-') != NULL)
		return (printminusint(fo, &(*str)));
	return (printint2(fo, &(*str), i));
}
