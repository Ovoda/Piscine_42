/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbarrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 17:09:32 by axbarrei          #+#    #+#             */
/*   Updated: 2020/09/27 14:36:26 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft.h"

int	print_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

int	ft_only_numbers(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	error_scout(int argc, char *str)
{
	if (argc < 2 || argc > 3)
	{
		print_error();
		return (0);
	}
	else if (!(ft_only_numbers(str)))
	{
		print_error();
		return (0);
	}
	return (1);
}
