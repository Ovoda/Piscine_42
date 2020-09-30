/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 19:46:52 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/14 13:46:29 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	if (power == 2)
		return (nb * nb);
	if (power < 0)
		return (0);
	return (nb * ft_recursive_power(nb, power - 1));
}

/*
**#include <stdio.h>
**#include <stdlib.h>
**
**int main(int argc, char **argv)
**{
**	(void)argc;
**	printf("%d", ft_recursive_power(atoi(argv[1]), atoi(argv[2])));
**	return (0);
**}
*/
