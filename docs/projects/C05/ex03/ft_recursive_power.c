/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:55:55 by aakhrif           #+#    #+#             */
/*   Updated: 2024/09/04 12:15:11 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power == 0 && nb == 0)
		return (1);
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	nb *= ft_recursive_power(nb, power - 1);
	return (nb);
}
