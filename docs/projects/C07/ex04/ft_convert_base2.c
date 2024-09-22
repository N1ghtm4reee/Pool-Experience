/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 18:07:46 by aakhrif           #+#    #+#             */
/*   Updated: 2024/09/16 10:29:11 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_isspace(char c);

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!base[i] || !base[i + 1])
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || ft_isspace(base[i]))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	n_len(long nb, char *base)
{
	int	i;
	int	base_len;

	i = 0;
	base_len = check_base(base);
	if (base_len == 0)
		return (0);
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	while (nb > 0)
	{
		nb /= base_len;
		i++;
	}
	return (i);
}

void	itoabase2(char *sbase, long nb, char *base, int base_len)
{
	int	i;
	int	len;

	len = n_len(nb, base);
	i = len - 1;
	if (nb < 0)
	{
		sbase[0] = '-';
		nb = -nb;
	}
	sbase[i + 1] = '\0';
	if (nb == 0)
		sbase[0] = base[0];
	while (nb > 0)
	{
		sbase[i--] = base[nb % base_len];
		nb /= base_len;
	}
}

char	*itoabase(long nb, char *base)
{
	int		base_len;
	int		size;
	char	*nbr;

	base_len = check_base(base);
	size = n_len(nb, base);
	if (base_len == 0)
		return (NULL);
	nbr = malloc(size + 1);
	if (!nbr)
		return (NULL);
	itoabase2(nbr, nb, base, base_len);
	return (nbr);
}
