/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:22:23 by aakhrif           #+#    #+#             */
/*   Updated: 2024/09/17 19:02:51 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	front;
	int	back;
	int	i;

	i = 0;
	front = 0;
	back = 0;
	while (i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) < 0)
			front++;
		else if ((*f)(tab[i], tab[i + 1]) > 0)
			back++;
		else
		{
			front++;
			back++;
		}
		i++;
	}
	if (back == i || front == i)
		return (1);
	return (0);
}
