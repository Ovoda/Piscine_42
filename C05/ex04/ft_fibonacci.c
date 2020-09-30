/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 11:59:24 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/14 13:50:20 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	if (index > 1)
	{
		return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
	}
	return (0);
}

/*
**#include <stdio.h>
**#include <stdlib.h>
**
**int main(int argc, char **argv)
**{
**	(void)argc;
**	printf("%d", ft_fibonacci(atoi(argv[1])));
**	return (0);
**}
*/
