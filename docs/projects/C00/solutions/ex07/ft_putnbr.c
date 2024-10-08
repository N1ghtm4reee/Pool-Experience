/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:23:26 by aakhrif           #+#    #+#             */
/*   Updated: 2024/08/31 14:01:52 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	buffer_init(char *str, long nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	while (nb)
	{
		str[i++] = (nb % 10) + 48;
		nb /= 10;
	}
	str[i--] = '\0';
	while (i >= 0)
		ft_putchar(str[i--]);
}

void	ft_putnbr(int nb)
{
	long	nbr;
	char	buffer[11];

	nbr = nb;
	if (nbr == 0)
	{
		write(1, "0", 1);
		return ;
	}
	buffer_init(buffer, nbr);
}
