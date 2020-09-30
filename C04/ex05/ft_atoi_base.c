/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 15:10:38 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/17 08:00:43 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	indexof(char c, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
		{
			return (i);
		}
		i++;
	}
	return (0);
}

int	ft_check_base(char c, char *str)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (c == str[i])
			n++;
		if (n > 1)
			return (0);
		if ((str[i] >= 8 && str[i] <= 14) || str[i] == 32 ||
				str[i] == '+' || str[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

int	char_is_in_base(char c, char *base)
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

int	ft_atoi_base(char *str, char *base)
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
	{
		if (!ft_check_base(base[size], base))
			return (0);
		size++;
	}
	while ((str[i] >= 8 || str[i] <= 14) && str[i] == 32 && str[i])
		i++;
	while ((str[i] == '+' || str[i] == '-') && str[i++])
	{
		str[i] == '-' ? sign *= -1 : sign;
		i++;
	}
	while (str[i] > 32 && str[i] < 127 && char_is_in_base(str[i], base))
	{
		nb = nb * size + indexof(str[i], base);
		i++;
	}
	return (nb * sign);
}
