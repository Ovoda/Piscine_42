/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mterkhoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 20:20:33 by mterkhoy          #+#    #+#             */
/*   Updated: 2020/09/27 20:45:57 by mterkhoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_isspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v'
			|| c == '\f' || c == '\r' || c == ' ');
}

void	ft_put_trim_str(char *str)
{
	int i;
	int j;

	i = 0;
	j = ft_strlen(str);
	while (j >= 0 && ft_isspace(str[j]))
		j--;
	while (str[i] && ft_isspace(str[i]))
		i++;
	while (i < j)
	{
		if (!ft_isspace(str[i]) || (ft_isspace(str[i]) &&
					!ft_isspace(str[i + 1]) && str[i + 1] != '\0'))
			write(1, &str[i], 1);
		i++;
	}
}

int		ft_str_is_printable(char *str)
{
	while (*str)
	{
		if (*str >= 32 && *str <= 127)
			return (1);
		str++;
	}
	return (0);
}
