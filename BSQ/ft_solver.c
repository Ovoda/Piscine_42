/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:07:22 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/30 22:37:45 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_init_cache(t_file file, t_cache *cache, t_max *max)
{
	int i;

	i = 0;
	if (!(cache->cache[0] = malloc(sizeof(int) * (file.nb_col + 1))))
		return (0);
	if (!(cache->cache[1] = malloc(sizeof(int) * (file.nb_col + 1))))
		return (0);
	while (i < file.nb_col - 1)
	{
		if (file.buff[i] == file.empty)
		{
			if (max->value == 0)
			{
				max->value = 1;
				max->index = i;
			}
			cache->cache[0][i] = 1;
		}
		else if (file.buff[i] == file.obstacle)
			cache->cache[0][i] = 0;
		i++;
	}
	return (1);
}

void	ft_set_cache(t_file file, t_cache *cache, t_max *max, int i)
{
	int y;
	int	min;

	y = 1;
	while (y < file.nb_col - 1)
	{
		min = cache->cache[1][y - 1];
		if (cache->cache[0][y - 1] < min)
			min = cache->cache[0][y - 1];
		if (cache->cache[0][y] < min)
			min = cache->cache[0][y];
		if (cache->cache[1][y] != 0)
			cache->cache[1][y] = cache->cache[1][y] + min;
		if (cache->cache[1][y] > max->value)
		{

			max->value = cache->cache[1][y];
			max->index = i - file.nb_col + 1 + y;
		}
		y++;
	}
}


int		ft_solve(t_file file, t_max *max, t_cache *cache)
{
	int i;
	int y;
	int x;

	i = file.nb_col;
	
	if (ft_init_cache(file, cache, max) == 0)
		return (0);
	y = 0;
	if (max->value == 1 && file.nb_lines == 1)
		return (1);
	while (file.buff[i] != '\0')
	{
		y = 0;
		while (file.buff[i] != '\n')
		{
			if (file.buff[i] == file.empty)
				cache->cache[1][y] = 1;
			else if (file.buff[i] == file.obstacle)
				cache->cache[1][y] = 0;
			else
				return (0);
			i++;
			y++;
		}
		
		if (y != file.nb_col - 1)
			return (0);
		ft_set_cache(file, cache, max, i);
		x = 0;
		while (x < file.nb_col - 1)
		{
			cache->cache[0][x] = cache->cache[1][x];
			x++;
		}
		i++;
	}
	
	if (i != file.file_size || i != file.nb_lines * file.nb_col)
		return (0);
	
	return (1);
}

void		ft_solve_single_col(t_file *file)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (file->buff[i] && count == 0)
	{
		if (file->buff[i] == file->empty)
			{
				file->buff[i] = file->full;
				count ++;
			}
		i++;
	}
}
