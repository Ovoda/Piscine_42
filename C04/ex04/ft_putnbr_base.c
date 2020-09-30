/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 12:35:53 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/12 17:38:16 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_is_printable_and_not_space(char c)
{
	if (c < 32 && c > 126)
	{
		return (0);
	}
	if (c == '\t' || c == '\v' ||
			c == '\n' || c == '\f' ||
			c == ' ' || c == '\r')
	{
		return (0);
	}
	return (1);
}

int		ft_check_double(char *str, char c)
{
	int n;
	int i;

	n = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			n++;
		}
		if (n > 1)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int		ft_check_base(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-' ||
				!ft_check_double(str, str[i]) ||
				!ft_is_printable_and_not_space(str[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	size;
	unsigned int	nb;

	size = 0;
	while (base[size])
	{
		size++;
	}
	if (size <= 1 || !ft_check_base(base))
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		nb = -nbr;
	}
	else
		nb = nbr;
	if (nb >= size)
	{
		ft_putnbr_base(nb / size, base);
		nb = nb % size;
	}
	ft_putchar(base[nb]);
}
