/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:59:12 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/18 23:25:18 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*get_first_line(char *argv)
{
	int		i;
	int		fd;
	char	c;
	char	*str;

	i = 0;
	str = malloc(100 * sizeof(char));
	if (str == NULL)
		exit(0);
	fd = open(argv, O_RDONLY);
	c = '0';
	while (c != '\n')
	{
		if (read(fd, &c, 1) <= 0)
			return (0);
		if (i > 0 && c == 0)
			return (0);
		str[i] = c;
		i++;
	}
	close(fd);
	str[i] = '\0';
	return (str);
}

int	get_nbr_lines(char *str)
{
	int		i;
	int		n;
	char	*get;

	i = 0;
	n = 0;
	get = malloc(sizeof(char) * 10);
	if (get == NULL)
		exit(0);
	while (ft_is_number(str[i]))
	{
		get[n] = str[i];
		n++;
		i++;
	}
	return (ft_atoi(get));
}

int	get_nbr_cols(char *argv)
{
	int		i;
	int		o;
	int		fd;
	char	c;

	i = 0;
	o = 0;
	fd = open(argv, O_RDONLY);
	while (o != 2)
	{
		if (read(fd, &c, 1) <= 0)
			return (0);
		if (c == '\n')
			o++;
		if (o == 1)
			i++;
	}
	close(fd);
	return (i - 1);
}

char	*get_chars(char *str)
{
	int		i;
	int		n;
	char	*get;

	i = 0;
	n = 0;
	get = malloc(sizeof(char) * 3);
	if (get == NULL)
		exit(0);
	while (str[i])
	{
		while (ft_is_number(str[i]))
			i++;
		get[n] = str[i];
		n++;
		i++;
	}
	get[n] = '\0';
	return (get);
}
