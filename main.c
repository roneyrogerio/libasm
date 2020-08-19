/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 16:51:18 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/08/05 18:54:50 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void	strlen_test(char *str)
{
	printf("#########################################\n");
	printf("############### ft_strlen ###############\n");
	printf("#########################################\n");
	printf("string    = \"%s\"\n", str);
	printf("-----------------------------------------\n");
	printf("strlen    = %lu\n", strlen(str));
	printf("ft_strlen = %lu\n", ft_strlen(str));
	printf("-----------------------------------------\n");
}

void	strcpy_test(char *str, char *str2)
{
	char	*ret;

	printf("#########################################\n");
	printf("############### ft_strcpy ###############\n");
	printf("#########################################\n");
	printf("string    = \"%s\"\n", str);
	printf("-----------------------------------------\n");
	ret = strcpy(str2, str);
	printf("strcpy    = \"%s\"\n", ret);
	printf("return    = %p\n", ret);
	bzero(str2, 25);
	ret = ft_strcpy(str2, str);
	printf("ft_strcpy = \"%s\"\n", ret);
	printf("return    = %p\n", ret);
	printf("-----------------------------------------\n");
}

void	strcmp_test(char *str, char *str2)
{
	int	ret;

	printf("#########################################\n");
	printf("############### ft_strcmp ###############\n");
	printf("#########################################\n");
	printf("string    = \"%s\"\n", str);
	printf("string2   = \"%s\"\n", str2);
	printf("-----------------------------------------\n");
	ret = strcmp(str, str2);
	printf("strcmp    = \"%d\"\n", ret);
	ret = ft_strcmp(str, str2);
	printf("ft_strcmp = \"%d\"\n", ret);
	printf("-----------------------------------------\n");
}

void	write_test(char *str)
{
	printf("#########################################\n");
	printf("################ ft_write ###############\n");
	printf("#########################################\n");
	printf("string    = \"%s\"\n", str);
	printf("-----------------------------------------\n");
	write(1, "write     = \"", 13);
	write(1, str, 24);
	write(1, "\"\n", 2);
	write(1, "ft_write  = \"", 13);
	write(1, str, 24);
	write(1, "\"\n", 2);
	printf("-----------------------------------------\n");
}

void	read_test(void)
{
	char	buffer[999];
	char	*ptr;

	printf("#########################################\n");
	printf("################# ft_read ###############\n");
	printf("#########################################\n");
	printf("-----------------------------------------\n");
	read(0, buffer, 999);
	ptr = strchr(buffer, '\n');
	ptr[0] = '\0';
	printf("read      = \"%s\"\n", buffer);
	ft_read(0, buffer, 999);
	ptr = strchr(buffer, '\n');
	ptr[0] = '\0';
	printf("ft_read   = \"%s\"\n", buffer);
	printf("-----------------------------------------\n");
}

void	strdup_test(char *str)
{
	char	*ptr;

	printf("#########################################\n");
	printf("############### ft_strdup ###############\n");
	printf("#########################################\n");
	printf("string    = \"%s\"\n", str);
	printf("-----------------------------------------\n");
	ptr = strdup(str);
	printf("strdup    = \"%s\"\n", ptr);
	free(ptr);
	ptr = ft_strdup(str);
	printf("ft_strdup = \"%s\"\n", ptr);
	free(ptr);
	printf("-----------------------------------------\n");
}

int		main(void)
{
	char	*str;
	char	str2[25];

	str = "abcdefghijlmopqrstuvwxyz";
	strlen_test(str);
	strcpy_test(str, str2);
	strcmp_test(str, "abcdf");
	write_test(str);
	read_test();
	strdup_test(str);
	return (0);
}
