/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 23:28:55 by aakhrif           #+#    #+#             */
/*   Updated: 2024/09/04 21:23:17 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	check_base(char *base, int *p)
{
	int	j;
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] <= 32)
			return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = 0;
		while (j < i)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	*p = i;
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		i;
	long	nb;

	i = 0;
	nb = nbr;
	if (check_base(base, &i))
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb = -nb;
		}
		if (nb < i)
			ft_putchar(base[nb]);
		else
		{
			ft_putnbr_base(nb / i, base);
			ft_putnbr_base(nb % i, base);
		}
	}
}
