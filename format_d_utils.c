/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_d_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 15:07:14 by admadene          #+#    #+#             */
/*   Updated: 2019/12/01 15:07:27 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*flag_d_after(int i, int precision, char *ret, char *format)
{
	while (precision && *format)
	{
		ret[i++] = *format++;
		precision--;
	}
	ret[i] = 0;
	return (ret);
}

char	*put_minus(char *ret)
{
	int i;

	i = 0;
	while (!ft_isdigit(ret[i]))
		i++;
	if (i != 0)
		ret = insert_string(ret, ft_strdup("-"), i - 1, i);
	else
		ret = insert_string(ret, ft_strdup("-"), 0, 0);
	return (ret);
}

void	set_width_and_precision(int zero, int *precision, int *width, int len)
{
	if (*precision < 0 && zero)
		*precision = *width;
	else if ((*precision < 0 && !zero) || *precision < len)
		*precision = len;
	if (*width > 0 && *precision > *width)
		*width = *precision;
	else if (*width < 0 && *precision > *width * -1)
		*width = *precision * -1;
}

void	set_flag(char *flag, int *precision, int *width, int *zero)
{
	int i;

	i = 0;
	*width = ft_atoi_flag_c(flag + *zero);
	while (flag[i] && flag[i] != '.')
		i++;
	if (flag[i] == '.')
	{
		*precision = ft_atoi_flag_c(flag + i + 1);
		if (*precision > 0)
			*zero = 0;
	}
	else
		*precision = -1;
}
