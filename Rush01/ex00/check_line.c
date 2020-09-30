/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 16:09:48 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/20 17:07:56 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_check_line2(int **comb_tab, int i, int tmp, int j)
{
	int n2;

	n2 = 0;
	tmp = comb_tab[j][i];
	while (i >= 0)
	{
		if (comb_tab[j][i] > tmp)
		{
			tmp = comb_tab[j][i];
			n2++;
		}
		i--;
	}
	return (n2 + 1);
}

int		ft_check_line(int **comb_tab, int **input_tab, int j)
{
	int n1;
	int n2;
	int i;
	int tmp;

	i = 0;
	n1 = 0;
	n2 = 0;
	tmp = comb_tab[j][i];
	while (i < 4)
	{
		if (comb_tab[j][i] > tmp)
		{
			tmp = comb_tab[j][i];
			n1++;
		}
		i++;
	}
	n2 = ft_check_line2(comb_tab, 3, tmp, j);
	n1++;
	if (n1 == input_tab[2][j] && n2 == input_tab[3][j])
		return (1);
	return (0);
}
