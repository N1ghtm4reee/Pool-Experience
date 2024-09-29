/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:09:15 by aakhrif           #+#    #+#             */
/*   Updated: 2024/09/18 22:47:21 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	*ft_bsq_pos(int **tab, int size_y, int size_x)
{
	t_pos	posb;

	posb.i[0] = 0;
	posb.i[1] = 0;
	posb.i[2] = 0;
	posb.pos = malloc(sizeof(int) * 2);
	posb.pos[1] = 0;
	if (posb.pos == NULL)
		exit(0);
	while (posb.i[0] < size_y)
	{
		while (posb.i[1] < size_x)
		{
			if (tab[posb.i[0]][posb.i[1]] > posb.i[2])
			{
				posb.i[2] = tab[posb.i[0]][posb.i[1]];
				posb.pos[0] = posb.i[0];
				posb.pos[1] = posb.i[1];
			}
			posb.i[1]++;
		}
		posb.i[1] = 0;
		posb.i[0]++;
	}
	return (posb.pos);
}

char	**ft_bsq_solver(int **tab_i, char **tab_c, char c, int *pos)
{
	t_bsq	bsq;

	bsq.bigst = tab_i[pos[0]][pos[1]];
	bsq.i = pos[0];
	bsq.j = pos[1];
	bsq.n = 0;
	bsq.m = 0;
	while (bsq.m < bsq.bigst)
	{
		while (bsq.n < bsq.bigst)
		{
			tab_c[bsq.i - bsq.m][bsq.j - bsq.n] = c;
			bsq.n++;
		}
		bsq.n = 0;
		bsq.m++;
	}
	return (tab_c);
}

void	ft_print_bsq(char **tab, int x)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
	{
		write(1, tab[i], x);
		ft_putchar('\n');
		i++;
	}
}

int	ft_bsq(char *argv)
{
	char	**tab_c;
	char	*first_line;
	char	*chars;
	int		**tab_i;
	int		size[2];

	first_line = get_first_line(argv);
	if (first_line == 0)
		return (1);
	size[0] = get_nbr_lines(first_line);
	chars = get_chars(first_line);
	tab_c = ft_read(size[0], argv, ft_strlen(first_line));
	if (tab_c == NULL)
		return (1);
	size[1] = get_nbr_cols(argv);
	tab_i = ft_char_arr_to_int_arr(tab_c, size[0], size[1], chars);
	if (tab_i == NULL || tab_c[0] == NULL)
		return (1);
	tab_i = ft_map_solver(tab_i, size[0], size[1]);
	tab_c = ft_bsq_solver(tab_i, tab_c, chars[2],
			ft_bsq_pos(tab_i, size[0], size[1]));
	ft_print_bsq(tab_c, size[1]);
	if (tab_i == 0 || tab_c == 0)
		return (1);
	return (0);
}
