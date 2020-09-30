/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbarrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 14:46:44 by axbarrei          #+#    #+#             */
/*   Updated: 2020/09/26 22:11:54 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# define BUFF_SIZE 4096
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

typedef struct	s_index
{
	char *key;
	char *value;
}				t_index;

int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, int n);
int		ft_atoi(char *str);
char	ft_strdup(char *src);
void	ft_putstr(char *str, int output);
t_index *ft_dict_to_struct(char *dict);
char	**ft_input_to_tab(char *str);
int		error_scout(int argc, char *str);

void	ft_display_tab(char **tab);
void	ft_display_struct(t_index *index);

extern int errno;

#endif
