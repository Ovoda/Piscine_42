/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 18:32:12 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/30 22:58:36 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_read_map(t_file *file)
{
	int		bytes;
	int 	i;

	file->is_ok = TRUE;
	i = file->param_size;
	file->fd = open(file->name, O_RDONLY);
	if (file->fd < 0)
		file->is_ok = FALSE;
	if (!(file->param_line = malloc(sizeof(char) * (file->param_size + 2))))
		return (0);
	file->param_line[file->param_size + 1] = '\0';
	read(file->fd, file->param_line, file->param_size + 1);
	file->nb_lines = ft_atoi(*file);
	file->full = file->param_line[--i];
	file->obstacle = file->param_line[--i];
	file->empty = file->param_line[--i];
	if (!(file->buff = malloc((file->nb_lines * file->nb_col + 1) * sizeof(char))))
			return (0);
	if ((bytes = read(file->fd, file->buff, file->nb_lines * file->nb_col + 1)))
	{
		if (bytes < 0)
			file->is_ok = FALSE;
	}
	file->buff[bytes] = '\0';
	if (file->buff[bytes] != '\0' || file->nb_col <= 1)
		return (0);
	file->file_size = bytes;
	close(file->fd);
	return (1);
}

int		ft_get_line_length(t_file *file)
{
	int		i;
	int		bytes;
	char	buff;

	i = 0;
	file->param_size = 0;
	file->fd = open(file->name, O_RDONLY);
	if (file->fd < 0)
	{
		return (0);
	}
	while ((bytes = read(file->fd, &buff, 1)))
	{
		if (bytes < 0)
		{
			return (0);
		}
		if (buff == '\n' && file->param_size != 0)
			break;
		if (buff == '\n' && file->param_size == 0)
			file->param_size = i;
		i++;
	}
	file->nb_col = i - file->param_size;
	close(file->fd);
	return (1);
}

t_file	ft_input_to_struct(char *name)
{
	t_file file;

	file.name = name;
	if (ft_get_line_length(&file) == 0)
		file.is_ok = FALSE;
	ft_read_map(&file);
	if (file.param_line != NULL)
		free(file.param_line);
	return (file);
}
