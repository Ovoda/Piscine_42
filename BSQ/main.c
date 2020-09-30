/* 
 ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 11:14:30 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/30 11:40:21 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "bsq.h"
#include <stdio.h>

void	ft_puterror()
{
	write(2, "map error\n", 10);
}

void	ft_struct_reset(t_file *file)
{	
	file->name = "";
	file->nb_col = 0;
	file->nb_lines = 0;
	file->param_size = 0;
	file->param_line = "";
	file->fd = 0;
	file->is_ok = TRUE;
	file->buff = "";
	file->file_size = 0;
}

void	ft_solo_line(t_file *file)
{
	int i;

	i = 0;
	while (file->buff[i] != '\0')
	{
		if (file->buff[i] == file->empty)
		{
			file->buff[i] = file->full;
			break;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	(void)argc;
	t_file file;
	t_cache cache;
	t_max	max_square;
	int i;
	int x;
	int y;

	i = 0;
	if (argc ==1)
	{
		if (ft_stdin_to_struct(&file) == 0)
		{	
			ft_puterror();
			return (0);
		}
	}
	else 
		i = 1;
	while (argv[i])
	{
//		printf("%s\n", argv[i]);
		y = 0;
		max_square.value = 0;
		max_square.index = 0;
		if (i > 0)
			file = ft_input_to_struct(argv[i]);
		if (file.is_ok == FALSE || ft_solve(file, &max_square, &cache) == 0 || ft_check_param_lines(file) == 0)
		{
			ft_puterror();
			if (argc > 2 && i != argc - 1)
				write(2, "\n", 1);
			i++;
			continue;
		}
		if (file.nb_col == 2)
			ft_solve_single_col(&file);
		while (y < max_square.value && file.nb_col != 2)
		{
			x = max_square.index - (file.nb_col * y);
			while (x > (max_square.index - (file.nb_col * y)) - max_square.value)
			{
				file.buff[x] = file.full;
				x--;
			}
			y++;
		}
		write(1, file.buff, (file.nb_col * file.nb_lines));
		if (argc == 1)
		{
			file.buff = file.buff - file.param_size - 1;
			free(file.buff);
		}
		if (argc != 1)
			free(file.buff);
		free(cache.cache[0]);
		free(cache.cache[1]);
		ft_struct_reset(&file);
		if (i != argc - 1)
			write(1, "\n", 1);
		i++;
	}
	system("leaks bsq");
	return (0);
}
