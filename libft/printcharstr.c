/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printcharstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:30:29 by dmorar            #+#    #+#             */
/*   Updated: 2019/03/28 16:30:33 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		printwide(t_form *form, int str)
{
	int i;

	i = 0;
	if ((form->wide -= str) > 0)
	{
		if ((ft_strchr(form->flags, '0') != NULL && ft_strchr(form->flags, '-')
		== NULL) || form->type == 3)
		{
			while (form->wide > 0)
			{
				i += write(1, "0", 1);
				form->wide--;
			}
		}
		else
		{
			while (form->wide > 0)
			{
				i += write(1, " ", 1);
				form->wide--;
			}
		}
	}
	return (i);
}

int		printstr(t_form *form, char *str)
{
	int	i;
	int check;

	check = 0;
	i = 0;
	if (str == 0)
		str = "(null)";
	if (form->acu != -1)
	{
		str = ft_strsub(str, 0, form->acu);
		check = 1;
	}
	if (ft_strchr(form->flags, '-') != NULL)
	{
		i += write(1, str, ft_strlen(str));
		i += printwide(form, (int)ft_strlen(str));
	}
	else
	{
		i += printwide(form, (int)ft_strlen(str));
		i += write(1, str, ft_strlen(str));
	}
	if (check == 1)
		free(str);
	return (i);
}

int		printchar(t_form *form, int c)
{
	int i;

	i = 0;
	if (ft_strchr(form->flags, '-') != NULL)
	{
		i += write(1, &c, 1);
		i += printwide(form, 1);
	}
	else
	{
		i += printwide(form, 1);
		i += write(1, &c, 1);
	}
	return (i);
}
