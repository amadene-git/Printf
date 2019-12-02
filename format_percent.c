/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:15:09 by admadene          #+#    #+#             */
/*   Updated: 2019/12/02 15:15:23 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*format_percent(char *flag)
{
	int		i;
	int		zero;
	int		width;

	if (!(zero = 0) && flag[0] == '0')
		zero = 1;
	width = ft_atoi_flag_c(flag + 0);
	free(flag);
	i = 0;
	if (!(flag = (char*)ft_calloc(sizeof(char), (abs(width)) + 2)))
		return (NULL);
	while (width-- > 1)
		if (zero)
			flag[i++] = '0';
		else
			flag[i++] = ' ';
	flag[i++] = '%';
	width++;
	while (width++ < -1)
		flag[i++] = ' ';
	flag[i] = 0;
	return (flag);
}
