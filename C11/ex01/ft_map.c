/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 09:19:36 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/21 22:18:38 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int *res;
	int i;

	i = 0;
	if (!(res = malloc(sizeof(int) * length)))
		return (0);
	while (i < length)
	{
		res[i] = f(tab[i]);
		i++;
	}
	return (res);
}

/*
**#include <stdio.h>
**
**int	ft_powerof2(int nb)
**{
**	return (nb * nb * nb);
**}
**
**int main(void)
**{
**	int tab[100];
**	int *res;
**
**	for (int i = 0; i < 100; i++)
**		tab[i] = i;
**	res = ft_map(tab, 100, &ft_powerof2);
**	for (int i = 0; i < 100; i++)
**		printf("%d ", res[i]);
**
**}
*/
