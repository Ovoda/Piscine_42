/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 14:14:49 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/17 14:25:16 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *tab;
	int i;

	i = 0;
	if (min >= max)
	{
		tab = (NULL);
		return (tab);
	}
	if (!(tab = malloc((max - min + 1) * sizeof(int))))
		return (NULL);
	while (min < max)
	{
		tab[i] = min;
		i++;
		min++;
	}
	return (tab);
}

/*
**#include <stdio.h>
**
**int main(int argc, char **argv)
**{
**	int i;
**	int *tab;
**	int min;
**	int max;
**
**	i = 0;
**	(void)argc;
**	min = atoi(argv[1]);
**	max = atoi(argv[2]);
**	tab = ft_range(min,  max);
**	while (i < max - min)
**	{
**		printf("%d ", tab[i]);
**		i++;
**	}
**}
*/
