/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 15:04:41 by admadene          #+#    #+#             */
/*   Updated: 2019/12/01 15:04:43 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*format_d(int nb)
{
	char	*ret;

	if (!(ret = ft_itoa(nb)))
		return (NULL);
	return (ret);
}

char	*flag_d_positive(int width, int precision, char *format, char *ret)
{
	int i;
	int j;

	i = 0;
	j = 0;
	width = (width < precision) ? precision : width;
	while (width > 0)
	{
		if (width > precision && width > ft_strlen(format))
			ret[i++] = ' ';
		else if (precision > ft_strlen(format))
		{
			ret[i++] = '0';
			precision--;
		}
		else if (format[j])
		{
			ret[i++] = format[j++];
			precision--;
		}
		width--;
	}
	if (ft_strlen(format) > j)
		ret = flag_d_after(i, precision, ret, format + j);
	return (ret);
}

char	*flag_d_negative(int width, int precision, char *format, char *ret)
{
	int i;
	int j;

	i = 0;
	j = 0;
	width = (abs(width) < precision) ? precision * -1 : width;
	while (width < 0)
	{
		if (precision > ft_strlen(format))
		{
			ret[i++] = '0';
			precision--;
		}
		else if (format[j])
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

char	*flag_d_null(char *format)
{
	char	*ret;

	if (!(ret = ft_strdup("")))
		return (NULL);
	free(format);
	return (ret);
}

char	*flag_d(char *fmt, char *flag)
{
	int		width;
	int		precision;
	int		zero;
	int		signe;
	char	*ret;

	if (!(signe = 0) && fmt[0] == '-')
	{
		signe = 1;
		fmt++;
	}
	if (!(zero = 0) && flag[0] == '0')
		zero = 1;
	set_flag(flag, &precision, &width, &zero);
	set_width_and_precis(zero, &precision, &width, len_f(fmt, precision));
	if (!(ret = (char*)ft_calloc(sizeof(char), ft_strlen(fmt)\
	+ (abs(width)) + (abs(precision) + 1))))
		return (NULL);
	fmt = (fmt[0] == '0' && precision == 0) ? flag_d_null(fmt) : fmt;
	ret = (width > 0) ? flag_d_positive(width, precision, fmt, ret)\
	: flag_d_negative(width, precision, fmt, ret);
	ret = (signe) ? put_minus(ret, flag) : ret;
	free(flag);
	free(fmt - signe);
	return (ret);
}
