/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 11:45:17 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/25 11:46:18 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_is_charset(char c, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_count_words(char *str, char *charset)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (ft_is_charset(str[i], charset) && str[i])
		i++;
	while (str[i])
	{
		if (ft_is_charset(str[i], charset) &&
				!ft_is_charset(str[i - 1], charset))
			count++;
		i++;
	}
	if (!ft_is_charset(str[i - 1], charset))
		count++;
	return (count);
}

char	*ft_strdup(char *dest, char *src, char *charset, int offset)
{
	int i;
	int tmp;

	i = 0;
	tmp = offset;
	while (src[offset] != '\0' && !ft_is_charset(src[offset], charset))
	{
		i++;
		offset++;
	}
	if (!(dest = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	offset = tmp;
	while (src[offset] != '\0' && !ft_is_charset(src[offset], charset))
	{
		dest[i] = src[offset];
		offset++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	int		word_count;
	char	**dest;
	int		i;
	int		offset;

	offset = 0;
	word_count = ft_count_words(str, charset);
	if (!(dest = (char **)malloc(sizeof(char *) * word_count + 1)))
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		while (ft_is_charset(str[offset], charset))
			offset++;
		dest[i] = ft_strdup(dest[i], str, charset, offset);
		while (str[offset] != '\0' && !ft_is_charset(str[offset], charset))
			offset++;
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/*
**int main(int argc, char **argv)
**{
**	char **tab;
**	int i;
**
**	(void)argc;
**	i = 0;
**	tab = ft_split(argv[1], argv[2]);
**	for (int x = 0; tab[x]; x++)
**			printf("%s\n", tab[x]);
**}
*/
