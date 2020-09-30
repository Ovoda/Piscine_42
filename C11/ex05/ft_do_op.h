/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 12:30:24 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/23 21:02:44 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DO_OP_H
# define FT_DO_OP_H
# include <unistd.h>
# define P printf

int					add(int x, int y);
int					sub(int x, int y);
int					div(int x, int y);
int					mult(int x, int y);
int					mod(int x, int y);
int					ft_atoi(char *nbr);
void				ft_putnbr(int nb);

typedef struct		s_calcul
{
	char	ope;
	int		(*f)(int x, int y);
}					t_calcul;
#endif
