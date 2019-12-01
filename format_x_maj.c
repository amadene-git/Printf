/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x_maj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 15:27:47 by admadene          #+#    #+#             */
/*   Updated: 2019/12/01 15:27:58 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*format_x_maj(unsigned int nb)
{
	char	*ret;

	if (!(ret = ft_utoxa_maj(nb)))
		return (NULL);
	return (ret);
}
