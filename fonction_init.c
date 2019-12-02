/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:13:34 by admadene          #+#    #+#             */
/*   Updated: 2019/12/02 15:13:47 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_fonction	*fonction_format_init(void)
{
	t_fonction	*fonct;

	if (!(fonct = (t_fonction*)malloc(sizeof(t_fonction) * 128)))
		return (NULL);
	(fonct + 'c')->f = &format_c;
	(fonct + 's')->f = &format_s;
	(fonct + 'd')->f = &format_d;
	(fonct + 'x')->f = &format_x;
	(fonct + 'X')->f = &format_x_maj;
	(fonct + 'i')->f = &format_d;
	(fonct + 'u')->f = &format_u;
	(fonct + 'p')->f = &format_p;
	return (fonct);
}

t_fonction	*fonction_flag_init(t_fonction *fonct)
{
	(fonct + 'c')->flag = &flag_c;
	(fonct + 's')->flag = &flag_s;
	(fonct + 'd')->flag = &flag_d;
	(fonct + 'x')->flag = &flag_d;
	(fonct + 'X')->flag = &flag_d;
	(fonct + 'i')->flag = &flag_d;
	(fonct + 'u')->flag = &flag_d;
	(fonct + 'p')->flag = &flag_p;
	return (fonct);
}
