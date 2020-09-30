/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 23:51:49 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/22 23:13:48 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_list_size(t_list **begin_list)
{
	int i;


	i = 0;
	while (begin_list[i]->next != 0)
		i++;
	return (i);
}

int main(void)
{
	t_list	*begin;

	begin = ft_create_elem}
}
