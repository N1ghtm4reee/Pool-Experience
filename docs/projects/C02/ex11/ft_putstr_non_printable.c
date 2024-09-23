/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:30:57 by aakhrif           #+#    #+#             */
/*   Updated: 2024/09/02 16:32:46 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	convert(unsigned char c)
{
	int		p;
	char	*base;

	p = c;
	base = "0123456789abcdef";
	ft_putchar('\\');
	ft_putchar(base[p / 16]);
	ft_putchar(base[p % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 32 && str[i] <= 126))
			convert(str[i]);
		else
			write(1, &str[i], 1);
		i++;
	}
}
