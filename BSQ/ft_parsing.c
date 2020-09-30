/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 08:16:50 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/30 22:36:52 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int     ft_str_is_printable(char str)
{
    if (str == 0)
        return (1);
    if (str < ' ' || str >= 127)
        return (0);
    return (1);
}
int ft_check_param_lines(t_file file)
{
    int i;
    int count;

    i = file.nb_lines;
    count = 0;
    if (ft_str_is_printable(file.full) == 0)
        return (0);
    if (ft_str_is_printable(file.obstacle) == 0)
        return (0);
    if (ft_str_is_printable(file.empty) == 0)
        return (0);
    while (i >= 1)
    {
        i = i / 10;
        count++;
    }
    if((count + 3) != file.param_size)
        return (0);
    return (1);
}
