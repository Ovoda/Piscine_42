/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 19:44:34 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/30 22:37:01 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_atoi(t_file file)
{
	int i;
	int sign;
	int nb;

	nb = 0;
	i = 0;
	sign = 1;
	while (((file.param_line[i] >= 8 &&
					file.param_line[i] <= 14) || file.param_line[i] == 32) && file.param_line[i])
		i++;
	while ((file.param_line[i] == '+' || file.param_line[i] == '-') && file.param_line[i])
	{
		file.param_line[i] == '-' ? sign *= -1 : sign;
		i++;
	}
	while (file.param_line[i] >= '0'
			&& file.param_line[i] <= '9'
			&& file.param_line[i]
			&& i < file.param_size - 3)
	{
		nb = nb * 10 + (file.param_line[i] - 48);
		i++;
	}
	if (sign < 0)
		return (0);
	return (nb);
}
