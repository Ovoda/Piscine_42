/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 15:59:29 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/27 13:04:49 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putaddr(void *addr, char *tab, int i)
{
	long addr_l;

	addr_l = (long)addr;
	while (addr_l > 0)
	{
		if (addr_l % 16 < 10)
			tab[i] = addr_l % 16 + 48;
		else
			tab[i] = addr_l % 16 + 87;
		addr_l /= 16;
		i--;
	}
	while (i >= 0)
	{
		tab[i] = '0';
		i--;
	}
}

void	ft_line(char *str, char *tab, int offset, int size)
{
	int i;
	int j;

	i = 0;
	j = 59;
	while (i < 16)
	{
		if (i >= size || str[i + offset] == '\0')
			tab[j] = ' ';
		else
		{
			if (str[i + offset] >= 32 && str[i + offset] < 127)
				tab[j] = str[i + offset];
			else
				tab[j] = '.';
		}
		i++;
		j++;
	}
}

void	ft_hex_ascii(char *str, int offset, char *tab, int j)
{
	unsigned char	u_char;

	u_char = str[offset] / 16;
	if (u_char < 10)
		tab[j] = u_char + 48;
	else
		tab[j] = u_char + 87;
	u_char = str[offset] % 16;
	if (u_char < 10)
		tab[j + 1] = u_char + 48;
	else
		tab[j + 1] = u_char + 87;
}

void	ft_hex_line(char *str, char *tab, int offset, int size)
{
	int	i;
	int	j;
	int k;

	i = 0;
	j = 19;
	k = i + offset;
	while (i < 16)
	{
		if (i >= size || str[i + offset] == '\0')
		{
			tab[j] = ' ';
			tab[j + 1] = ' ';
		}
		else
			ft_hex_ascii(str, k, tab, j);
		if (i % 2 == 1)
		{
			tab[j + 2] = ' ';
			j++;
		}
		j += 2;
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char			tab[100];
	char			*str;
	unsigned int	offset;
	unsigned int	nb_of_char_to_print;

	offset = 0;
	nb_of_char_to_print = 16;
	str = (char *)addr;
	while (size > 0)
	{
		ft_putaddr(addr + offset, tab, 16);
		tab[16] = '0';
		tab[17] = ':';
		tab[18] = ' ';
		ft_hex_line(str, tab, offset, size);
		ft_line((char*)addr, tab, offset, size);
		write(1, tab, 75);
		write(1, "\n", 1);
		if (size >= 16)
			size -= 16;
		else
			size = 0;
		offset += 16;
	}
	return (addr);
}

int main()
{
	char *tab;

	tab = "bonjour je suis actuellment tres content car jai un bon mate pour le bsq";
	ft_print_memory(tab, 52);
	return (0);
}
