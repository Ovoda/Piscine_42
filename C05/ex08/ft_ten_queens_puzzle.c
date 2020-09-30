/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 14:02:56 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/27 01:00:00 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define N 14

int		ft_abs(int nb)
{
	return (nb < 0 ? -nb : nb);
}

int		ft_check(int i, int *tab)
{
	int j;

	j = 0;
	while (j < i)
	{
		if (tab[i] == tab[j] || ft_abs(tab[i] - tab[j]) == ft_abs(i - j))
			return (0);
		j++;
	}
	return (1);
}

void	ft_print(int *tab)
{
	int		i;
	char	a;

	i = 0;
	while (i < N)
	{
		a = tab[i] + 48;
		write(1, &a, 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_add_queen(int i, int *tab, int *count)
{
	tab[i] = 0;
	while (tab[i] < N)
	{
		if (ft_check(i, tab))
		{
			if (i == N - 1)
			{
//				ft_print(tab);
				*count = *count + 1;
			}
			else
				ft_add_queen(i + 1, tab, count);
		}
		tab[i]++;
	}
}

int		ft_ten_queens_puzzle(void)
{
	int tab[N];
	int count;

	count = 0;
	ft_add_queen(0, tab, &count);
	return (count);
}


#include <stdio.h>

int main()
{
	printf("%d", ft_ten_queens_puzzle());
}

