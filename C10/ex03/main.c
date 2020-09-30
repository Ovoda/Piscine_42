/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 10:40:59 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/25 12:04:07 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

param 	*init_params(char **argv)
{
	param *params;

	params = malloc(sizeof(param *));
	if ((argv[1][0] == '-' && argv[1][1] == 'C') ||
			(argv[1][0] == '-' && argv[2][0] == 'C'))
	{
		params->c_flag = 1;
		params->addr_length = 8;
	}
	else
	{
		params->c_flag = 0;
		params->addr_length = 7;
	}
	return (params);
}

void	ft_display_file_stock(t_file *file_stock)
{
	int i;

	i = 0;
	while (file_stock[i].name != 0)
	{
		PF(file_stock[i].name, file_stock[i].size);
		i++;
	}
}

int main(int argc, char **argv)
{
	param *params;
	t_file *file_stock;

	file_stock = ft_create_file_stock(argc, argv);
//	ft_display_file_stock(file_stock);
	ft_open_files(file_stock);	
	ft_read_files(file_stock);
	// open files
	// Chek argvs for options flags
	// read files
	// convert everything in hexa or addr
	// stock it in tab
	// print tab with -c or not
	// close files
	return (0);
}
