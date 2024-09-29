/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:09:15 by aakhrif           #+#    #+#             */
/*   Updated: 2024/09/18 22:47:21 by aakhrif          ###   ########.fr       */
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
