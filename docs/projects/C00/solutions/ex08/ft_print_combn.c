/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:38:22 by aakhrif           #+#    #+#             */
/*   Updated: 2024/08/28 16:27:17 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_combs(int n, int array[10])
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(array[i] + 48);
		i++;
	}
	if (array[0] != (10 - n))
		write(1, ", ", 2);
}

int	check_order(int n, int array[10])
{
	int	i;

	i = 0;
	while (i + 1 < n)
	{
		if (array[i] >= array[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void	comb1(int n, int array[10])
{
	int	flag;
	int	i;

	while (array[0] <= (10 - n))
	{
		flag = 0;
		i = 0;
		if (check_order (n, array))
			flag = 1;
		if (flag == 0)
			print_combs(n, array);
		if (array[0] == 9)
			return ;
		i = n - 1;
		array[i]++;
		while (i >= 0)
		{
			if (array[i] > 9)
			{
				array[i - 1]++;
				array[i] = 0;
			}
			i--;
		}
	}
}

void	ft_print_combn(int n)
{
	int	array[10];
	int	i;

	i = 0;
	if (n >= 1 && n <= 9)
	{
		while (i < n)
		{
			array[i] = i;
			i++;
		}
		comb1(n, array);
	}
}
