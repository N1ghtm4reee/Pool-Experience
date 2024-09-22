/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 23:50:34 by aakhrif           #+#    #+#             */
/*   Updated: 2024/09/04 20:53:51 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_error(char *base, int *p)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = 0;
		while (i < j)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	*p = i;
	return (1);
}

int	base_reset(char str, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == str)
			return (i);
		i++;
	}
	return (-1);
}

int	skip(char *str, int *p)
{
	int	i;
	int	s;

	s = 1;
	i = 0;
	while (str[i] <= 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	*p = i;
	return (s);
}

int	ft_atoi_base(char *str, char *base)
{
	int	r;
	int	n;
	int	i;
	int	bl;
	int	s;

	i = 0;
	s = 1;
	bl = 0;
	r = 0;
	n = 0;
	if (check_error(base, &bl))
	{
		s = skip(str, &i);
		n = base_reset(str[i], base);
		while (n != -1)
		{
			r = (r * bl) + n;
			i++;
			n = base_reset(str[i], base);
		}
	}
	else
		return (0);
	return (s * r);
}
