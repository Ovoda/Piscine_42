/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 22:41:42 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/28 11:09:52 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[i])
		i++;
	if (!(dest = malloc((i + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
**#include <stdio.h>
**#include <string.h>
**int main(int argc, char **argv)
**{
**	char *dest;
**	char *dest2;
**
**	(void)argc;
**	dest = ft_strdup(argv[1]);
**	dest2 = strdup(argv[1]);
**	printf("moi : %s\nla vraie : %s", dest, dest2);
**}
*/
