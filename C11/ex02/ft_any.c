/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 09:34:21 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/21 22:18:17 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char*))
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (f(tab[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

/*
**#include <stdio.h>
**
**int	ft_greaterthan3(char *str)
**{
**	int i;
**
**	i = 0;
**	while (str[i])
**		i++;
**	if (i > 3)
**		return (0);
**	return (1);
**}
**
**int main(int argc, char **argv)
**{
**	printf("%d", ft_any(argv, &ft_greaterthan3));
**}
*/
