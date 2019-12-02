/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:04:30 by admadene          #+#    #+#             */
/*   Updated: 2019/12/02 17:04:43 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		malloc_len_unsigned_ll(unsigned long int nb)
{
	int	i;

	i = 0;
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_utoa(unsigned int nb)
{
	unsigned long int	my_nb;
	int					n;
	char				*str;

	if (nb == 0)
		return (ft_strdup("0"));
	my_nb = (unsigned long int)nb;
	if (!(str = (char*)malloc(sizeof(char)\
	* (malloc_len_unsigned_ll(my_nb) + 1))))
		return (NULL);
	n = 0;
	while (my_nb > 0)
	{
		str[n++] = (my_nb % 10) + '0';
		my_nb /= 10;
	}
	str[n] = '\0';
	return (ft_strrev(str));
}
