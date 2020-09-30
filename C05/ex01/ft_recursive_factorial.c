/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 19:20:11 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/14 13:15:32 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 1 || nb == 0)
		return (1);
	return (ft_recursive_factorial(nb - 1) * nb);
}

/*
**#include <stdio.h>
**#include <stdlib.h>
**
**int main(int argc, char **argv)
**{
**	(void)argc;
**	printf("%d", ft_recursive_factorial(atoi(argv[1])));
**	return (0);
**}
*/
