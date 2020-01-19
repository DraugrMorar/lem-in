/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 19:34:08 by dmorar            #+#    #+#             */
/*   Updated: 2019/03/27 15:23:56 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	fillerforstruct(t_form *smt)
{
	int		i;

	i = 6;
	smt->flags = ft_memalloc(i);
	smt->flags[--i] = '\0';
	while (i-- > 1)
		smt->flags[i] = 'A';
	smt->flags[i] = ' ';
	smt->size = 0;
	smt->wide = 0;
	smt->m = 0;
	smt->cut = 0;
	smt->acu = -1;
}

int		ifpercent(char *str, t_form *smt, va_list ap)
{
	int		i;

	i = 6;
	fillerforstruct(smt);
	i = 0;
	if (str[i] == '%')
		i++;
	while (str[i] == '.' || str[i] == ' ' || str[i] == '+' ||
	str[i] == '-' || (ft_isdigit(str[i]) == 1) || str[i] == '#' ||
	str[i] == '*' || str[i] == 'l' || str[i] == 'h' || str[i] == 'L')
	{
		i = addflags(str, i, smt);
		i = addwide(str, i, smt, ap);
		i = addaccu(str, i, smt, ap);
		i = addsize(str, i, smt);
	}
	i = addtype(str, i, smt);
	return (i);
}
