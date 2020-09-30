/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 10:27:22 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/27 15:08:41 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft.h"

char	*ft_zero(int factor)
{
	char	*dest;
	int		i;

	i = 1;
	dest = 0;
	if (factor > 0)
	{
		dest = malloc(sizeof(char) * (factor * 3 + 2));
		dest[0] = '1';
		while (i <= factor * 3)
		{
			dest[i] = '0';
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}

void	ft_decompose(int nb, char **tab, int factor)
{
	if (nb / 100 != 0)
	{
		ft_add_to_tab(tab, ft_itoa(nb / 100));
		ft_add_to_tab(tab, ft_itoa(100));
		nb -= nb / 100 * 100;
	}
	if (nb / 10 != 0 && nb >= 20)
	{
		ft_add_to_tab(tab, ft_itoa(nb - nb % 10));
		nb -= nb / 10 * 10;
	}
	if (nb > 0)
		ft_add_to_tab(tab, ft_itoa(nb));
	ft_add_to_tab(tab, ft_zero(factor));
}

int		ft_atoi_of_n(char *str, int size)
{
	int i;
	int res;

	res = 0;
	i = 0;
	while (i < size && str[i])
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res);
}

char	**ft_allocate_tab(char *str)
{
	char	**tab;
	int		len;
	int		i;

	len = ft_strlen(str) + 100;
	if (!(tab = malloc(len * sizeof(char *))))
		return (0);
	i = -1;
	while (++i < len)
		tab[i] = 0;
	return (tab);
}

char	**ft_input_to_tab(char *str)
{
	int		i;
	char	**tab;
	int		str_len;
	int		factor;

	tab = ft_allocate_tab(str);
	str_len = ft_strlen(str);
	factor = str_len / 3 - 1;
	i = 0;
	if (str_len % 3)
	{
		ft_decompose(ft_atoi_of_n(&str[i], str_len % 3), tab, factor + 1);
		i += str_len % 3;
	}
	while (str[i] && i < str_len)
	{
		if (ft_atoi_of_n(&str[i], 3) != 0)
			ft_decompose(ft_atoi_of_n(&str[i], 3), tab, factor);
		factor--;
		i += 3;
	}
	return (tab);
}
