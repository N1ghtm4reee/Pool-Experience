/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 11:59:53 by aakhrif           #+#    #+#             */
/*   Updated: 2024/09/03 10:52:49 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	j;
	unsigned int	i;
	unsigned int	dlen;
	unsigned int	slen;

	j = 0;
	dlen = 0;
	slen = ft_strlen(src);
	while (dest[dlen])
		dlen++;
	if (size <= dlen)
		return (slen + size);
	i = dlen;
	while (src[j] && j < size - dlen - 1)
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dlen + slen);
}
