/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 09:43:15 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/21 22:19:11 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < length)
	{
		if (f(tab[i]) != 0)
			count++;
		i++;
	}
	return (count);
}

/*
**#include <stdio.h>
**
**int	ft_contains_a(char *str)
**{
**	int i;
**
**	i = 0;
**	while (str[i])
**	{
**		if (str[i] == 'a')
**			return (1);
**		i++;
**	}
**	return (0);
**}
**
**int main(int argc, char **argv)
**{
**	printf("There is %d arguments containing the letter 'a'",
** ft_count_if(argv, argc, &ft_contains_a));
**}
*/
