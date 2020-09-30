/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 11:02:21 by gpetit            #+#    #+#             */
/*   Updated: 2020/09/20 21:41:12 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sky.h"

int		ft_conformity(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((i % 2 == 0) && (str[i] < '0' || str[i] > '4'))
			return (1);
		if ((i % 2 == 1) && (str[i] != ' '))
			return (1);
		i++;
	}
	if (i != 31)
		return (1);
	return (0);
}

int		main(int argc, char **argv)
{
	int		i;
	char	*error;

	error = "Error\n";
	i = 1;
	if (argc != 2)
	{
		ft_putstr(error);
		return (0);
	}
	if (ft_conformity(argv[1]) == 1 || sky(argv[1]) == 0)
	{
		ft_putstr(error);
		return (0);
	}
	return (0);
}
