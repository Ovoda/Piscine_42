/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 20:01:20 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/20 21:40:59 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_print_line(int *tab)
{
	int i;

	i = 0;
	while (i < 4)
	{
		ft_putchar(tab[i] + 48);
		if (i != 3)
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

void	ft_print_tab(int **tab)
{
	int i;

	i = 0;
	while (i < 4)
	{
		ft_print_line(tab[i]);
		i++;
	}
}
