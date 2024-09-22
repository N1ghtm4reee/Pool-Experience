/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 20:27:05 by aakhrif           #+#    #+#             */
/*   Updated: 2024/09/12 12:33:48 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	total_lengh(char **strs, char *sep, int size)
{
	int	i;
	int	t_len;

	t_len = 0;
	i = 0;
	while (i < size)
		t_len += ft_strlen(strs[i++]);
	t_len += (size - 1) * ft_strlen(sep);
	return (t_len);
}

char	*initializer(char *d, char **strs, int size, char *sep)
{
	int		i;
	int		s;
	int		j;

	i = 0;
	s = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			d[s++] = strs[i][j++];
		j = 0;
		while (sep[j] && i < size - 1)
			d[s++] = sep[j++];
		i++;
	}
	d[s] = '\0';
	return (d);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		t_len;
	char	*d;

	if (size <= 0)
	{
		d = malloc(sizeof(char));
		return (d);
	}
	t_len = total_lengh(strs, sep, size) + 1;
	d = malloc(sizeof(char) * t_len);
	if (!d)
		return (NULL);
	d = initializer(d, strs, size, sep);
	return (d);
}
