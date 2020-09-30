/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 09:12:40 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/21 22:17:50 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}

/*
**#include <stdio.h>
**
**void	ft_putnbr(int nb)
**{
**	printf("%d ", nb);
**}
**
**int main(void)
**{
**	int tab[100];
**
**	for (int i = 0; i < 100; i++)
**		tab[i] = i;
**	ft_foreach(tab, 100, &ft_putnbr);
**}
*/
