/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <aleveil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 12:29:34 by aleveil           #+#    #+#             */
/*   Updated: 2021/12/04 00:05:14 by aleveil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putunbr(unsigned int nb)
{
	int	nb_print;

	nb_print = 0;
	if (nb >= 10)
	{
		nb_print += ft_putnbr(nb / 10);
		nb_print += ft_putchar(nb % 10 + '0');
	}
	else if (nb < 10)
		nb_print += ft_putchar(nb + '0');
	return (nb_print);
}
