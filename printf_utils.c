/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvila <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:16:39 by alvila            #+#    #+#             */
/*   Updated: 2025/11/14 17:16:40 by alvila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_pf_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_pf_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_pf_putstr(char *s)
{
	size_t	len;

	if (!s)
		return (ft_pf_putstr("(null)"));
	len = ft_pf_strlen(s);
	if (write(1, s, len) == -1)
		return (-1);
	return ((int)len);
}
