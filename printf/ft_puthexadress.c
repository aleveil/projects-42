/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexadress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <aleveil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 00:07:00 by aleveil           #+#    #+#             */
/*   Updated: 2021/12/04 01:27:31 by aleveil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_puthexadress(unsigned long adress)
{
	int	nb_print;

	nb_print = 0;
	nb_print += ft_putstr("0x");
	nb_print += ft_putbaselong(adress, "0123456789abcdef");
	return (nb_print);
}
