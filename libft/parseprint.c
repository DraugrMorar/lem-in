/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:31:59 by dmorar            #+#    #+#             */
/*   Updated: 2019/03/21 19:42:23 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		addsize(char *str, int i, t_form *pt)
{
	if (str[i] == 'l' || str[i] == 'h' || str[i] == 'L')
	{
		if (str[i] == 'l')
		{
			pt->size = 1;
			if (str[i + 1] == 'l' || str[i] == 'L')
				pt->size = 2;
		}
		else if (str[i] == 'h')
		{
			pt->size = 3;
			if (str[i + 1] == 'h')
				pt->size = 4;
		}
		else if (str[i] == 'L')
			pt->size = 5;
		while ((str[i] == 'l' || str[i] == 'h' || str[i] == 'L') &&
		str[i] != '\0')
			i++;
	}
	return (i);
}

int		addtype(char *str, int i, t_form *pt)
{
	int		t;

	t = 0;
	if ((str[i] != '%' && ft_strchr(TYPE, str[i]) == '\0') || str[i] == '\0')
		pt->type = 11;
	else if (ft_strchr(TYPE, str[i]) != NULL)
	{
		while (TYPE[t] != str[i])
			t++;
		pt->type = t;
		i++;
	}
	else if (str[i] == '%')
	{
		pt->type = 10;
		i++;
	}
	return (i);
}

int		addwide(char *str, int i, t_form *pt, va_list ap)
{
	if ((str[i] >= 49 && str[i] <= 57) || str[i] == '*')
	{
		if (str[i] >= 49 && str[i] <= 57)
		{
			pt->wide = ft_atoi(&str[i]);
			while (str[i] >= 48 && str[i] <= 57)
				i++;
		}
		if (str[i] == '*')
		{
			pt->wide = va_arg(ap, int);
			pt->wide < 0 ? pt->flags[4] = '-' : pt->flags[4];
			pt->wide < 0 ? pt->wide = -pt->wide : pt->wide;
			i++;
		}
	}
	return (i);
}

int		addaccu(char *str, int i, t_form *pt, va_list ap)
{
	if (str[i] == '.')
	{
		i++;
		if (str[i] >= 48 && str[i] <= 57)
			pt->acu = ft_atoi(&str[i]);
		else if (str[i] == '*')
			pt->acu = va_arg(ap, int);
		else if (!(str[i] >= 48 && str[i] <= 57) || !(str[i] == '*'))
			pt->acu = 0;
		while ((str[i] >= 48 && str[i] <= 57) || str[i] == '*')
			i++;
	}
	return (i);
}

int		addflags(char *str, int i, t_form *pt)
{
	if (str[i] == '0' || str[i] == ' ' ||
	str[i] == '#' || str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '0')
			pt->flags[0] = '0';
		else if (str[i] == 32)
			pt->flags[1] = ' ';
		else if (str[i] == 35)
			pt->flags[2] = '#';
		else if (str[i] == 43)
			pt->flags[3] = '+';
		else if (str[i] == 45)
			pt->flags[4] = '-';
		i++;
	}
	return (i);
}
