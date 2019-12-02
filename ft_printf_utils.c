/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:09:34 by admadene          #+#    #+#             */
/*   Updated: 2019/12/02 15:09:50 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*insert_string(char *str, char *to_insert, int start, int end)
{
	char	*ret;
	int		i;

	if (!(ret = (char*)ft_calloc(sizeof(char), (ft_strlen(str) \
	+ ft_strlen(to_insert) + (end - start) + 1))))
		return (NULL);
	i = -1;
	while (++i < start)
		ret[i] = str[i];
	while (i < start + ft_strlen(to_insert))
	{
		ret[i] = to_insert[i - start];
		i++;
	}
	while (str[i - ft_strlen(to_insert) + (end - start)])
	{
		ret[i] = str[i - ft_strlen(to_insert) + (end - start)];
		i++;
	}
	ret[i] = 0;
	free(str);
	free(to_insert);
	return (ret);
}

int		is_flag(char c)
{
	if ((c >= '0' && c <= '9') || c == '.' || c == '*' || c == '-')
		return (1);
	return (0);
}

char	*read_flag(char *str)
{
	int		i;
	char	*ret;

	i = 0;
	while (is_flag(str[i]))
		i++;
	if (!(ret = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (is_flag(str[i]))
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

int		is_format(char c)
{
	if (c == 'c' || c == 'p' || c == 'd' || c == 'i' ||
	c == 's' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	return (0);
}
