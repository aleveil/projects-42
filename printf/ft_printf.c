/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <aleveil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:47:22 by aleveil           #+#    #+#             */
/*   Updated: 2021/12/04 01:25:45 by aleveil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_printarg(char c, va_list args)
{
	int	nb_print;

	nb_print = 0;
	if (c == 'c')
		nb_print = ft_putchar(va_arg(args, int ));
	else if (c == 's')
		nb_print = ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		nb_print = ft_puthexadress(va_arg(args, unsigned long));
	else if (c == 'd' || c == 'i')
		nb_print = ft_putnbr(va_arg(args, int ));
	else if (c == 'u')
		nb_print = ft_putunbr(va_arg(args, unsigned int ));
	else if (c == 'x')
		nb_print = ft_putbase(va_arg(args, int), "0123456789abcdef");
	else if (c == 'X')
		nb_print = ft_putbase(va_arg(args, int), "0123456789ABCDEF");
	else if (c == '%')
		nb_print = ft_putchar('%');
	else
		return (0);
	return (nb_print);
}

int	ft_printf(const char *s, ...)
{
	size_t	i;
	va_list	args;
	int		nb_print;

	i = 0;
	va_start(args, s);
	nb_print = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			nb_print += ft_printarg(s[i + 1], args);
			i++;
		}
		else
			nb_print += ft_putchar(s[i]);
		i++;
	}
	return (nb_print);
}
