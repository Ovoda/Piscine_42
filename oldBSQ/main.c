/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 11:14:30 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/29 18:03:24 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int main(int argc, char **argv)
{
	(void)argc;
	t_file file;
	t_tab	tab;
	t_max	max_square;
	int i;

	i = 1;
	max_square.value = 0;
	while (argv[i])
	{
		file = ft_input_to_struct(argv[i]);
		ft_check_matrice(&file);
		if (file.is_ok == FALSE)
		{
			PS(file.name);
			i++;
			continue;
		}
		else
		{	
			PS("GOOD MAP");
			tab = ft_fill_tab(&file);
			ft_solve(&tab, &max_square);
			ft_display(&file, max_square);
		}
		i++;
	}
	return (0);
}
