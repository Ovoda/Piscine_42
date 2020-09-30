/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 13:13:42 by calide-n          #+#    #+#             */
/*   Updated: 2020/09/14 20:07:37 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int ft_strcmp(char *dest, char *src);
int ft_strncmp(char *dest, char *src, unsigned int n);
char *ft_strcat(char *dest, char *src);
char *ft_strncat(char *dest, char *src, unsigned int nb);
char *ft_strstr(char *str, char *to_find);

int main()
{
    char dest[10] = "1234";
    char dest1[10] = "1";
    char dest2[10] = "9874";
    char dest00[10] = "1234";
    char dest11[10] = "1";
    char dest22[10] = "9874";
    char dest000[10] = "1234";
    char dest111[10] = "1";
    char dest222[10] = "9874";
    char dest0000[10] = "1234";
    char dest1111[10] = "1";
    char dest2222[10] = "9874";

    printf("***FT_STRCMP***\n");
    printf("ft_strcmp: %d\n", ft_strcmp("bonjour", "hello"));
    printf("ft_strcmp: %d\n", ft_strcmp("1", "hello"));
    printf("ft_strcmp: %d\n", ft_strcmp("bonjour", ""));
    printf("ft_strcmp: %d\n", ft_strcmp("", "hello"));
    printf("ft_strcmp: %d\n", ft_strcmp("ab", "bcdef"));
    printf("strcmp: %d\n", strcmp("bonjour", "hello"));
    printf("strcmp: %d\n", strcmp("1", "hello"));
    printf("strcmp: %d\n", strcmp("bonjour", ""));
    printf("strcmp: %d\n", strcmp("", "hello"));
    printf("strcmp: %d\n", strcmp("ab", "bcdef"));
    printf("***FT_STRNCMP***\n");
    printf("ft_strcmp: %d\n", ft_strncmp("bonjour", "hello", 1));
    printf("ft_strcmp: %d\n", ft_strncmp("1", "hello", 2));
    printf("ft_strcmp: %d\n", ft_strncmp("bonjour", "", 3));
    printf("ft_strcmp: %d\n", ft_strncmp("", "hello", 4));
    printf("ft_strcmp: %d\n", ft_strncmp("ab", "bcdef", 5));
    printf("strcmp: %d\n", strncmp("bonjour", "hello", 1));
    printf("strcmp: %d\n", strncmp("1", "hello", 2));
    printf("strcmp: %d\n", strncmp("bonjour", "", 3));
    printf("strcmp: %d\n", strncmp("", "hello", 4));
    printf("strcmp: %d\n", strncmp("ab", "bcdef", 5));
    printf("***FT_STRCAT***\n");
    printf("ft_strcat: %s\n", ft_strcat(dest, "567"));
    printf("ft_strcat: %s\n", ft_strcat(dest1, "2345678"));
    printf("ft_strcat: %s\n", ft_strcat(dest2, ""));
    printf("strcat: %s\n", strcat(dest00, "567"));
    printf("strcat: %s\n", strcat(dest11, "2345678"));
    printf("strcat: %s\n", strcat(dest22, ""));
    printf("***FT_STRNCAT***\n");
    printf("ft_strncat: %s\n", ft_strncat(dest000, "567", 1));
    printf("ft_strncat: %s\n", ft_strncat(dest111, "2345678", 2));
    printf("ft_strncat: %s\n", ft_strncat(dest222, "", 3));
    printf("strncat: %s\n", strncat(dest0000, "567", 1));
    printf("strncat: %s\n", strncat(dest1111, "2345678", 2));
    printf("strncat: %s\n", strncat(dest2222, "", 3));
    printf("***FT_STRSTR***\n");
    printf("ft_strstr: %s\n", ft_strstr("bonjour les ours", "our"));
    printf("ft_strstr: %s\n", ft_strstr("bonjour les ours", ""));
    printf("ft_strstr: %s\n", ft_strstr("bonjour les ours", "s"));
    printf("strstr: %s\n", strstr("bonjour les ours", "our"));
    printf("strstr: %s\n", strstr("bonjour les ours", ""));
    printf("strstr: %s\n", strstr("bonjour les ours", "s"));
}

