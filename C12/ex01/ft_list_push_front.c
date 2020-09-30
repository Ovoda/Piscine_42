/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_first_elem.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 23:05:57 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/21 13:14:48 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_create_elem(void *data)
{
	t_list	*list;

	list = NULL;
	list = malloc(sizeof(t_list));
	if (list)
	{
		list->data = data;
		list->next = NULL;
	}
	return (list);
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*begin;

	if (*begin_list)
	{
		begin = ft_create_elem(data);
		begin->next = begin_list[0];
		begin_list[0] = begin;
	}
	else
		*begin_list = ft_create_elem(data);
}

#include <stdio.h>

int main()
{
	char str[] = "Hello struct";
	char str1[] = "Hello struct 2";
	int i;
	
	i = 0;
	t_list **begin_list;

	begin_list = malloc(sizeof(t_list *) * 3);
	begin_list[i] = ft_create_elem(str1);
	//ft_list_push_front(begin_list, str);
	while (begin_list[i])
		i++;
	printf("%d\n", i);
	return (0);
}
