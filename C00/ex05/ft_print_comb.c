/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 22:31:10 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/07 22:52:38 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb(void)
{
	int tab[3];

	tab[0] = -1;
	while (tab[0]++ <= 7)
	{
		tab[1] = tab[0] + 1;
		while (tab[1] <= 8)
		{
			tab[2] = tab[1] + 1;
			while (tab[2] <= 9)
			{
				ft_putchar(tab[0] + 48);
				ft_putchar(tab[1] + 48);
				ft_putchar(tab[2] + 48);
				if (tab[0] < 7)
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
				tab[2]++;
			}
			tab[1]++;
		}
	}
}
