/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvila <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:18:04 by alvila            #+#    #+#             */
/*   Updated: 2026/01/06 13:34:37 by alvila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_pf_conv(char c, va_list ap)
{
	if (c == 'c')
		return (ft_pf_putchar(va_arg(ap, int)));
	if (c == 's')
		return (ft_pf_putstr(va_arg(ap, char *)));
	if (c == 'p')
		return (ft_pf_putptr(va_arg(ap, void *)));
	if (c == 'd' || c == 'i')
		return (ft_pf_putnbr(va_arg(ap, int)));
	if (c == 'u')
		return (ft_pf_putunbr(va_arg(ap, unsigned int)));
	if (c == 'x')
		return (ft_pf_puthex(va_arg(ap, unsigned int), 0));
	if (c == 'X')
		return (ft_pf_puthex(va_arg(ap, unsigned int), 1));
	if (c == '%')
		return (ft_pf_putchar('%'));
	return (0);
}

static int	ft_vprintf(const char *fmt, va_list ap)
{
	int	i;
	int	len;
	int	tmp;

	i = 0;
	len = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%' && fmt[i + 1] != '\0')
		{
			i++;
			tmp = ft_pf_conv(fmt[i], ap);
		}
		else
			tmp = ft_pf_putchar(fmt[i]);
		if (tmp == -1)
			return (-1);
		len += tmp;
		i++;
	}
	return (len);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		len;

	if (!fmt)
		return (0);
	va_start(ap, fmt);
	len = ft_vprintf(fmt, ap);
	va_end(ap);
	return (len);
}
