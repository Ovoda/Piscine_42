/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 16:59:24 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/29 18:55:44 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_num_to_en(char *str, t_index *index)
{
	int i;
	int j;

	i = 0;
	while (index[i].value)
	{
		j = 0;
		if (ft_strcmp(str, index[i].key) == 0)
		{
			while (index[i].value[j])
			{
				if (index[i].value[j] == 32)
					write(1, " ", 1);
				while (index[i].value[j] == 32)
					j++;
				write(1, &index[i].value[j], 1);
				j++;
			}
			return;
		}
		i++;
	}
}

void	ft_conversion(char **nbr, t_index *index)
{
	int i;

	i = 0;
	while (nbr[i + 1])
	{
		ft_num_to_en(nbr[i], index);
		ft_putstr(" ", 1);
		i++;
	}
	ft_num_to_en(nbr[i], index);
	ft_putstr("\n", 1);
}

int		ft_zero_exception(char *str, t_index *index)
{
	int i;

	i = 0;
	if (str[i] == '0')
	{
		ft_num_to_en("0", index);
		return (1);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	char	*dictionary;
	char	**nbr;
	char	*str;
	t_index *index;

	if (argc == 2)
	{
		dictionary = "numbers.dict";
		str = argv[1];
	}
	if (argc == 3)
	{
		str = argv[2];
		dictionary = argv[1];
	}
	if (error_scout(argc, str) == 0)
		return (0);
	if ((index = ft_dict_to_struct(dictionary)) == 0)
		return (0);
	if (ft_zero_exception(str, index))
		return (0);
	nbr = ft_input_to_tab(str);
	ft_conversion(nbr, index);
	return (0);
}
