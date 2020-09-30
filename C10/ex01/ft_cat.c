/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 11:20:12 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/30 12:04:47 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFF_SIZE 2048
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

extern int errno;

void	ft_putstr(char *str, char *name)
{
	int i;

	i = 0;
	write(2, "./ft_cat: ", 10);
	while (name[i])
		i++;
	write(2, name, i);
	write(2, ": ", 2);
	i = 0;
	while (str[i])
		i++;
	write(2, str, i);
	write(2, "\n", 1);
}

int		ft_display_file(char *str)
{
	int fd;
	int byte;
	char buff[BUFF_SIZE];

	
	fd = open(str, O_RDONLY);
	if (fd < 0)
		ft_putstr(strerror(errno), str);
	else
	{
		while ((byte = read(fd, buff, BUFF_SIZE)))
		{
			if (byte == -1)
			{
				ft_putstr(strerror(errno), str);
				return (0);
			}
			write(1, buff, byte);
		}
	}
	close(fd);
	return (1);
}

int main(int argc, char **argv)
{
	int i;
	char buff[BUFF_SIZE];
	ssize_t bytes;

	i = 1;
	if (argc < 2)
	{
		while ((bytes = read(1, buff, BUFF_SIZE)))
			write(1, buff, bytes);
	}
	while (i < argc)
	{
		if (argv[i][0] == '-' && !argv[i][1])
		{
			while ((bytes = read(1, buff, BUFF_SIZE)))
			write(1, buff, bytes);
		}
		else
			ft_display_file(argv[i]);
		i++;
	}
	return (0);
}
