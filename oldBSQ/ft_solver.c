/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:07:22 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/28 16:42:59 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_get_value(t_tab *tab, int x, int y)
{
	int tmp;

	if (x == 0 || y == 0)
		return;
	tmp = tab->cache[x][y - 1];
	if (tmp > tab->cache[x - 1][y - 1])
		tmp = tab->cache[x - 1][y - 1];
	if (tmp > tab->cache[x - 1][y])
		tmp = tab->cache[x - 1][y];
	tab->cache[x][y] += tmp;
}

void	ft_solve(t_tab *tab, t_max *max_square)
{
	int x;
	int y;

	x = 0;
	while (x < tab->nb_lines)
	{
		y = 0;
		while (y < tab->nb_col)
		{
			if (tab->cache[x][y] != 0)
				ft_get_value(tab, x, y);
			if (tab->cache[x][y] > max_square->value)
			{
				max_square->value = tab->cache[x][y];
				max_square->x = x;
				max_square->y = y;
			}
			//			PI(tab->cache[x][y]);
			y++;
		}
		//		PN;
		x++;
	}
}
