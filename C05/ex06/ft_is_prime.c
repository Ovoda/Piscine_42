/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 12:16:53 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/14 19:51:29 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int i;

	i = 2;
	if (nb < 2)
		return (0);
	while (i <= nb / i)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

/*
**#include <stdio.h>
**#include <stdlib.h>
**
**int main(int argc, char **argv)
**{
**	(void)argc;
**	printf("%d", ft_is_prime(atoi(argv[1])));
**	return (0);
**}
*/
