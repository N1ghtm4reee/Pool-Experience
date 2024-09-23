/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:11:30 by aakhrif           #+#    #+#             */
/*   Updated: 2024/09/02 14:20:28 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	hex_ascii(int c)
{
	char	*base;

	base = "0123456789abcdef";
	ft_putchar(base[c / 16]);
	ft_putchar(base[c % 16]);
}

void	print_address(void *addr)
{
	char	buf[16];
	char	*base;
	long	add;
	int		counter;

	base = "0123456789abcdef";
	add = (long )addr;
	counter = 0;
	while (counter < 16)
	{
		buf[counter] = base[add % 16];
		add /= 16;
		counter++;
	}
	while (counter >= 0)
		ft_putchar(buf[counter--]);
	write(1, ": ", 2);
}

void	print_ascii(void *addr, unsigned int size)
{
	unsigned int	i;
	int				c;
	char			*str;
	int				counter;

	str = (char *)addr;
	i = 0;
	counter = 0;
	while (str[i] && i < size && counter < 16)
	{
		c = str[i];
		hex_ascii(c);
		i++;
		counter++;
		if (counter % 2 == 0)
			ft_putchar(' ');
	}
	while (counter < 16)
	{
		write(1, "  ", 2);
		counter++;
		if (counter % 2 == 0)
			ft_putchar(' ');
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	*str;
	int				counter;

	str = (unsigned char *)addr;
	i = 0;
	while (str[i] && i < size && (int )size > 0)
	{
		print_address(addr);
		print_ascii(addr, size);
		counter = 0;
		while (str[i] && i < size && counter < 16)
		{
			if (str[i] >= 32 && str[i] <= 126)
				ft_putchar(str[i]);
			else
				ft_putchar('.');
			i++;
			counter++;
		}
		addr += 16;
		write(1, "\n", 1);
	}
	return (addr);
}
