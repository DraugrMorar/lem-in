/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexoct2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 15:33:25 by dmorar            #+#    #+#             */
/*   Updated: 2019/03/27 16:40:32 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		acuforhexoct(t_form *form, int n)
{
	int		i;
	int		len;

	i = 0;
	len = form->acu - n;
	while (len > 0)
	{
		i += write(1, "0", 1);
		len--;
	}
	return (i);
}

int		minushexoct2(t_form *form, char **str)
{
	int i;

	i = 0;
	if (form->type == 5)
		*str = ft_strjoin_free("0", *str, 0, 1);
	else if (form->type == 7)
	{
		i += write(1, "0x", 2);
		form->m = 2;
	}
	else if (form->type == 8)
	{
		i += write(1, "0X", 2);
		form->m = 2;
	}
	form->flags[2] = 'A';
	return (i);
}

int		minushexoct(t_form *form, char **str)
{
	int		i;
	int		len;
	int		n;

	i = 0;
	form->flags[0] = ' ';
	if (form->flags[2] == '#')
		i += minushexoct2(form, &(*str));
	n = ft_strlen(*str);
	if (form->acu > -1)
		i += acuforhexoct(form, n);
	i += write(1, *str, n);
	if (form->acu > n)
		len = form->wide - form->acu - form->m;
	else
		len = form->wide - n - form->m;
	if (len > 0)
		i += wideforint(form, len);
	return (i);
}
