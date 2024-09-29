/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:32:13 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/18 21:12:56 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_initialize(t_read *bsq)
{
	bsq->i = 0;
	bsq->j = 0;
	bsq->size = 0;
}

char	**ft_read(int y, char *argv, int p_size)
{
	t_read	bsq;

	if (y == 0)
		return (0);
	ft_initialize(&bsq);
	bsq.x = get_nbr_cols(argv);
	bsq.buf = (char **) malloc(y * sizeof(char *) + 1);
	if (bsq.buf == NULL)
		exit(1);
	bsq.fd = open(argv, O_RDONLY);
	read(bsq.fd, bsq.buf, p_size);
	bsq.buf[0] = malloc(bsq.x * sizeof(char));
	while (read(bsq.fd, bsq.buf[bsq.i], bsq.x) > 0)
	{
		bsq.i++;
		read(bsq.fd, bsq.b, 1);
		if (bsq.b[0] != '\n' || bsq.i > y)
			return (0);
		bsq.buf[bsq.i] = malloc(bsq.x * sizeof(char));
	}
	if (bsq.i != y)
		return (0);
	bsq.buf[bsq.i] = 0;
	close(bsq.fd);
	return (bsq.buf);
}
