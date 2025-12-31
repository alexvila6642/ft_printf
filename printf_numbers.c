/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvila <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:16:44 by alvila            #+#    #+#             */
/*   Updated: 2025/12/31 17:14:36 by alvila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pf_putunbr(unsigned int n)
{
	char	buf[10];
	int		i;
	int		ret;
	int		len;

	i = 0;
	len = 0;
	if (n == 0)
		return (ft_pf_putchar('0'));
	while (n > 0)
	{
		buf[i++] = '0' + (n % 10);
		n /= 10;
	}
	while (--i >= 0)
	{
		ret = ft_pf_putchar(buf[i]);
		if (ret == -1)
			return (-1);
		len += ret;
	}
	return (len);
}

int	ft_pf_putnbr(int n)
{
	int	ret;
	int	len;

	len = 0;
	if (n < 0)
	{
		ret = ft_pf_putchar('-');
		if (ret == -1)
			return (-1);
		len += ret;
		if (n == -2147483648)
			return (len + ft_pf_putunbr(2147483648u));
		n = -n;
	}
	ret = ft_pf_putunbr((unsigned int)n);
	if (ret == -1)
		return (-1);
	return (len + ret);
}
