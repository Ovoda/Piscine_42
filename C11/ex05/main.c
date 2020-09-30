/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 10:16:29 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/23 21:00:10 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_do_op.h"

int		ft_do_op(int nb1, int nb2, char ope)
{
	int				i;
	static t_calcul tab_calcul[5] = {{'+', add}, {'-', sub}, {'*', mult}
		, {'/', div}, {'%', mod}};

	i = 0;
	while (i < 5)
	{
		if (tab_calcul[i].ope == ope)
			return (tab_calcul[i].f(nb1, nb2));
		i++;
	}
	return (0);
}

int		ft_check_errors(int n2, char ope)
{
	if (n2 == 0 && (ope == '/' || ope == '%'))
	{
		if (ope == '/')
			write(1, "Stop : division by zero", 23);
		if (ope == '%')
			write(1, "Stop : modulo by zero", 21);
		write(1, "\n", 1);
		return (0);
	}
	return (1);
}

int		ft_ope(char *str)
{
	if (str[1] != '\0')
		return (0);
	if (str[0] != '+' && str[0] != '-' &&
			str[0] != '/' && str[0] != '*' && str[0] != '%')
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	int			n1;
	int			n2;
	char		ope;
	int			res;

	res = 0;
	if (argc != 4)
		return (0);
	n1 = ft_atoi(argv[1]);
	n2 = ft_atoi(argv[3]);
	if (ft_ope(argv[2]) == 0)
	{
		write(1, "0\n", 2);
		return (0);
	}
	ope = argv[2][0];
	if (ft_check_errors(n2, ope) == 0)
		return (0);
	res = ft_do_op(n1, n2, ope);
	ft_putnbr(res);
	write(1, "\n", 1);
}
