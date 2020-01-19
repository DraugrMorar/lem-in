/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 22:10:20 by dmorar            #+#    #+#             */
/*   Updated: 2019/03/28 17:16:11 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		whatsize(t_form *form, long long int n)
{
	int		i;
	char	*str;

	i = 0;
	if (form->size == 0)
		n = (int)n;
	if (form->size == 1)
		n = (long int)n;
	if (form->size == 2)
	{
		n = (long long int)n;
		if (n == (-9223372036854775807 - 1))
			return (write(1, "-9223372036854775808", 20));
	}
	if (form->size == 3)
		n = (short int)n;
	if (form->size == 4)
		n = (char)n;
	str = changetostr(n);
	i = printint(form, &str);
	free(str);
	return (i);
}

int		sizeforunsign(t_form *form, unsigned long long int n)
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
	str = changeutostr(n);
	form->flags[3] = 'A';
	form->flags[1] = 'A';
	i += printint(form, &str);
	free(str);
	return (i);
}
