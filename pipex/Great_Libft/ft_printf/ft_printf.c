/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:29:17 by jodone            #+#    #+#             */
/*   Updated: 2025/11/05 15:15:28 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_printf(const char *fmt, int *i, va_list args, int *c)
{
	if (fmt[(*i) + 1] == 'c')
		ft_putchar_print(va_arg(args, int), 1, c);
	else if (fmt[(*i) + 1] == 's')
		ft_putstr_print(va_arg(args, char *), 1, c);
	else if (fmt[(*i) + 1] == 'p')
		ft_ulputnbr_ptr((unsigned long)va_arg(args, void *), c);
	else if (fmt[(*i) + 1] == 'i' || fmt[(*i) + 1] == 'd')
		ft_putnbr_base(va_arg(args, int), "0123456789", c);
	else if (fmt[(*i) + 1] == 'u')
		ft_uputnbr_base(va_arg(args, unsigned int), "0123456789", c);
	else if (fmt[(*i) + 1] == 'x')
		ft_itoax(va_arg(args, unsigned int), 1, c);
	else if (fmt[(*i) + 1] == 'X')
		ft_itoax(va_arg(args, unsigned int), 0, c);
	else if (fmt[(*i) + 1] == '%')
		ft_putchar_print('%', 1, c);
	else
	{
		ft_putchar_print(fmt[(*i)], 1, c);
		(*i)--;
	}
	(*i)++;
}

int	ft_printf(const char *fmt, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%')
			format_printf(fmt, &i, args, &count);
		else
			ft_putchar_print(fmt[i], 1, &count);
		i++;
	}
	va_end(args);
	return (count);
}
