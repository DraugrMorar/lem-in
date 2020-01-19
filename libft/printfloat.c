/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfloat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:05:28 by dmorar            #+#    #+#             */
/*   Updated: 2019/03/28 18:01:28 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*findzapyat(t_form *form, long double num, int *sym)
{
	char			*new;
	int				i;
	long long int	p;
	int				j;

	i = 6;
	(num < 0) ? (num = -num) : (num);
	if (form->acu != -1)
		i = form->acu;
	new = (char *)malloc(sizeof(char) * i + 1);
	new[0] = '.';
	new[i + 1] = '\0';
	j = 1;
	p = (long long int)num;
	num -= p;
	while (i-- > 0)
	{
		num *= 10;
		new[j++] = (int)num + '0';
		p = (long long int)num;
		num -= p;
	}
	num *= 10;
	*sym = (int)num;
	return (new);
}

char	*rounding2(char *str, int i)
{
	i--;
	while (str[i] == '9')
	{
		str[i] = '0';
		i--;
	}
	i++;
	if (str[i] == '0' && i == 0)
		str = ft_strjoin_free("1", str, 0, 1);
	else
	{
		i--;
		str[i] += 1;
	}
	return (str);
}

char	*rounding(char *str, int sym)
{
	int		i;

	i = ft_strlen(str) - 1;
	if (sym >= 5)
	{
		while (str[i] == '9')
		{
			str[i] = '0';
			i--;
		}
		if (ft_isdigit(str[i]) == 1)
		{
			str[i] += 1;
			return (str);
		}
		if (str[i] == '.')
			str = rounding2(str, i);
	}
	i = 0;
	while (ft_isdigit(str[i]) == 1 || str[i] == '.' || str[i] == '-')
		i++;
	str[i] = '\0';
	return (str);
}

int		printfloat(t_form *form, char *str)
{
	int		i;
	int		len;

	len = ft_strlen(str);
	i = 0;
	if (str[len - 1] == '.' && form->flags[2] != '#')
	{
		str = ft_strsub_free(str, 0, (len - 1));
		len--;
	}
	form->acu = -1;
	form->flags[2] = 'A';
	form->type = 4;
	i += printint(form, &str);
	free(str);
	return (i);
}
