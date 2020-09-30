/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 16:19:14 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/25 16:48:18 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFF_SIZE 4096

extern int errno;

void	ft_putstr(char *str, int output)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	write(output, str, i);
}

int main(int argc, char **argv)
{
	int fd;
	int fd2;
	ssize_t bytes;
	char buff[BUFF_SIZE];

	fd = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_WRONLY);
	if (fd < 0)
	{
		ft_putstr(strerror(errno), 2);
	}
	while ((bytes = read(fd, buff, BUFF_SIZE)))
	{
		if (bytes < 0)
		{
			ft_putstr(strerror(errno), 2);
			break ;
		}
		write(fd2, buff, bytes);
	}
	close(fd);
}
