/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:05:03 by dmorar            #+#    #+#             */
/*   Updated: 2019/03/28 16:05:56 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		writediftype(t_form *lst, va_list ap)
{
	if (lst->type == 0)
		return (printchar(lst, va_arg(ap, int)));
	else if (lst->type == 1)
		return (printstr(lst, va_arg(ap, char *)));
	else if (lst->type == 2)
		return (sizepointer(lst, va_arg(ap, unsigned long long int)));
	else if (lst->type == 3 || lst->type == 4)
		return (whatsize(lst, va_arg(ap, long long int)));
	else if (lst->type == 5)
		return (octalint(lst, va_arg(ap, unsigned long long int)));
	else if (lst->type == 6)
		return (sizeforunsign(lst, va_arg(ap, unsigned long long int)));
	else if (lst->type == 7 || lst->type == 8)
		return (hexalint(lst, va_arg(ap, unsigned long long int)));
	else if (lst->type == 10)
		return (printchar(lst, '%'));
	else if (lst->type == 9)
	{
		if (lst->size == 5)
			return (floatsize(lst, va_arg(ap, long double)));
		else
			return (floatsize(lst, va_arg(ap, double)));
	}
	return (0);
}

int		ft_printf2(char *str, va_list ap, t_form *lst)
{
	int			i;
	int			count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i += ifpercent(&str[i], lst, ap);
			count += writediftype(lst, ap);
			free(lst->flags);
		}
		else if (str[i] == '%' && str[i + 1] == '\0')
			i++;
		else if ((str[i] == '%' && str[i + 1] == '%') ||
		(str[i] != '%' && str[i] != '\0'))
		{
			if (str[i] == '%' && str[i + 1] == '%')
				i++;
			ft_putchar(str[i++]);
			count++;
		}
	}
	return (count);
}

int		ft_printf(char *str, ...)
{
	int		count;
	t_form	*lst;
	va_list	ap;

	count = 0;
	va_start(ap, str);
	lst = (t_form *)malloc(sizeof(t_form));
	count = ft_printf2(str, ap, lst);
	va_end(ap);
	free(lst);
	return (count);
}
