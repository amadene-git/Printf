/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:53:51 by admadene          #+#    #+#             */
/*   Updated: 2019/12/01 14:53:53 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi_flag_c(char *str)
{
	int i;
	int ret;
	int signe;

	i = 0;
	ret = 0;
	signe = (*str == '-') ? -1 : 1;
	while (str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		ret = (ret * 10) + ((str[i] - '0') * signe);
		i++;
	}
	return (ret);
}

char	*format_c(int c)
{
	char	*str;

	if (!(str = (char*)malloc(sizeof(char) * 2)))
		return (NULL);
	str[0] = c;
	str[1] = 0;
	return (str);
}

char	*flag_c(char *format, char *flag)
{
	int		i;
	int		width;
	char	*ret;

	i = 0;
	width = abs(ft_atoi_flag_c(flag));
	if (!(ret = (char*)ft_calloc(sizeof(char), width + 2)))
		return (NULL);
	while (width > 1)
	{
		ret[i++] = ' ';
		width--;
	}
	ret[i++] = *format;
	ret[i] = 0;
	ret = (ft_atoi_flag_c(flag) < 0) ? ft_strrev(ret) : ret;
	free(format);
	free(flag);
	return (ret);
}
