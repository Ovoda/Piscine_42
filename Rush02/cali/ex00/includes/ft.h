/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbarrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 14:46:44 by axbarrei          #+#    #+#             */
/*   Updated: 2020/09/27 20:34:02 by mterkhoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# define BUFF_SIZE 8192
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

typedef struct	s_index
{
	char *key;
	char *value;
}				t_index;

int				ft_strcmp(char *s1, char *s2);
char			*ft_strdup(char *src);
int				ft_strncmp(char *s1, char *s2, int n);
int				ft_atoi(char *str);
void			ft_putstr(char *str, int output);
t_index			*ft_dict_to_struct(char *dict);
char			**ft_input_to_tab(char *str);
int				error_scout(int argc, char *str);
void			ft_display_tab(char **tab);
void			ft_display_struct(t_index *index);
int				ft_valid_keys(char **tab, t_index *index);
int				ft_strlen(char *str);
int				ft_intlen_base(long nbr, int baselen);
char			*ft_itoa(long nbr);
void			ft_add_to_tab(char **tab, char *key);
void			ft_put_trim_str(char *str);
int				ft_isspace(char c);
int				ft_str_is_printable(char *str);
#endif
