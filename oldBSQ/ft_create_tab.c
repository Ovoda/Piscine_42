/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 11:27:47 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/28 14:20:27 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		**ft_create_tab(t_file *file)
{
	int i;
	int j;
	int	**tab;

	i = 0;
	while (file->matrice[i])
		i++;
	if (!(tab = malloc(sizeof(int *) * i)))
		return (0);
	i = 0;
	while (file->matrice[i])
	{
		j = 0;
		while (file->matrice[i][j])
			j++;
		if (!(tab[i] = malloc(sizeof(int) * j)))
			return (0);
		i++;
	}
	return (tab);
}

t_tab	ft_fill_tab(t_file *file)
{
	int i;
	int j;
	t_tab tab;

	i = 0;
	tab.cache = ft_create_tab(file);
	while (file->matrice[i])
	{
		j = 0;
		while (file->matrice[i][j])
		{	
			if (file->matrice[i][j] == file->empty)
				tab.cache[i][j] = 1;
			if (file->matrice[i][j] == file->obstacle)
				tab.cache[i][j] = 0;
			j++;
		}
		i++;
	}
	tab.cache[i] = NULL;
	tab.nb_lines = i;
	tab.nb_col = j;
	return (tab);
}
