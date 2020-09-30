/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 12:44:18 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/18 15:10:04 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	print_bits(unsigned char octet)
{
	int	z;
	int	oct;

	z = 128;
	oct = octet;
	while (z > 0)
	{
		if (oct & z)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		z = z >> 1;
	}
}

unsigned char	swap_bits(unsigned char oct)
{
	return ((oct >> 2) | (oct << 2));
}

int	main(void)
{
	print_bits(8);
	write(1, "\n", 1);
	print_bits(swap_bits(8));

	write(1, "\n", 1);
	return (0);
}
