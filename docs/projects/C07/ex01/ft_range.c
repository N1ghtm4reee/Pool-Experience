/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:54:29 by aakhrif           #+#    #+#             */
/*   Updated: 2024/09/07 13:34:19 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*p;
	int	i;
	int	size;

	size = max - min;
	if (size <= 0)
		return (NULL);
	p = (int *)malloc(sizeof(int) * size);
	if (!p)
		return (NULL);
	i = 0;
	while (i < size)
	{
		p[i] = min + i;
		i++;
	}
	return (p);
}
