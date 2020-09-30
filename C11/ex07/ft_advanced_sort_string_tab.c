/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 17:56:34 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/22 22:02:30 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_string(char **s1, char **s2)
{
	char *tmp_str;

	tmp_str = *s1;
	*s1 = *s2;
	*s2 = tmp_str;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		j = 0;
		while (tab[j + 1])
		{
			if (cmp(tab[j], tab[j + 1]) > 0)
				ft_swap_string(&tab[j], &tab[j + 1]);
			j++;
		}
		i++;
	}
}

/*
**#include <stdio.h>
**
**int ft_strlen(char *str)
**{
**	int i;
**
**	i = 0;
**	while (str[i])
**		i++;
**	return (i);
**}
**
**int	ft_cmp(char *s1, char *s2)
**{
**	return (ft_strlen(s1) - ft_strlen(s2));
**}
**
**int main(int argc, char **argv)
**{
**	int i;
**	char **dest;
**
**	ft_advanced_sort_string_tab(argv, &ft_cmp);
**
**	while (argv[i])
**	{
**		printf("%s\n", argv[i]);
**		i++;
**	}
**	return (0);
**}
*/
