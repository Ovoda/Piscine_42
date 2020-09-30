/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 16:37:57 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/26 17:50:45 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putstr(char *str, int output)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	write(output, str, i);
}

void	ft_display_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i + 1])
	{
		write(1, "[", 1);
		ft_putstr(tab[i], 1);
		write(1, "]\n", 2);
		i++;
	}
}

void	ft_display_struct(t_index *index)
{
	int i;

	i = 0;
	while (index[i].value)
	{
		ft_putstr("key[", 1);
		ft_putstr(index[i].key, 1);
		ft_putstr("] --> value[", 1);
		ft_putstr(index[i].value, 1);
		ft_putstr("]\n", 1);
		i++;
	}
}
