/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvila <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:17:10 by alvila            #+#    #+#             */
/*   Updated: 2025/12/31 17:10:01 by alvila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pf_puthex(unsigned int n, int uppercase)
{
	char	*base;
	char	buf[16];
	int		i;
	int		len;

	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	i = 0;
	if (n == 0)
		return (ft_pf_putchar('0'));
	while (n > 0)
	{
		buf[i++] = base[n % 16];
		n /= 16;
	}
	len = i;
	while (--i >= 0)
		ft_pf_putchar(buf[i]);
	return (len);
}

static int	ft_pf_putptr_hex(unsigned long n)
{
	char	buf[16];
	char	*base;
	int		i;
	int		len;

	base = "0123456789abcdef";
	i = 0;
	while (n > 0)
	{
		buf[i++] = base[n % 16];
		n /= 16;
	}
	len = i;
	while (--i >= 0)
		if (ft_pf_putchar(buf[i]) == -1)
			return (-1);
	return (len);
}

int	ft_pf_putptr(void *p)
{
	unsigned long	n;
	int				len;
	int				ret;

	if (p == NULL)
		return (ft_pf_putstr("(nil)"));
	n = (unsigned long)p;
	len = ft_pf_putstr("0x");
	if (len == -1)
		return (-1);
	ret = ft_pf_putptr_hex(n);
	if (ret == -1)
		return (-1);
	return (len + ret);
}
