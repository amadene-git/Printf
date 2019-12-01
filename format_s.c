/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 15:00:49 by admadene          #+#    #+#             */
/*   Updated: 2019/12/01 15:01:02 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*format_s(char *str)
{
	char *ret;

	if (!str)
	{
		if (!(ret = ft_strdup("(null)")))
			return (NULL);
		return (ret);
	}
	if (!(ret = ft_strdup(str)))
		return (NULL);
	return (ret);
}

char	*flag_s_positive(int width, int precision, char *format, char *ret)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (width > 0)
	{
		if (width > precision)
			ret[i++] = ' ';
		else if (precision && format[j])
		{
			ret[i++] = format[j++];
			precision--;
		}
		width--;
	}
	if (ft_strlen(format) > j && precision)
		while (precision && format[j])
		{
			ret[i++] = format[j++];
			precision--;
		}
	ret[i] = 0;
	return (ret);
}

char	*flag_s_negative(int width, int precision, char *format, char *ret)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (width < 0)
	{
		if (precision && format[j])
		{
			ret[i++] = format[j++];
			precision--;
		}
		else if (width < 0)
			ret[i++] = ' ';
		width++;
	}
	if (ft_strlen(format) > j && precision)
		while (precision && format[j])
		{
			ret[i++] = format[j++];
			precision--;
		}
	ret[i] = 0;
	return (ret);
}

char	*flag_s(char *format, char *flag)
{
	int		width;
	int		precision;
	char	*ret;
	int		i;

	i = 0;
	width = ft_atoi_flag_c(flag);
	while (flag[i] != '.' && flag[i])
		i++;
	if (flag[i] == '.')
		precision = ft_atoi_flag_c(flag + i + 1);
	else
		precision = -1;
	if (precision > ft_strlen(format) || precision < 0)
		precision = ft_strlen(format);
	if (!(ret = (char*)ft_calloc(sizeof(char), ft_strlen(format)\
	+ (ABS(precision)) + (ABS(width)))))
		return (NULL);
	if (width > 0)
		ret = flag_s_positive(width, precision, format, ret);
	else
		ret = flag_s_negative(width, precision, format, ret);
	free(format);
	free(flag);
	return (ret);
}
