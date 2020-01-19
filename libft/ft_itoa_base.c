/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 12:58:25 by dmorar            #+#    #+#             */
/*   Updated: 2019/04/02 13:57:46 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int		ft_countnum_base(unsigned long long int n, int base)
{
	int		i;

	i = 0;
	if (n == 0)
		i++;
	while (n > 0)
	{
		n = (n / base);
		i++;
	}
	return (i);
}

char			*ft_itoa_base(unsigned long long int n, int base)
{
	char	*new;
	int		len;
	int		re;

	len = ft_countnum_base(n, base);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (new == 0)
		return (NULL);
	new[len] = '\0';
	len--;
	while (len >= 0)
	{
		re = n % base;
		if (re > 9)
		{
			re = re - 10;
			new[len] = HEX[re];
		}
		else
			new[len] = re + '0';
		n = n / base;
		len--;
	}
	return (new);
}

char			*ft_itoa_base_h(unsigned long long int n, int base)
{
	char	*new;
	int		len;
	int		re;

	len = ft_countnum_base(n, base);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (new == 0)
		return (NULL);
	new[len] = '\0';
	len--;
	while (len >= 0)
	{
		re = n % base;
		if (re > 9)
		{
			re = re - 10;
			new[len] = HEX2[re];
		}
		else
			new[len] = re + '0';
		n = n / base;
		len--;
	}
	return (new);
}
