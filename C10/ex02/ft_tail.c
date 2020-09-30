/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 14:57:29 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/22 23:54:37 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"
#include <stdio.h>

extern int errno;

int		ft_check_argvs(char **argv)
{
	int i;
	int nb;

	i = 0;
	nb= 0;
	while (argv[1][i])
		i++;
	if (argv[1][1] != 'c')
		return (0);
	if (i > 2)
	{
		argv[1][1] = '-';
		nb = ft_atoi(argv[1]);
	}
	else
		nb = atoi(argv[2]);
	return (nb);
}

int		ft_file_size(char *str)
{
	ssize_t bytes;
	char buff[BUFF_SIZE];
	int size;
	int fd;

	size = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		ft_puterror(str, strerror(errno));
		return (0);	
	}
	while ((bytes = read(fd, &buff, BUFF_SIZE)))
	{
		if (bytes < 0)
		{
			if (errno != 21)
				ft_puterror(str, (strerror(errno)));
			return (0);
		}
		size += bytes;
	}
	close (fd);
	return (size);
}

char	*ft_print_tail(char *str, int nb)
{
	int i;
	int size;
	int fd;
	char *file;
	char buff[BUFF_SIZE];
	ssize_t	bytes;

	i = 0;
	size = ft_file_size(str);
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (0);
	if (!(file = malloc(sizeof(char) * (size + 1))))
		return (0);
	while ((bytes = read(fd, &buff, BUFF_SIZE)))
	{
		if (bytes < 0)
			return (0);
		ft_strncpy_with_offset(file, buff, bytes, i);
		i += bytes;
	}
	i = size;
	while (nb > 0)
	{
		size = i - nb; 
		write(1, &file[size], 1);
		nb--;
	}
	write(1, "\n", 1);
	return (0);
}

void	ft_display(int argc, char **argv, int i, int k)
{
	int nb;

	nb = ft_check_argvs(argv);
	while (i < argc)
	{
		if (argc > k + 1)
		{
			if (i != k)
				write(1, "\n", 1);
			ft_putstr("==> ");
			ft_putstr(argv[i]);
			ft_putstr(" <==\n");
		}
		ft_print_tail(argv[i], nb);
		i++;
	}
}

int 	main(int argc, char **argv)
{
	char c;
	int i;

	i = 2;
	if (argc < 2)
		while (read(1, &c, 1));
	if (argv[1][2])
		ft_display(argc, argv, 2, 2);
	else
		ft_display(argc, argv, 3, 3);

	return (0);
}
