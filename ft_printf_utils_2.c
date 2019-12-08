/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 13:22:06 by admadene          #+#    #+#             */
/*   Updated: 2019/12/03 13:22:30 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			print_format_c(t_printf *ws)
{
	int		n;
	int		width;
	char	*tmp;

	n = 0;
	width = ft_atoi_flag_c(ws->str + ws->j + 1);
	write(1, ws->str, ws->j);
	ws->len += (width) ? abs(width) + ws->j : ws->j + 1;
	while (width > 1)
	{
		write(1, " ", 1);
		width--;
	}
	write(1, &ws->format[0], 1);
	while (width < -1)
	{
		write(1, " ", 1);
		width++;
	}
	tmp = ws->str;
	ws->str = ft_strdup(ws->str + ws->i + 1);
	ws->i = 0;
	ws->j = 0;
	free(tmp);
	free(ws->format);
}

void	end_ft_printf(t_printf *ws)
{
	ws->len += ft_strlen(ws->str);
	ft_putstr(ws->str);
	free(ws->str);
	free(ws->fonct);
}
