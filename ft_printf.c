/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 14:40:48 by admadene          #+#    #+#             */
/*   Updated: 2019/11/28 14:40:50 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_wildcard(char *str, int *i, va_list *ap)
{
	while (str[++*i] && is_flag(str[*i]))
		if (str[*i] == '*')
			str = insert_string(str, ft_itoa(va_arg(*ap, int)), *i, *i + 1);
	return (str);
}

char	*get_percent(char *str, char *format, int *i, int *j)
{
	format = format_percent(read_flag(str + *j + 1));
	str = insert_string(str, format, *j, *i + 1);
	(*j)++;
	return (str);
}

void	structure_init(t_printf *ws, char const *fmt)
{
	ws->fonct = fonction_format_init();
	ws->fonct = fonction_flag_init(ws->fonct);
	ws->str = ft_strdup(fmt);
	ws->i = 0;
	ws->j = 0;
}

void	convert_format(t_printf *ws)
{
	ws->format = (ws->fonct + ws->str[ws->i])->f(va_arg(ws->ap, void*));
	ws->format = (ws->fonct + ws->str[ws->i])->flag(ws->format,\
	read_flag(ws->str + ws->j + 1));
	ws->str = insert_string(ws->str, ws->format, ws->j, ws->i + 1);
}

int		ft_printf(char const *fmt, ...)
{
	t_printf ws;

	va_start(ws.ap, fmt);
	structure_init(&ws, fmt);
	while (ws.str[ws.i])
		if (ws.str[ws.i] == '%')
		{
			ws.j = ws.i;
			ws.str = get_wildcard(ws.str, &ws.i, &ws.ap);
			if (ws.str[ws.i] == '%')
				ws.str = get_percent(ws.str, ws.format, &ws.i, &ws.j);
			else if (is_format(ws.str[ws.i]))
				convert_format(&ws);
			else
				ws.j++;
			ws.i = ws.j;
		}
		else
			ws.i++;
	end_ft_printf(&ws);
	va_end(ws.ap);
	return (ws.i);
}
