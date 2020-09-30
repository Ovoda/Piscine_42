/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skycrapper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 10:54:47 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/20 21:47:12 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sky.h"
#include <stdio.h>

int g_sol_found = 0;

void	ft_solve(int **comb_tab, int **input_tab, int **sol_tab, int i)
{
	int j;

	j = 0;
	sol_tab[i] = comb_tab[0];
	while (sol_tab[i] != comb_tab[24])
	{
		if (ft_check_line(sol_tab, input_tab, i))
		{
			if (i >= 3)
			{
				if (ft_check_all_col(sol_tab, input_tab))
				{
					if (g_sol_found == 0)
						ft_print_tab(sol_tab);
					g_sol_found = 1;
				}
			}
			else
				ft_solve(comb_tab, input_tab, sol_tab, i + 1);
		}
		j++;
		sol_tab[i] = comb_tab[j];
	}
}

int		sky(char *str)
{
	int **input_tab;
	int	**sol_tab;
	int **comb_tab;
	int i;

	i = 0;
	sol_tab = malloc(sizeof(int *) * 4);
	while (i < 4)
	{
		sol_tab[i] = malloc(sizeof(int) * 4);
		i++;
	}
	input_tab = ft_create_input_tab(str);
	comb_tab = create_comb_tab();
	ft_solve(comb_tab, input_tab, sol_tab, 0);
	free(comb_tab);
	free(input_tab);
	free(sol_tab);
	if (g_sol_found == 1)
		return (1);
	return (0);
}
