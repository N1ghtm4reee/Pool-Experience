/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:50:05 by aakhrif           #+#    #+#             */
/*   Updated: 2024/09/12 16:05:41 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (0);
		i++;
	}
	return (1);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		while (str[i] && !(is_charset(str[i], charset)))
			i++;
		if (str[i])
			word++;
		while (str[i] && (is_charset(str[i], charset)))
			i++;
	}
	return (word);
}

void	skip(char *str, char *charset, int pos, int *p)
{
	int	i;

	i = pos;
	while (str[i] && !(is_charset(str[i], charset)))
		i++;
	*p = i;
}

char	*ft_string(int end, int start, char *str)
{
	char	*s;
	int		i;

	i = 0;
	s = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!s)
		return (NULL);
	while (start < end)
		s[i++] = str[start++];
	s[i] = '\0';
	return (s);
}

char	**ft_split(char *str, char *charset)
{
	char	**d;
	int		s;
	int		i;
	int		start;
	int		end;

	s = 0;
	d = (char **)malloc(sizeof(char *) * (count_words(str, charset) + 1));
	if (!d)
		return (NULL);
	i = 0;
	while (str[i])
	{
		skip(str, charset, i, &i);
		if (!str[i])
			break ;
		start = i;
		while (str[i] && is_charset(str[i], charset))
			i++;
		end = i;
		d[s++] = ft_string(end, start, str);
	}
	d[s] = 0;
	return (d);
}
