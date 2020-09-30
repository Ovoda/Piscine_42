/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 15:18:38 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/20 16:59:43 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SKY_H
# define SKY_H
# include <unistd.h>
# include <stdlib.h>

int		**create_comb_tab();
int		**ft_create_input_tab(char *input);
int		ft_check_line(int **comb_tab, int **input_tab, int j);
int		ft_check_all_col(int **comb_tab, int **input_tab);
int		sky(char *str);
void	ft_print_line(int *tab);
void	ft_print_tab(int **tab);
void	ft_putchar(char c);
void	ft_putstr(char *str);
#endif
