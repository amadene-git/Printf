/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llutoxa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:05:54 by admadene          #+#    #+#             */
/*   Updated: 2019/12/02 17:06:09 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		malloc_len_unsigned_lluh(unsigned long long int nb)
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

char	*ft_llutoxa(unsigned long long int nb)
{
	int		i;
	char	*str;
	char	tab[17];

	i = -1;
	while (++i < 10)
		tab[i] = '0' + i;
	i = -1;
	while (++i < 6)
		tab[i + 10] = 'a' + i;
	if (!(i = 0) && nb == 0)
		return (ft_strdup("0"));
	if (!(str = (char*)malloc(sizeof(char)\
	* (malloc_len_unsigned_lluh(nb) + 1))))
		return (NULL);
	i = 0;
	while (nb > 0)
	{
		str[i++] = tab[nb % 16];
		nb /= 16;
	}
	str[i] = '\0';
	return (ft_strrev(str));
}
