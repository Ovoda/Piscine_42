/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 18:37:10 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/28 20:22:02 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# define BOOL int
# define TRUE 1
# define FALSE 0
# define BUFF_SIZE 2800000
# define PI(x) printf("%d ", x);
# define PN printf("\n");
# define PS(x) printf("%s\n", x);
# define PC(x) printf("%c", x);
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>


typedef struct	s_file
{
	char	*name;
	int		nb_lines;
	char	full;
	char	empty;
	char	obstacle;
	int		fd;
	BOOL	is_ok;
	char	*map;
	char	**matrice;
}				t_file;

typedef	struct	s_tab
{
	int	nb_lines;
	int	nb_col;
	int **cache;
}				t_tab;

typedef	struct	s_max
{
	int x;
	int y;
	int value;
}				t_max;

t_file	ft_input_to_struct(char *name);
int		ft_atoi(char *nbr);
t_tab	ft_fill_tab(t_file *file);
char	**ft_split(char *str, char *charset);
void	ft_check_matrice(t_file *file);
void	ft_solve(t_tab *tab, t_max *max_square);
void	ft_display(t_file *file, t_max max_square);

#endif

