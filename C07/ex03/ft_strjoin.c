/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 12:26:23 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/16 10:30:11 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int
	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char
	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	j = 0;
	if (dest[0] == '\0')
		i = 0;
	else
		i = ft_strlen(dest);
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char
	*create_dest(int size, char **strs, char *sep)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	len += ft_strlen(sep) * size - 1;
	if (!(dest = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	return (dest);
}

char
	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*dest;

	i = 0;
	dest = create_dest(size, strs, sep);
	dest[0] = '\0';
	while (i < size)
	{
		ft_strcat(dest, strs[i]);
		if (i != size - 1)
			ft_strcat(dest, sep);
		i++;
	}
	return (dest);
}

/*
**int main(int argc, char **argv)
**{
**	printf("%s", (ft_strjoin(0, argv, " |sep| ")));
**}
*/
