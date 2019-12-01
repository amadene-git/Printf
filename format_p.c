/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 17:49:51 by admadene          #+#    #+#             */
/*   Updated: 2019/12/01 17:50:03 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*format_p(void *ptr)
{
	char	*ret;

	if (!(ret = ft_llutoxa((unsigned long long int)ptr)))
		return (NULL);
	if (!(ret = insert_string(ret, ft_strdup("0x"), 0, 0)))
		return (NULL);
	return (ret);
}

char	*flag_p_null(char *format)
{
	char	*ret;

	if (!(ret = ft_strdup("0x")))
		return (NULL);
	free(format);
	return (ret);
}

char	*flag_p_positive(int width, int precision, char *format, char *ret)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (width > 0)
	{
		if (width > ft_strlen(format))
			ret[i++] = ' ';
		else if (format[j])
		{
			ret[i++] = format[j++];
			precision--;
		}
		width--;
	}
	if (ft_strlen(format) > j && precision)
		ret = flag_d_after(i, precision, ret, format + j);
	return (ret);
}

char	*flag_p_negative(int width, int precision, char *format, char *ret)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (width < 0)
	{
		if (format[j])
		{
			ret[i++] = format[j++];
			precision--;
		}
		else if (width)
			ret[i++] = ' ';
		width++;
	}
	if (ft_strlen(format) > j && precision)
		ret = flag_d_after(i, precision, ret, format + j);
	return (ret);
}

char	*flag_p(char *format, char *flag)
{
	int		width;
	int		precision;
	int		zero;

	if (!(zero = 0) && flag[0] == '0')
		zero = 1;
	set_flag(flag, &precision, &width, &zero);
	set_width_and_precision(zero, &precision, &width, ft_strlen(format));
	free(flag);
	if (!(flag = (char*)ft_calloc(sizeof(char), ft_strlen(format)\
	+ (ABS(width)) + (ABS(precision)))))
		return (NULL);
	format = (ft_strlen(format) == 3 && precision == 0)\
	? flag_p_null(format) : format;
	flag = (width > 0) ? flag_p_positive(width, precision, format, flag)\
	: flag_p_negative(width, precision, format, flag);
	free(format);
	return (flag);
}
