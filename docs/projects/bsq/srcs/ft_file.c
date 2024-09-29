/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:18:22 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/18 20:51:29 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_file(void)
{
	int		r;
	int		fd;
	char	buf[4096];

	fd = open("francawiii", O_CREAT | O_RDWR | O_TRUNC);
	r = read(0, buf, 4096);
	while (r > 0)
	{
		write(fd, buf, r);
		r = read(0, buf, 4096);
	}
	close(fd);
}
