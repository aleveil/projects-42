/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <aleveil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:49:41 by aleveil           #+#    #+#             */
/*   Updated: 2021/12/04 01:08:23 by aleveil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putbase(unsigned int nb, char *base)
{
	int				nb_print;
	unsigned int	base_len;

	nb_print = 0;
	base_len = ft_strlen(base);
	if (nb >= base_len)
	{
		nb_print += ft_putbase(nb / base_len, base);
		nb_print += ft_putchar(base[nb % base_len]);
	}
	else
		nb_print += ft_putchar(base[nb]);
	return (nb_print);
}
