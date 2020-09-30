/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 11:54:58 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/28 11:59:52 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BSQ_H
# define BSQ_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

int		ft_atoi(char *nbr);
char	**ft_split(char *str, char *charset);
void	ft_check_matrice(t_file *file);

#endif

