/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:08:01 by aakhrif           #+#    #+#             */
/*   Updated: 2024/09/04 18:47:38 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_compare(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	sort(char **av, int ac)
{
	int		i;
	char	*s;

	i = 1;
	while (i < ac - 1)
	{
		if (ft_compare(av[i], av[i + 1]) > 0)
		{
			s = av[i];
			av[i] = av[i + 1];
			av[i + 1] = s;
			i = 0;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	j;

	j = 1;
	sort(av, ac);
	while (j < ac)
	{
		i = 0;
		while (av[j][i])
			write(1, &av[j][i++], 1);
		write(1, "\n", 1);
		j++;
	}
}
