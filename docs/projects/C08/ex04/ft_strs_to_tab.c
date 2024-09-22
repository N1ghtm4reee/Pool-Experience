/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:44:08 by aakhrif           #+#    #+#             */
/*   Updated: 2024/09/15 09:19:32 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int		i;
	int		len;
	char	*d;

	i = 0;
	while (str[i])
		i++;
	len = i;
	d = (char *)malloc(sizeof(char) * (len + 1));
	if (!d)
		return (NULL);
	i = 0;
	while (str[i])
	{
		d[i] = str[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*arr;

	i = 0;
	arr = malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (!arr)
		return (NULL);
	while (i < ac)
	{
		arr[i].size = ft_strlen(av[i]);
		arr[i].str = av[i];
		arr[i].copy = ft_strdup(av[i]);
		i++;
	}
	arr[i].str = 0;
	arr[i].copy = 0;
	return (arr);
}
