/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:44:08 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/28 15:06:52 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_print_matrice(t_file file)
{
	int i;
	int j;

	i = 0;
	while (file.matrice[i])
	{
		j = 0;
		while (file.matrice[i][j])
			j++;
		write(1, &file.matrice[i][j], j);
		write(1, "\n", 1);
		i++;

	}
}

void	ft_display(t_file *file, t_max max_square)
{
	int x;
	int y;
	int	x_stop;
	int y_stop;

	(void)max_square;
	x = max_square.x;
	x_stop = x - max_square.value;
	y = max_square.y;
	y_stop = y - max_square.value;
	while (x > x_stop)
	{
		y = max_square.y;
		while (y > y_stop)
		{
			file->matrice[x][y] = file->full;
			y--;
		}
		x--;
	}
	ft_print_matrice(*file);
}
