/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 14:38:23 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/17 18:44:52 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int *tab;
	int length;

	i = 0;
	length = max - min;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	if (!(tab = malloc((max - min) * sizeof(int))))
		return (-1);
	while (min < max)
	{
		tab[i] = min;
		min++;
		i++;
	}
	*range = tab;
	return (length);
}

/*
**#include <stdio.h>
**
**int main(int argc, char **argv)
**{
**	int *tab;
**	int min;
**	int max;
**	int i;
**
**	i = 0;
**	(void)argc;
**	min = atoi(argv[1]);
**	max = atoi(argv[2]);
**	printf("length : %d\n", ft_ultimate_range(&tab, min, max));
**	while (min < max)
**	{
**		printf("%d", tab[i]);
**		min++;
**		i++;
**	}
**}
*/
