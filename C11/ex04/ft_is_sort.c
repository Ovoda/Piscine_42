/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 09:51:20 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/23 18:20:55 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort_descending(int *tab, int length, int (*f)(int, int))
{
	int i;

	i = 1;
	while (i < length)
	{
		if (f(tab[i - 1], tab[i]) < 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_sort_ascending(int *tab, int length, int (*f)(int, int))
{
	int i;

	i = 1;
	while (i < length)
	{
		if (f(tab[i - 1], tab[i]) > 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	if (ft_is_sort_descending(tab, length, f) ||
			ft_is_sort_ascending(tab, length, f))
		return (1);
	return (0);
}


#include <stdio.h>

int	ft_intcmp(int x, int y)
{
	return (x - y);
}

int main(void)
{
	int tab[] = {};
	int tab1[] = {1, 2, 3, 5, 9};
	int tab2[] = {0, 0, 0, 0, 0};
	int tab3[] = {1, 0, 0, 0, 2};
	int tab4[] = {5, 4, 3, 2, 1};

	if (ft_is_sort(tab1, 5, &ft_intcmp) == 0)
		printf("Non sorted tab\n");
	else
		printf("Sorted tab\n");
	if (ft_is_sort(tab2, 5, &ft_intcmp) == 0)
		printf("Non sorted tab\n");
	else
		printf("Sorted tab\n");
	if (ft_is_sort(tab3, 5, &ft_intcmp) == 0)
		printf("Non sorted tab\n");
	else
		printf("Sorted tab\n");
	if (ft_is_sort(tab4, 5, &ft_intcmp) == 0)
		printf("Non sorted tab\n");
	else
		printf("Sorted tab\n");
	if (ft_is_sort(tab, 5, &ft_intcmp) == 0)
		printf("Non sorted tab\n");
	else
		printf("Sorted tab\n");
	return (0);
}

