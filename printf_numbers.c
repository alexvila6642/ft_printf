/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvila <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:16:44 by alvila            #+#    #+#             */
/*   Updated: 2025/11/14 17:41:02 by alvila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_pf_putnbr_rec(long n)
{
	char	c;
	int		len;
	int		res;

	len = 0;
	if (n >= 10)
	{
		res = ft_pf_putnbr_rec(n / 10);
		if (res == -1)
			return (-1);
		len += res;
	}
	c = (char)('0' + (n % 10));
	res = ft_pf_putchar(c);
	if (res == -1)
		return (-1);
	return (len + 1);
}

int	ft_pf_putnbr(int n)
{
	long	nb;
	int		len;
	int		res;

	nb = (long)n;
	len = 0;
	if (nb < 0)
	{
		res = ft_pf_putchar('-');
		if (res == -1)
			return (-1);
		len += res;
		nb = -nb;
	}
	res = ft_pf_putnbr_rec(nb);
	if (res == -1)
		return (-1);
	return (len + res);
}

static int	ft_pf_putunbr_rec(unsigned int n)
{
	char	c;
	int		len;
	int		res;

	len = 0;
	if (n >= 10)
	{
		res = ft_pf_putunbr_rec(n / 10);
		if (res == -1)
			return (-1);
		len += res;
	}
	c = (char)('0' + (n % 10));
	res = ft_pf_putchar(c);
	if (res == -1)
		return (-1);
	return (len + 1);
}

int	ft_pf_putunbr(unsigned int n)
{
	return (ft_pf_putunbr_rec(n));
}
