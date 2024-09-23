/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:02:10 by aakhrif           #+#    #+#             */
/*   Updated: 2024/09/18 13:03:10 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_sum(int nb1, int nb2)
{
	int	res;

	res = nb1 + nb2;
	ft_putnbr(res);
}

void	ft_sub(int nb1, int nb2)
{
	int	res;

	res = nb1 - nb2;
	ft_putnbr(res);
}

void	ft_mult(int nb1, int nb2)
{
	int	res;

	res = nb1 * nb2;
	ft_putnbr(res);
}

void	ft_mod(int nb1, int nb2)
{
	int	res;

	res = nb1 % nb2;
	ft_putnbr(res);
}

void	ft_div(int nb1, int nb2)
{
	int	res;

	res = nb1 / nb2;
	ft_putnbr(res);
}
