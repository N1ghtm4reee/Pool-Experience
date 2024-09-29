/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:09:15 by aakhrif           #+#    #+#             */
/*   Updated: 2024/09/18 22:47:21 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

int				*ft_bsq_pos(int **tab, int size_y, int size_x);
void			ft_file(void);
int				ft_checker(int left, int up, int upleft);
char			*re_alloc(char *str, int n);
int				ft_atoi(char *str);
int				ft_bsq(char *argv);
int				**ft_map_solver(int **tab, int size_y, int size_x);
char			**ft_bsq_solver(int **tab_i, char **tab_c, char c, int *pos);
int				ft_is_number(char c);
int				get_nbr_cols(char *argv);
int				get_nbr_lines(char *str);
char			*get_first_line(char *argv);
char			*get_chars(char *str);
int				**ft_char_arr_to_int_arr(char **t, int y, int x, char *c);
char			**ft_read(int y, char *argv, int p_size);
char			**ft_split_whitespaces(char *str);
void			ft_print_bsq(char **tab, int x);
void			ft_putchar(char c);
int				ft_strlen(char *str);
void			ft_putstr(char *str);
int				ft_errors(char **tab);

typedef struct s_bsq
{
	int	i;
	int	j;
	int	m;
	int	n;
	int	bigst;
}				t_bsq;

typedef struct s_read
{
	int		x;
	int		size;
	int		fd;
	int		i;
	int		j;
	char	**buf;
	char	*str;
	char	b[5];
}				t_read;

typedef struct s_pos
{
	int		i[3];
	int		*pos;
}				t_pos;

#endif
