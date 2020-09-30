/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 16:59:24 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/26 23:29:29 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_num_to_en(char *str, t_index *index)
{
	int i;

	i = 0;
	while (index[i].value)
	{
		if (ft_strcmp(str, index[i].key) == 0)
			ft_putstr(index[i].value, 1);
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
}

int main(int argc, char **argv)
{
	char *dictionary;
	char **nbr;
	char *str;
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
	index = ft_dict_to_struct(dictionary);
	nbr = ft_input_to_tab(str);
	ft_conversion(nbr, index);
	return (0);
}
