/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:15:22 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/18 21:04:02 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_check_chars(char **tab, int *i, char *c)
{
	if (tab[i[0]][i[1]] != c[0] && tab[i[0]][i[1]] != c[1]
	&& tab[i[0]][i[1]] != c[2])
		return (1);
	return (0);
}

int	ft_checker(int left, int up, int upleft)
{
	if (left <= up && left <= upleft)
		return (left + 1);
	if (upleft <= up && upleft <= left)
		return (upleft + 1);
	if (up <= upleft && up <= left)
		return (up + 1);
	return (0);
}

int	**ft_char_arr_to_int_arr(char **tab, int size_y, int size_x, char *c)
{
	int	i[2];
	int	**ret;

	i[0] = 0;
	i[1] = 0;
	ret = (int **) malloc(sizeof(int *) * size_y);
	if (ret == NULL)
		exit(1);
	while (i[0] < size_y)
	{
		ret[i[0]] = malloc(sizeof(int) * size_x);
		while (i[1] < size_x)
		{
			if (ft_check_chars(tab, i, c))
				return (0);
			if (tab[i[0]][i[1]] == c[1])
				ret[i[0]][i[1]] = 0;
			else
				ret[i[0]][i[1]] = 1;
			i[1]++;
		}
		i[1] = 0;
		i[0]++;
	}
	return (ret);
}

int	**ft_map_solver(int **tab, int size_y, int size_x)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i < size_y)
	{
		while (j < size_x)
		{
			if (tab[i][j] != 0)
				tab[i][j] = ft_checker(tab[i - 1][j],
						tab[i][j - 1], tab[i - 1][j - 1]);
			j++;
		}
		j = 1;
		i++;
	}
	return (tab);
}
