/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 12:09:43 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/17 19:47:43 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int i;

	i = 0;
	if (nb == 1)
		return (1);
	while (i * i < nb && i < nb / 2)
	{
		i++;
	}
	if (i * i == nb)
		return (i);
	else
		return (0);
}


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	(void)argc;
	printf("%d", ft_sqrt(atoi(argv[1])));
	return (0);
}

