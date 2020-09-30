/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 15:13:23 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/20 10:39:10 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_check_comb(int *tab, int n)
{
	int i;
	int j;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (tab[i] >= tab[j])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_print_tab(int *tab, int n)
{
	int		i;
	char	c;

	i = 0;
	if (ft_check_comb(tab, n))
	{
		while (i < n)
		{
			c = tab[i] + 48;
			write(1, &c, 1);
			i++;
		}
		if (tab[0] != (10 - n))
		{
			write(1, ", ", 2);
		}
	}
}

void	ft_n_is_one(void)
{
	char	c;

	c = '0';
	while (c <= '9')
	{
		write(1, &c, 1);
		if (c != '9')
		{
			write(1, ", ", 2);
		}
		c++;
	}
}

int		ft_create_tab(int *tab, int n)
{
	int		i;

	i = 0;
	if (n == 1)
	{
		ft_n_is_one();
	}
	if (n < 2 || n > 9)
	{
		return (0);
	}
	else
	{
		while (i < n)
		{
			tab[i] = i;
			i++;
		}
	}
	return (1);
}

void	ft_print_combn(int n)
{
	int	tab[9];
	int var[2];

	var[0] = n - 1;
	if (ft_create_tab(tab, n))
	{
		while (tab[0] <= (10 - n))
		{
			var[1] = n - 1;
			while (tab[var[0]] <= 9)
			{
				ft_print_tab(tab, n);
				tab[var[0]]++;
			}
			while (tab[var[1]] >= 9)
			{
				tab[var[1]] = 0;
				var[1]--;
			}
			tab[var[1]] = tab[var[1]] + 1;
		}
	}
}
