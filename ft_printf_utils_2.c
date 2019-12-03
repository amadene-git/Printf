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

char	*delete_char_one(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] == 1)
			str = insert_string(str, ft_strdup(""), i, i + 1);
	return (str);
}

void	end_ft_printf(t_printf *ws)
{
	ws->i = ft_strlen(ws->str);
	ws->str = delete_char_one(ws->str);
	ft_putstr(ws->str);
	free(ws->str);
	free(ws->fonct);
}
