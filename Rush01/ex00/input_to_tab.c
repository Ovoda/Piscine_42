/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 16:56:49 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/20 15:21:23 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sky.h"

int	**ft_fill_input_tab(char *input, int **tab)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (input[i])
	{
		x = (x > 3 ? 0 : x);
		tab[0][x] = (i < 8 ? input[i] - 48 : tab[0][x]);
		tab[1][x] = (i < 16 ? input[i] - 48 : tab[1][x]);
		tab[2][x] = (i < 24 ? input[i] - 48 : tab[2][x]);
		tab[3][x] = (i < 32 ? input[i] - 48 : tab[3][x]);
		i += 2;
		x++;
	}
	return (tab);
}

int	**ft_create_input_tab(char *input)
{
	int i;
	int	**tab;

	i = 0;
	if (!(tab = malloc(sizeof(int *) * 4)))
		return (0);
	while (i < 4)
	{
		if (!(tab[i] = malloc(sizeof(int) * 4)))
			return (0);
		i++;
	}
	tab = ft_fill_input_tab(input, tab);
	return (tab);
}
