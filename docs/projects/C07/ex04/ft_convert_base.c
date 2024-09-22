/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 08:34:11 by aakhrif           #+#    #+#             */
/*   Updated: 2024/09/16 10:33:37 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		check_base(char *base);
char	*itoabase(long nb, char *base);

int	ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	i_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

long	ft_reset_base(char *str, int i, char *base, int base_len)
{
	long	res;
	int		nb;

	res = 0;
	while (str[i])
	{
		nb = i_index(str[i], base);
		if (nb >= 0)
			res = (res * base_len) + nb;
		else
			break ;
		i++;
	}
	return (res);
}

long	atoibase(char *str, char *base_from)
{
	int		i;
	long	sign;
	long	result;
	int		base_len;

	i = 0;
	result = 0;
	sign = 1;
	base_len = check_base(base_from);
	if (!base_len || !str[i])
		return (0);
	while (ft_isspace(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	result = ft_reset_base(str, i, base_from, base_len);
	result = result * sign;
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*n;
	long	nb;

	if (check_base(base_from) == 0 || check_base(base_to) == 0)
		return (0);
	nb = atoibase(nbr, base_from);
	n = itoabase(nb, base_to);
	return (n);
}
