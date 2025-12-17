/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvila <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:16:37 by alvila            #+#    #+#             */
/*   Updated: 2025/11/14 17:16:38 by alvila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>

int		ft_printf(const char *fmt, ...);

int		ft_pf_putchar(char c);
int		ft_pf_putstr(char *s);
size_t	ft_pf_strlen(const char *s);

int		ft_pf_putnbr(int n);
int		ft_pf_putunbr(unsigned int n);
int		ft_pf_puthex(unsigned int n, int uppercase);
int		ft_pf_putptr(void *p);

#endif
