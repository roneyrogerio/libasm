/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 16:51:18 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/08/30 15:20:23 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

void	strlen_test(char *str)
{
	printf("#########################################\n");
	printf("############### ft_strlen ###############\n");
	printf("#########################################\n");
	printf("string    = \"%s\"\n", str);
	printf("-----------------------------------------\n");
	printf("strlen    = %lu, errno = %d\n", strlen(str), errno);
	printf("ft_strlen = %lu, errno = %d\n", ft_strlen(str), errno);
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
	printf("return    = %p, errno = %d\n", ret, errno);
	bzero(str2, 25);
	ret = ft_strcpy(str2, str);
	printf("ft_strcpy = \"%s\"\n", ret);
	printf("return    = %p, errno = %d\n", ret, errno);
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
	printf("strcmp    = \"%d\", errno = %d\n", ret, errno);
	ret = ft_strcmp(str, str2);
	printf("ft_strcmp = \"%d\", errno = %d\n", ret, errno);
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
	write(1, str, ft_strlen(str));
	write(1, "\"\n", 2);
	printf("errno = %d\n", errno);
	write(1, "ft_write  = \"", 13);
	write(1, str, ft_strlen(str));
	write(1, "\"\n", 2);
	printf("errno = %d\n", errno);
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
	printf("read      = \"%s\", errno = %d\n", buffer, errno);
	ft_read(0, buffer, 999);
	ptr = strchr(buffer, '\n');
	ptr[0] = '\0';
	printf("ft_read   = \"%s\", errno = %d\n", buffer, errno);
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
	printf("errno = %d\n", errno);
	free(ptr);
	ptr = ft_strdup(str);
	printf("ft_strdup = \"%s\"\n", ptr);
	printf("errno = %d\n", errno);
	free(ptr);
	printf("-----------------------------------------\n");
}

int		main(void)
{
	char	*str;
	char	str2[25000];

	str = "abcdefghijlmopqrstuvwxyz";
	strlen_test(str);
	strcpy_test(str, str2);
	strcmp_test(str, "abcdf");
	write_test(str);
	read_test();
	strdup_test(str);
	return (0);
}
