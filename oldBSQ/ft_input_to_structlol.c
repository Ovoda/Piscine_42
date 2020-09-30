/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 18:32:12 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/30 22:53:21 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_file_size(t_file file)
{
	ssize_t bytes;
	char 	buff[BUFF_SIZE];
	int		size;

	file.fd = open(file.name, O_RDONLY);
	if (file.fd < 0)
		file.is_ok = FALSE;

	size = 0;
	while ((bytes = read(file.fd, buff, BUFF_SIZE)))
	{
		if (bytes < 0)
			file.is_ok = FALSE;
		size += bytes;
	}
	close(file.fd);
	return (size);	
}

char	*ft_read_map(t_file file)
{
	ssize_t bytes;
	char 	buff[BUFF_SIZE];
	char	*map;
	int		size;

	size = ft_file_size(file);
	file.fd = open(file.name, O_RDONLY);
	if (file.fd < 0)
		file.is_ok = FALSE;
	map = malloc(sizeof(char) * (size + 1));
	while ((bytes = read(file.fd, buff, BUFF_SIZE)))
	{
		if (bytes < 0)
			file.is_ok = FALSE;
		map = strncat(map, buff, bytes);
	}
	close(file.fd);
	return (map);
}

void	ft_param_line(char *map, t_file *file)
{
	int i;
	int j;
	char *nbr;

	i = 0;
	j = 0;
	while (file->map[i] != '\n')
		i++;
	file->full = map[--i];
	file->obstacle = map[--i];
	file->empty = map[--i];
	while (j < i)
		j++;
	if (!(nbr = malloc(sizeof(char) * (j + 1))))
		return ;
	i = 0;
	while (i < j)
	{
		nbr[i] = map[i];
		i++;
	}
	nbr[i] = '\0';
	file->nb_lines = atoi(nbr);
}

void	ft_matrix(t_file *file)
{
	int i;

	i = 1;
	file->matrice = ft_split(file->map, "\n");
	if (!file->matrice[1])
		file->matrice[0] = 0;
	while (file->matrice[i])
	{
		if (file->matrice[i])
			file->matrice[i - 1] = file->matrice[i];
		i++;
	}
	file->matrice[i - 1] = file->matrice[i];
	i = 0;
//	while (file->matrice[i])
//	{
//		PS(file->matrice[i]);
//		i++;
//	}
}

t_file	ft_input_to_struct(char *name)
{
	t_file file;

	file.name = name;
	file.map = ft_read_map(file);
	ft_param_line(file.map, &file);
	ft_matrix(&file);
	return (file);
}
