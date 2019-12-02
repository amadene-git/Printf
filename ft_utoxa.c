/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoxa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:41:37 by admadene          #+#    #+#             */
/*   Updated: 2019/12/02 16:41:50 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		malloc_len_unsigned_lhex(unsigned long int nb)
{
	int	i;

	i = 0;
	while (nb > 0)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

char	*ft_utoxa(unsigned int nb)
{
	unsigned long int	my_nb;
	int					n;
	char				*str;
	char				tab[17];

	n = -1;
	while (++n < 10)
		tab[n] = '0' + n;
	n = -1;
	while (++n < 6)
		tab[n + 10] = 'a' + n;
	if (!(n = 0) && nb == 0)
		return (ft_strdup("0"));
	my_nb = (unsigned long int)nb;
	if (!(str = (char*)malloc(sizeof(char)\
	* (malloc_len_unsigned_lhex(my_nb) + 1))))
		return (NULL);
	while (my_nb > 0)
	{
		str[n++] = tab[my_nb % 16];
		my_nb /= 16;
	}
	str[n] = '\0';
	return (ft_strrev(str));
}
