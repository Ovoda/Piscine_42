/* ************************************************************************** */
/*                                                                            */

/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 18:37:10 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/29 10:31:36 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# define BOOL int
# define TRUE 1
# define FALSE 0
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>


typedef struct	s_file
{
	char	*name;
	int 	nb_col;
	int		nb_lines;
	int		param_size;
	char	*param_line;
	char	full;
	char	empty;
	char	obstacle;
	int		fd;
	BOOL	is_ok;
	char	*buff;
	int		file_size;
}				t_file;

typedef	struct	s_max
{
	int index;
	int value;
}				t_max;

typedef struct s_cache
{
	int *cache[2];
	int cache_len;
}				t_cache;


t_file	ft_input_to_struct(char *name);
int		ft_atoi(t_file file);
void	ft_display(t_file *file, t_max max_square);
int		ft_solve(t_file file, t_max *max, t_cache *cache);
int		ft_check_param_lines(t_file file);
void		ft_solve_single_col(t_file *file);
int		ft_stdin_to_struct(t_file *file);

#endif

