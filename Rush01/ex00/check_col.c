/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_col.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 16:24:13 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/20 16:38:10 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_check_col2(int **comb_tab, int i, int tmp, int j)
{
	int n2;

	n2 = 0;
	tmp = comb_tab[j][i];
	while (j >= 0)
	{
		if (comb_tab[j][i] > tmp)
		{
			tmp = comb_tab[j][i];
			n2++;
		}
		j--;
	}
	return (n2 + 1);
}

int		ft_check_col(int **comb_tab, int **input_tab, int i)
{
	int n1;
	int n2;
	int j;
	int tmp;

	n1 = 0;
	n2 = 0;
	j = 0;
	tmp = comb_tab[j][i];
	while (j < 4)
	{
		if (comb_tab[j][i] > tmp)
		{
			tmp = comb_tab[j][i];
			n1++;
		}
		j++;
	}
	n2 = ft_check_col2(comb_tab, i, tmp, 3);
	n1++;
	if (n1 == input_tab[0][i] && n2 == input_tab[1][i])
		return (1);
	i++;
	return (0);
}

int		check_for_double_in_line(int **tab, int i)
{
	int j;
	int x;

	j = 0;
	x = 0;
	while (x < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tab[j][i] == tab[x][i] && j != x)
				return (0);
			j++;
		}
		x++;
	}
	return (1);
}

int		ft_check_all_col(int **comb_tab, int **input_tab)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (ft_check_col(comb_tab, input_tab, i) == 0 ||
				check_for_double_in_line(comb_tab, i) == 0)
			return (0);
		i++;
	}
	return (1);
}
