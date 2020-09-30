/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 09:09:41 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/28 12:47:52 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_check_line(char *line, t_file file)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == file.empty ||
				line[i] == file.obstacle ||
				line[i] == file.full)
			i++;
		else
			return (0);
	}
	return (i);
}

void	ft_check_matrice(t_file *file)
{
	int i;
	int	prev;

	i = 1;
	while (file->matrice[i])
	{
		prev = ft_check_line(file->matrice[i - 1], *file);
		if (prev != ft_check_line(file->matrice[i], *file))
		{
			file->is_ok = FALSE;
			return;
		}
		i++;
	}
	//i--;
	if (i != file->nb_lines)
		file->is_ok = FALSE;
	else
		file->is_ok = TRUE;
	if (file->nb_lines == 0)
		file->is_ok = FALSE;
}
