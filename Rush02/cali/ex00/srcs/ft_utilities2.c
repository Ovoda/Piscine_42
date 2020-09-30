/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 15:04:13 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/27 20:10:18 by mterkhoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_intlen_base(long nbr, int baselen)
{
	int i;

	i = 0;
	if (nbr <= 0)
		i++;
	while (nbr)
	{
		nbr /= baselen;
		i++;
	}
	return (i);
}

char	*ft_itoa(long nbr)
{
	int		len;
	char	*res;
	int		sign;

	sign = (nbr < 0) ? 1 : 0;
	len = ft_intlen_base(nbr, 10);
	res = malloc((len + 1) * sizeof(*res));
	nbr = (nbr < 0) ? -nbr : nbr;
	res[len] = '\0';
	while (--len >= 0)
	{
		res[len] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	(sign) ? res[0] = '-' : 0;
	return (res);
}

void	ft_add_to_tab(char **tab, char *key)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	tab[i] = key;
}
