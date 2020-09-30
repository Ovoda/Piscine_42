/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 16:24:53 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/25 13:13:19 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#define BUFF_SIZE 28000

int		ft_return_error(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	write(2, str, i);
	return (0);
}

int	main(int argc, char **argv)
{
	int fd;
	char 	buff[BUFF_SIZE];
	ssize_t	bytes;

	fd = open(argv[1], O_RDONLY);
	if (argc > 2)
		return (ft_return_error("Too many arguments.\n"));
	else if (argc < 2)
		return (ft_return_error("File name missing.\n"));
	else if (fd < 0)
		return (ft_return_error("Cannot read file.\n"));
	while ((bytes = read(fd, buff, BUFF_SIZE)))
	{
		if (bytes == -1)
			return (ft_return_error("Cannot read file.\n"));
		write(1, buff, bytes);
	}
	close(fd);
	return (0);
}
