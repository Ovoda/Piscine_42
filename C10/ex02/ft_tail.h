/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 12:18:04 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/22 23:02:01 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H
# define BUFF_SIZE 28000
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

void	ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_atoi(char *str);
void	ft_strncpy_with_offset(char *dest, char *src, int n, int i);
void	ft_puterror(char *str, char *error);

extern int errno;

#endif
