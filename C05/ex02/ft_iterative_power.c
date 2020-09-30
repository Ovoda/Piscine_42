/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 19:32:27 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/14 13:28:52 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int tmp_nb;

	tmp_nb = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 1)
	{
		nb = tmp_nb * nb;
		power--;
	}
	return (nb);
}

/*
**#include <stdlib.h>
**#include <stdio.h>
**
**int main(int argc, char **argv)
**{
**	(void)argc;
**	printf("%d", ft_iterative_power(atoi(argv[1]), atoi(argv[2])));
**	return (0);
**}
*/
