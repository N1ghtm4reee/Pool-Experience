/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:56:27 by aakhrif           #+#    #+#             */
/*   Updated: 2024/09/12 18:29:35 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int		*arr;
	int		i;

	i = 0;
	arr = malloc(sizeof(int) * length);
	if (!arr)
		return (NULL);
	while (i < length)
	{
		arr[i] = (*f)(tab[i]);
		i++;
	}
	return (arr);
}
