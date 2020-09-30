/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 17:34:01 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/08 17:58:51 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int x;
	int y;
	int tmp_int;

	x = 0;
	while (x < size)
	{
		y = x;
		while (y < size)
		{
			if (tab[x] > tab[y])
			{
				tmp_int = tab[x];
				tab[x] = tab[y];
				tab[y] = tmp_int;
			}
			y++;
		}
		x++;
	}
}
