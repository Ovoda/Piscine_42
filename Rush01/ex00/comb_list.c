/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 12:26:12 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/20 16:46:58 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sky.h"

int	ft_is_comb(int *tab)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = i + 1;
		while (j < 4)
		{
			if (tab[i] == tab[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	*ft_strcpy(int *src, int *dest)
{
	int i;

	i = 0;
	while (i < 4)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

int	**comb(int **comb_tab)
{
	int i;
	int tab[4];

	i = -1;
	tab[0] = 0;
	while (++tab[0] <= 4)
	{
		tab[1] = 0;
		while (++tab[1] <= 4)
		{
			tab[2] = 0;
			while (++tab[2] <= 4)
			{
				tab[3] = 0;
				while (++tab[3] <= 4)
				{
					if (ft_is_comb(tab))
					{
						ft_strcpy(tab, comb_tab[++i]);
					}
				}
			}
		}
	}
	return (comb_tab);
}

int	**create_comb_tab(void)
{
	int i;
	int **tab;

	i = 0;
	if (!(tab = malloc(sizeof(int *) * 24)))
		return (0);
	while (i < 24)
	{
		if (!(tab[i] = malloc(sizeof(int) * 4)))
			return (0);
		i++;
	}
	i = 0;
	comb(tab);
	return (tab);
}
