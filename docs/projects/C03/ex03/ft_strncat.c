/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 08:56:30 by aakhrif           #+#    #+#             */
/*   Updated: 2024/09/07 22:44:49 by aakhrif          ###   ########.fr       */
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

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	slen;

	slen = ft_strlen(src);
	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (j < nb && j < slen)
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}
