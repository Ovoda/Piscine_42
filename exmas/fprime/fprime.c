/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 14:37:45 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/25 15:18:22 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int i;
	int sign;
	int nb;

	sign = 1;
	i = 0;
	nb = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		sign == '-' ? sign *= -1 : sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - 48;  
		i++;
	}
	return (nb * sign);
}

#include <stdio.h>

int main(int argc, char **argv)
{
	int i;
	int nb;

	i = 2;
	if (argc != 2)
		return (0);
	nb = ft_atoi(argv[1]);
	while (nb != 0)
	{
		if (i > nb)
			break;
		while (nb % i == 0)
		{
				printf("%d*", i);
				nb = nb / i;
		}
		i++;
	}
}
