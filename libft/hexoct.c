/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexoct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 20:16:19 by dmorar            #+#    #+#             */
/*   Updated: 2019/03/28 16:54:17 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		hexoct4(t_form *form, char **str, int i, int n)
{
	int	len;

	if (form->acu > n)
		len = form->wide - form->acu - form->m;
	else
		len = form->wide - n - form->m;
	if (len > 0)
		i += wideforint(form, len);
	if (form->flags[2] == '#' && (form->type == 7 || form->type == 8)
	&& form->flags[0] != '0')
	{
		if (form->type == 7)
			i += write(1, "0x", 2);
		else if (form->type == 8)
			i += write(1, "0X", 2);
		form->flags[2] = 'A';
		form->m = 2;
	}
	if (form->acu != -1 && form->acu > n)
		i += acuforhexoct(form, n);
	i += write(1, (*str), n);
	return (i);
}

int		hexoct3(t_form *form, char **str)
{
	int i;
	int n;

	i = 0;
	if (form->flags[2] == '#' && (form->type == 7 || form->type == 8))
		form->m = 2;
	n = ft_strlen(*str);
	if (form->flags[2] == '#' && (form->type == 7 || form->type == 8) &&
	form->flags[0] == '0' && (form->wide > n || form->wide > form->acu))
	{
		if (form->type == 7)
			i += write(1, "0x", 2);
		else if (form->type == 8)
			i += write(1, "0X", 2);
		form->flags[2] = 'A';
	}
	return (hexoct4(form, &(*str), i, n));
}

int		hexoct2(t_form *form, char **str)
{
	int n;

	n = ft_strlen(*str);
	if (form->flags[2] == '#')
	{
		if (form->type == 5)
		{
			form->flags[2] = 'A';
			(*str) = ft_strjoin_free("0", (*str), 0, 1);
		}
		else if (form->type == 7 && (form->wide < form->acu &&
		form->wide < n + 2) && form->flags[0] == '0')
		{
			form->flags[2] = 'A';
			(*str) = ft_strjoin_free("0x", (*str), 0, 1);
		}
		else if (form->type == 8 && (form->wide < form->acu &&
		form->wide < n + 2) && form->flags[0] == '0')
		{
			form->flags[2] = 'A';
			(*str) = ft_strjoin_free("0X", (*str), 0, 1);
		}
	}
	return (hexoct3(form, &(*str)));
}

int		hexoct(t_form *f, char **s)
{
	if (((f->type == 7 || f->type == 8) && (*s)[0] == '0' && ft_strlen(*s) == 1
	&& f->flags[2] == '#' && f->acu == -1 && f->wide == 0) || ((f->type == 7 ||
	f->type == 8) && (*s)[0] == '0' && ft_strlen(*s) == 1 && f->wide == 0 &&
	f->acu == 1) || (f->type == 5 && (*s)[0] == '0' && ft_strlen(*s) == 1 &&
	f->flags[2] == '#' && f->wide == 0 && f->acu <= 0))
		return (write(1, "0", 1));
	if ((f->type == 5 && (*s)[0] == '0' && ft_strlen(*s) == 1 && f->wide == 0
	&& f->acu == 0 && f->flags[2] != '#') || ((f->type == 7 || f->type == 8)
	&& (*s)[0] == '0' && ft_strlen((*s)) == 1 && f->wide == 0 && f->acu == 0))
		return (0);
	if (f->acu >= 0)
		f->flags[0] = ' ';
	if (f->type == 5 && (*s)[0] == '0' && ft_strlen(*s) == 1 &&
	f->flags[2] == '#')
		f->flags[2] = 'A';
	if (((f->type == 7 || f->type == 8) && (*s)[0] == '0' && ft_strlen(*s) == 1
	&& f->acu == 0) || (f->type == 5 && (*s)[0] == '0' && ft_strlen(*s) == 1 &&
	f->acu == 0))
		(*s)[0] = ' ';
	if ((f->type == 7 || f->type == 8) && (*s)[0] == '0' && ft_strlen(*s) == 1)
		f->flags[2] = 'A';
	if (ft_strchr(f->flags, '-') != NULL)
		return (minushexoct(f, &(*s)));
	return (hexoct2(f, &(*s)));
}
