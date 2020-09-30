/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbarrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 17:09:32 by axbarrei          #+#    #+#             */
/*   Updated: 2020/09/27 21:09:38 by mterkhoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft.h"

int		print_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

int		ft_only_numbers(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int		error_scout(int argc, char *str)
{
	if (argc < 2 || argc > 3 || ft_strlen(str) == 0)
	{
		print_error();
		return (0);
	}
	else if (!(ft_only_numbers(str)))
	{
		print_error();
		return (0);
	}
	return (1);
}

int		ft_valid_keys(char **tab, t_index *index)
{
	int i;
	int j;
	int cnt;

	i = -1;
	while (tab[++i])
	{
		j = -1;
		cnt = 0;
		while (index[++j].value)
		{
			if ((ft_strcmp(tab[i], index[j].key) == 0)
					&& ft_str_is_printable(index[j].value))
				cnt++;
		}
		if (cnt != 1)
		{
			write(1, "Dict Error\n", 11);
			return (0);
		}
	}
	return (1);
}
