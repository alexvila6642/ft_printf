/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvila <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:17:10 by alvila            #+#    #+#             */
/*   Updated: 2025/11/18 20:26:43 by alvila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_pf_puthex_rec(unsigned int n, int uppercase)
{
	char	*base;
	int		len;
	int		ret;

	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	len = 0;
	if (n >= 16)
	{
		ret = ft_pf_puthex_rec(n / 16, uppercase);
		if (ret == -1)
			return (-1);
		len += ret;
	}
	ret = ft_pf_putchar(base[n % 16]);
	if (ret == -1)
		return (-1);
	return (len + 1);
}

int	ft_pf_puthex(unsigned int n, int uppercase)
{
	return (ft_pf_puthex_rec(n, uppercase));
}

static int	ft_pf_putptr_rec(unsigned long n)
{
	char	*base;
	int		len;
	int		ret;

	base = "0123456789abcdef";
	len = 0;
	if (n >= 16)
	{
		ret = ft_pf_putptr_rec(n / 16);
		if (ret == -1)
			return (-1);
		len += ret;
	}
	ret = ft_pf_putchar(base[n % 16]);
	if (ret == -1)
		return (-1);
	return (len + 1);
}

int	ft_pf_putptr(void *p)
{
	unsigned long	n;
	int				len;
	int				ret;

	n = (unsigned long)p;
	if (n == 0)
	{
		len = (ft_pf_putstr("(nil)"));
		if (len == -1)
			return (-1);
		return (len);
	}
	len = ft_pf_putstr("0x");
	if (len == -1)
		return (-1);
	ret = ft_pf_putptr_rec(n);
	if (ret == -1)
		return (-1);
	return (len + ret);
}
