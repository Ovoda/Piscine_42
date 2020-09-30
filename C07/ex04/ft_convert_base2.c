/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 11:39:39 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/25 11:43:43 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_printable_and_not_space(char c)
{
	if ((c > 8 && c < 14) || c == 32)
		return (0);
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
			n++;
		if (n > 1)
			return (0);
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
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

int		indexof(char c, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (i);
		i++;
	}
	return (0);
}
