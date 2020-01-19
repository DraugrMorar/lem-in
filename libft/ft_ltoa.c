/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 13:56:35 by dmorar            #+#    #+#             */
/*   Updated: 2019/04/14 20:24:17 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int	countnum(long long int n)
{
	int		i;

	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n = (n / 10);
		i++;
	}
	return (i);
}

char		*changetostr(long long int n)
{
	char	*new;
	int		len;
	int		i;

	i = 0;
	len = countnum(n);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (new == 0)
		return (NULL);
	new[len] = '\0';
	len--;
	if (n < 0)
	{
		n = -n;
		new[i++] = '-';
	}
	while (len >= i)
	{
		new[len] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (new);
}
