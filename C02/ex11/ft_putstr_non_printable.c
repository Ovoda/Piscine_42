/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 12:24:36 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/13 10:43:57 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_hex_char(char c)
{
	if (c < 10)
	{
		c = c + 48;
	}
	else
	{
		c = c + 87;
	}
	ft_putchar(c);
}

void	ft_putnbr_hex(char c)
{
	unsigned char		negative;
	char				n1;
	char				n2;

	if (c < 0)
	{
		negative = c;
		n1 = negative / 16;
		n2 = negative % 16;
	}
	else
	{
		n1 = c / 16;
		n2 = c % 16;
	}
	print_hex_char(n1);
	print_hex_char(n2);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str != '\0')
	{
		if (*str >= 32 && *str != 127)
		{
			ft_putchar(*str);
		}
		else
		{
			ft_putchar('\\');
			ft_putnbr_hex(*str);
		}
		++str;
	}
}

int main(void)
{
    char tab[20];
    int i;

    i = 1;
	tab[0] = 'a';
    while (i < 20)
    {
        tab[i] = -i;
        i++;
    }
    ft_putstr_non_printable(tab);
    return (0);
}
