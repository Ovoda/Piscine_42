/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 10:55:37 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/28 11:10:49 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     is_in_charset(char str, char *charset)
{
	int i;
	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == str)
			return (1);
		i++;
	}
	return (0);
}
int     count_words(char *str, char *charset)
{
	int count;
	int i;
	i = 0;
	count = 0;
	if (is_in_charset(str[0], charset) == 0)
		count++;
	while (str[i])
	{
		if (is_in_charset(str[i + 1], charset) == 0
				&& is_in_charset(str[i], charset) == 1 && str[i + 1])
		{
			count++;
		}
		i++;
	}
	return (count);
}
char    *ft_add_word(char *str, int i, char *charset)
{
	int     size_word;
	char    *word;
	int     tmp;
	int     k;
	k = 0;
	tmp = i;
	size_word = 0;
	while (is_in_charset(str[i], charset) == 0 && str[i])
	{
		size_word++;
		i++;
	}
	word = malloc(sizeof(char) * (size_word + 1));
	i = tmp;
	while (is_in_charset(str[i], charset) == 0 && str[i])
	{
		word[k] = str[i];
		i++;
		k++;
	}
	word[k] = '\0';
	return (word);
}
char    **ft_split(char *str, char *charset)
{
	const int   number_words = count_words(str, charset);
	char        **dest;
	int         k;
	int         i;
	i = -1;
	k = 0;
	dest = malloc(sizeof(char*) * (number_words + 1));
	if (dest == 0)
		return (0);
	if (is_in_charset(str[0], charset) == 0 && str[i + 1])
	{
		dest[k++] = ft_add_word(str, 0, charset);
	}
	while (str[++i] && str[i + 1])
	{
		if (is_in_charset(str[i + 1], charset) == 0
				&& is_in_charset(str[i], charset) == 1)
		{
			dest[k] = ft_add_word(str, i + 1, charset);
			k++;
		}
	}
	dest[k] = 0;
	return (dest);
}
