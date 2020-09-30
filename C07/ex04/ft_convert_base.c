/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:52:08 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/25 11:43:25 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_is_printable_and_not_space(char c);
int		ft_check_double(char *str, char c);
int		ft_check_base(char *str);
int		indexof(char c, char *str);

int		char_is_in_base(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_atoi_base(char *str, char *base)
{
	int i;
	int sign;
	int nb;
	int size;

	i = 0;
	sign = 1;
	nb = 0;
	size = 0;
	while (base[size])
		size++;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	while ((str[i] == '+' || str[i] == '-'))
	{
		str[i] == '-' ? sign *= -1 : sign;
		i++;
	}
	while (str[i] && char_is_in_base(str[i], base))
	{
		nb = nb * size + indexof(str[i], base);
		i++;
	}
	return (nb * sign);
}

char	*ft_putnbr_base(int nbr, char *base, int i, char *dest)
{
	unsigned int	size;
	unsigned int	nb;

	size = 0;
	while (base[size])
		size++;
	if (nbr < 0)
	{
		dest[0] = '-';
		nb = -nbr;
	}
	else
		nb = nbr;
	if (nb >= size)
	{
		ft_putnbr_base(nb / size, base, i - 1, dest);
		dest[i] = base[nb % size];
	}
	if (nb < size)
		dest[i] = base[nb];
	return (dest);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	int		tmp_nb;
	char	*dest;
	int		base_to_size;
	int		i;

	if (!ft_check_base(base_to) || !ft_check_base(base_from))
		return (0);
	nb = ft_atoi_base(nbr, base_from);
	tmp_nb = nb;
	i = 0;
	base_to_size = ft_strlen(base_to);
	while (tmp_nb != 0)
	{
		tmp_nb = tmp_nb / base_to_size;
		i++;
	}
	nb < 0 ? i += 1 : i;
	if (!(dest = malloc(sizeof(char) * (i + 1))))
		return (0);
	dest[0] = base_to[0];
	dest = ft_putnbr_base(nb, base_to, i - 1, dest);
	nb == 0 ? i++ : i;
	dest[i] = '\0';
	return (dest);
}
