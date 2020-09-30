/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 17:30:51 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/22 22:08:21 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_string(char **s1, char **s2)
{
	char *tmp_str;

	tmp_str = *s1;
	*s1 = *s2;
	*s2 = tmp_str;
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort_string_tab(char **tab)
{
	int i;
	int j;
	int size;

	size = 0;
	i = 0;
	j = 0;
	while (tab[size])
		size++;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (ft_strcmp(tab[i], tab[j]) < 0)
			{
				ft_swap_string(&tab[i], &tab[j]);
				j = 0;
			}
			j++;
		}
		i++;
	}
}

/*
**#include <stdio.h>
**
**int main(int argc, char **argv)
**{
**	int i;
**	char **dest;
**
**	i = 0;
**	dest = argv;
**	ft_sort_string_tab(argv);
**	dest = argv;
**	while (i < argc)
**	{
**		printf("%d: %s\n", i, dest[i]);
**		i++;
**	}
**}
*/
