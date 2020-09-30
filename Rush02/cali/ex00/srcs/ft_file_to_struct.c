/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_dict.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 14:14:55 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/29 15:16:31 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_dict_line_count(char *str)
{
	int lines;
	int i;

	i = 0;
	lines = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			lines++;
		i++;
	}
	return (lines);
}

char	*ft_strdup_with_offset(char *str, char charset, int *i)
{
	char	*dest;
	int		j;
	int		tmp;
	int		size;

	j = 0;
	tmp = *i;
	size = 0;
	while (str[tmp] != charset)
	{
		size++;
		tmp += 1;
	}
	if (!(dest = malloc(sizeof(char) * (size + 1))))
		return (0);
	while (str[*i] == 32)
		*i += 1;
	while (str[*i] != charset && str[*i])
	{
		dest[j] = str[*i];
		j++;
		*i += 1;
	}
	dest[j] = '\0';
	return (dest);
}

char	**ft_split(char *str)
{
	int		i;
	int		nb_lines;
	char	**tab;
	int		offset;

	nb_lines = ft_dict_line_count(str);
	offset = 0;
	i = 0;
	if (!(tab = malloc(sizeof(char *) * (nb_lines + 1))))
		return (0);
	while (i < nb_lines && str[offset])
	{
		tab[i] = ft_strdup_with_offset(str, '\n', &offset);
		offset++;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

t_index	*ft_tab_to_struct(char **tab)
{
	int		i;
	int		offset;
	t_index	*index;

	i = 0;
	while (tab[i])
		i++;
	if (!(index = malloc(sizeof(t_index) * i)))
		return (0);
	i = 0;
	while (tab[i])
	{
		offset = 0;
		index[i].key = ft_strdup_with_offset(tab[i], ':', &offset);
		offset++;
		index[i].value = ft_strdup_with_offset(tab[i], '\0', &offset);
		i++;
	}
	i = -1;
	while (tab[++i])
		free(tab[i]);
	return (index);
}

t_index	*ft_dict_to_struct(char *dict)
{
	int		fd;
	int		bytes;
	char	**tab;
	char	buff[BUFF_SIZE];
	t_index *index;

	fd = open(dict, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Error\n", 2);
		return (0);
	}
	while ((bytes = read(fd, buff, BUFF_SIZE)))
	{
		if (bytes < 0)
			ft_putstr("Error\n", 2);
		tab = ft_split(ft_strdup(buff));
		index = ft_tab_to_struct(tab);
		free(tab);
	}
	close(fd);
	return (index);
}
