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
	while (width > 0)
	{
		if (width > precision)
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
	if (ft_strlen(format) > j && precision)
		ret = flag_d_after(i, precision, ret, format + j);
	return (ret);
}

char	*flag_d_negative(int width, int precision, char *format, char *ret)
{
	int i;
	int j;

	i = 0;
	j = 0;
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

char	*flag_d(char *format, char *flag)
{
	int		width;
	int		precision;
	int		zero;
	int		signe;

	if (!(signe = 0) && format[0] == '-')
	{
		signe = 1;
		format++;
	}
	if (!(zero = 0) && flag[0] == '0')
		zero = 1;
	set_flag(flag, &precision, &width, &zero);
	set_width_and_precis(zero, &precision, &width, ft_strlen(format));
	free(flag);
	if (!(flag = (char*)ft_calloc(sizeof(char), ft_strlen(format)\
	+ (abs(width)) + (abs(precision)))))
		return (NULL);
	format = (format[0] == '0' && precision == 0)\
	? flag_d_null(format) : format;
	flag = (width > 0) ? flag_d_positive(width, precision, format, flag)\
	: flag_d_negative(width, precision, format, flag);
	flag = (signe) ? put_minus(flag) : flag;
	free(format - signe);
	return (flag);
}
