/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 14:48:38 by dmorar            #+#    #+#             */
/*   Updated: 2019/03/28 18:00:27 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		octalint(t_form *form, unsigned long long int n)
{
	int		i;
	char	*str;

	i = 0;
	if (form->size == 0)
		n = (unsigned int)n;
	if (form->size == 1)
		n = (unsigned long int)n;
	if (form->size == 2)
		n = (unsigned long long int)n;
	if (form->size == 3)
		n = (unsigned short int)n;
	if (form->size == 4)
		n = (unsigned char)n;
	str = ft_itoa_base(n, 8);
	form->flags[3] = 'A';
	form->flags[1] = 'A';
	i += hexoct(form, &str);
	free(str);
	return (i);
}

int		hexalint(t_form *form, unsigned long long int n)
{
	int		i;
	char	*str;

	i = 0;
	if (form->size == 0)
		n = (unsigned int)n;
	if (form->size == 1)
		n = (unsigned long int)n;
	if (form->size == 2)
		n = (unsigned long long int)n;
	if (form->size == 3)
		n = (unsigned short int)n;
	if (form->size == 4)
		n = (unsigned char)n;
	if (form->type == 7)
		str = ft_itoa_base(n, 16);
	else
		str = ft_itoa_base_h(n, 16);
	form->flags[3] = 'A';
	form->flags[1] = 'A';
	i += hexoct(form, &str);
	free(str);
	return (i);
}

int		sizepointer(t_form *form, unsigned long long int n)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_itoa_base(n, 16);
	form->flags[3] = 'A';
	form->flags[1] = 'A';
	form->flags[2] = '#';
	i += printint(form, &str);
	free(str);
	return (i);
}

int		floatsize(t_form *form, long double n)
{
	int		i;
	char	*str;
	char	*str2;
	int		sym;

	i = 0;
	if (form->size == 1 || form->size == 0)
		n = (double)n;
	if (form->size == 5)
		n = (long double)n;
	sym = 0;
	str = changetostr(n);
	str2 = findzapyat(form, n, &sym);
	str = ft_strjoin_free(str, str2, 1, 1);
	str = rounding(str, sym);
	i += printfloat(form, str);
	return (i);
}
