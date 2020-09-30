/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexdump.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 15:04:26 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/25 12:23:26 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEXDUMP_H
# define HEXDUMP_H
# define PF(name, size) printf("File : %s, size : %d\n", name, size);
# define pd(X) printf("- %d\n", X);

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

typedef struct	s_param
{
	int	c_flag;
	int addr_length;
}				param;

typedef struct s_file
{
	int size;
	char *name;
	int fd;
	int error;
}				t_file;

char	*ft_str_to_hexa(char *str, char *tab);
char	*ft_strncat_count(int count, char *tab);
char	*ft_strncat(char *dest, char *src, int n);
int		ft_file_size(int fd);
t_file	*ft_create_file_stock(int argc, char **argv);
void	ft_open_files(t_file *file_stock);
void	ft_read_files(t_file *file_stock);
void	ft_put_error(t_file file);

extern int errno;

# define BUFF_SIZE 4096

#endif
