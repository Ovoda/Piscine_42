/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 12:13:38 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/22 23:57:42 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

int	ft_atoi(char *str)
{
	int i;
	int nb;
	int sign;

	i = 0;
	nb = 0;
	sign = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	return (nb);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_puterror(char *str, char *error)
{
	ft_putstr("tail: ");
	ft_putstr(str);
	ft_putstr(": ");
	ft_putstr(error);
	ft_putstr("\n");
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*ft_strncpy_with_offset(char *dest, char *src, int n)
{
	int i;

	i = 0;
	while (dest[i])
		i++;
	while (src[i] && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
