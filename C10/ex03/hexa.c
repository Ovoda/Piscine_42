/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 21:22:51 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/25 12:31:23 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_to_hexa(char c)
{
	char *base;
	char *nb;
	unsigned char uc;

	uc = c;
	nb = malloc(sizeof(char) * 3);
	base = "0123456789abcdef";
	nb[0] = base[uc / 16];
	nb[1] = base[uc % 16];
	return (nb);
}

char	*ft_str_to_hexa(char *str, char *tab)
{
	int i;
	int j;
	char *nb;

	i = 0;
	j = 0;
	i = 0;
	while (str[i] && i < 16)
	{
		nb = ft_to_hexa(str[i]);
		tab[j] = nb[0];
		tab[j + 1] = nb[1];
		tab[j + 2] = ' ';
		j += 3;
		i++;
	}
	return (tab);
}

char	*ft_strncat_count(int count, char *tab)
{
	char *base;
	int i;

	base = "0123456789abcdef";
	i = 5;
	tab[7] = 32;
	tab[6] = '0';
	while (i >= 0)
	{
		tab[i] = base[count % 16];
		count /= 16;
		i--;
	}
	tab[8] = '\0';
	return (tab);
}

