/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 15:21:22 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/25 15:47:42 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	int i;

	i = 0;
	while (begin_list[i].next)
	{
		(*f)(begin_list[i].data);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	printf("%d", nb);
}

int main()
{
	t_list *begin_list;
	
	begin_list = &begin_list[0];
	begin_list[0].next = &begin_list[1];
	begin_list[1].next = &begin_list[2];
	begin_list[2].next = &begin_list[3];
	begin_list[3].next = NULL;
	begin_list[0].data = (void *)12;
	begin_list[1].data = (void *)3;
	begin_list[2].data = (void *)14;
	begin_list[3].data = (void *)15;
	ft_list_foreach(begin_list, &ft_putnbr);
}
