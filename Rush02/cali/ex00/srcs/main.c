/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 16:59:24 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/29 15:20:28 by calide-n         ###   ########.fr       */
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
		{
			ft_put_trim_str(index[i].value);
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
		write(1, "\n", 1);
		return (1);
	}
	return (0);
}

void	ft_ultimate_clean(char **tab, t_index *index)
{
	int i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
	i = -1;
	free(index);
}

int		main(int argc, char **argv)
{
	char	*dict;
	char	**nbr;
	char	*str;
	t_index *idx;

	if (argc == 2)
	{
		dict = "numbers.dict";
		str = argv[1];
	}
	if (argc == 3)
	{
		str = argv[2];
		dict = argv[1];
	}
	if (error_scout(argc, str) == 0 || ((idx = ft_dict_to_struct(dict)) == 0))
		return (0);
	while (*str == '0' && ft_strlen(str) != 1)
		str++;
	nbr = ft_input_to_tab(str);
	if (ft_zero_exception(str, idx) || !ft_valid_keys(nbr, idx))
		return (0);
	ft_conversion(nbr, idx);
	ft_ultimate_clean(nbr, idx);
	return (0);
}
