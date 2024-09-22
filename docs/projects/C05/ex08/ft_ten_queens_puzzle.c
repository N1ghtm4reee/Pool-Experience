/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:30:44 by aakhrif           #+#    #+#             */
/*   Updated: 2024/09/04 12:45:28 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	abs(int a)
{
	if (a < 0)
		a = -a;
	return (a);
}

int	is_valid_placement(int x, int y, int board[])
{
	int	i;

	i = 0;
	if (y == 0)
		return (1);
	while (i < y)
	{
		if (board[i] == x)
			return (0);
		if (abs(board[i] - x) == abs(i - y))
			return (0);
		i++;
	}
	return (1);
}

void	print_board(int board[])
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = board[i] + 48;
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ten_queens(int y, int board[], int *c)
{
	int	x;

	x = 0;
	if (y == 10)
	{
		print_board(board);
		*c += 1;
	}
	while (x < 10)
	{
		if (is_valid_placement(x, y, board))
		{
			board[y] = x;
			ten_queens(y + 1, board, c);
		}
		x++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	count;
	int	board[10];

	count = 0;
	ten_queens(0, board, &count);
	return (count);
}
