/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_stock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 14:37:31 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/24 14:45:38 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

int		ft_file_size(int fd)
{
	int size;
	char buff[BUFF_SIZE];
	ssize_t bytes;

	size = 0;
	while ((bytes = read(fd, &buff, BUFF_SIZE)))
	{
		if (bytes < 0)
			return (0);
		size += bytes; 
	}
	return (size);
}

t_file	*ft_create_file_stock(int argc, char **argv)
{
	int fd;
	int i;
	int j;
	t_file	*file_stock;

	i = 0;
	j = 1;
	file_stock = malloc(sizeof(t_file) * argc);
	while (j < argc)
	{
		file_stock[i].fd = open(argv[j], O_RDONLY);
		file_stock[i].error = errno;
		file_stock[i].name = argv[j];
		file_stock[i].size = ft_file_size(file_stock[i].fd);
		i++;
		j++;
	}
	file_stock[i].name = 0;
	i = 0;
	while (i < argc - 1)
	{
		close(file_stock[i].fd);
		i++;
	}
	return (file_stock);
}
