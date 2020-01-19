/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dpui2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 19:56:28 by dmorar            #+#    #+#             */
/*   Updated: 2019/03/28 11:34:06 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		wideforint(t_form *form, int len)
{
	int i;

	i = 0;
	i = len;
	while (len > 0)
	{
		write(1, &form->flags[0], 1);
		len--;
	}
	return (i);
}

int		printsign(t_form *form, char **str)
{
	int i;

	i = 0;
	if (form->type == 2 && form->flags[2] == '#')
		i += write(1, "0x", 2);
	if (*str[0] == '-')
	{
		i += write(1, "-", 1);
		*str = ft_strsub_free(*str, 1, ft_strlen(*str) - 1);
		form->cut = 1;
	}
	else if (form->flags[3] == '+')
		i += write(1, "+", 1);
	return (i);
}

int		printminusint2(t_form *form, char **str, int i)
{
	int	n;

	if (form->acu >= ((int)ft_strlen(*str) + form->m) && form->acu > 0)
	{
		n = form->acu + form->m;
		i += form->acu - ft_strlen(*str);
		while ((form->acu - (int)ft_strlen(*str)) > 0)
		{
			write(1, "0", 1);
			form->acu--;
		}
	}
	else
		n = ft_strlen(*str) + form->m;
	if ((form->type == 2 && form->flags[2] == '#') && form->m != 2)
		i += write(1, "0x", 2);
	i += write(1, *str, ft_strlen(*str));
	if (form->wide > 0 && form->wide > n)
		i += wideforint(form, form->wide - n);
	return (i);
}

int		printminusint(t_form *form, char **str)
{
	int i;

	i = 0;
	form->flags[0] = ' ';
	if ((*str[0] == '-' || (ft_strchr(form->flags, '+') != NULL) ||
	form->flags[1] == ' ') || (form->type == 2 && form->flags[2] == '#'))
	{
		form->m = 1;
		if (form->type == 2 && form->flags[2] == '#')
			form->m = 2;
		if (form->flags[1] == ' ' && *str[0] != '-' &&
		(ft_strchr(form->flags, '+') == NULL))
			i += write(1, " ", 1);
		else
			i += printsign(form, &(*str));
	}
	return (printminusint2(form, &(*str), i));
}
