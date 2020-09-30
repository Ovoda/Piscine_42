/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 22:13:22 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/25 12:30:34 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

//void	ft_read_files(int fd)
//{
//	int i;
//	char buff[BUFF_SIZE];
//	ssize_t bytes;
//	char *tab;
//	char *tmp_tab;
//	char asterix;
//	int count;
//
//	i = 0;
//	count = 0;
//	asterix = '\0';
//	tab = malloc(sizeof(char) * 16);
//	tmp_tab = malloc(sizeof(char) * 16);
//	tmp_tab[0] = '\0';
//	while ((bytes = read(fd, &buff, 16)))
//	{
//		if (bytes < 0)
//			ft_puterror(strerror(errno));
//		while (bytes > 0)
//		{
//			if (bytes >= 16)
//			{	
//				tab = ft_str_to_hexa(buff, 16);
//				tab[47] = '\0';
//			}
//			else
//			{
//				tab = ft_str_to_hexa(buff, bytes);
//				i = (bytes * 3) - 3;
//				tab[i] = '\0';
//			}
//			if (strcmp(tab, tmp_tab) == 0)
//			{
//				if (asterix != '*')
//				{
//					asterix = '*';
//					tab[0] = '*';
//				}
//			}
//			else
//			{
//				asterix = '\0';
//				ft_display_hex_num(count);
//				if (tab[0] == '*')
//					write(1, "*", 1);
//				else if (bytes >= 16)
//					write(1, tab, 47);
//				else
//					write(1, tab, (bytes * 3 - 1));
//				write(1, "\n", 1);
//			}
//			count++;
//			tmp_tab = strcpy(tmp_tab, tab);
//			bytes -= 16;
//		}
//	}
//}

void	ft_putstr(char *str, int output)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	write(output, str, i);
}

void	ft_put_error(t_file file)
{
	ft_putstr("hexdump: ", 2);
	ft_putstr(file.name, 2);
	ft_putstr(": ", 2);
	ft_putstr(strerror(file.error), 2);
	ft_putstr("\n", 2);
}

void	ft_display(ssize_t bytes, t_file file, char *buff)
{
	char *dest;

	dest = malloc(sizeof(char) * (bytes * 3) - 3);
	dest = strcpy(dest, buff);
	while (bytes > 0)
	{
		dest = ft_str_to_hexa(buff, dest);
		write(1, dest, 32);
		write(1, "\n", 1);
		dest += 16;
		bytes -= 16;
	}
}

void	ft_open_files(t_file *file_stock)
{
	int i;
	int fd;

	i = 0;
	while (file_stock[i].name != 0)
	{
		fd = open(file_stock[i].name, O_RDONLY);
		if (fd < 0)
		{
			file_stock[i].error = errno;
			ft_put_error(file_stock[i]);
		}
		i++;
	}
}

void	ft_read_files(t_file *file_stock)
{
	int i;
	char buff[BUFF_SIZE];
	ssize_t bytes;

	i = 0;
	while (file_stock[i].name != 0)
	{
		while ((bytes = read(file_stock[i].fd, buff, BUFF_SIZE)))
		{
			if (bytes < 0)
			{
				file_stock[i].error = errno;
				ft_put_error(file_stock[i]);
			}
			ft_display(bytes, file_stock[i], buff);
		}
		i++;
	}
}
