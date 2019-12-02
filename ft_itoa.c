/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:15:32 by admadene          #+#    #+#             */
/*   Updated: 2019/12/02 17:15:33 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		malloc_len(long int nb)
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

char	*ft_itoa(int nb)
{
	long int	my_nb;
	int			n;
	int			signe;
	char		*str;

	if (nb == 0)
		return (ft_strdup("0"));
	my_nb = (long int)nb;
	if (!(signe = 0) && my_nb < 0)
	{
		signe = 1;
		my_nb *= -1;
	}
	str = (char*)malloc(sizeof(char) * (malloc_len(my_nb) + 1 + signe));
	n = 0;
	while (my_nb > 0)
	{
		str[n++] = (my_nb % 10) + '0';
		my_nb /= 10;
	}
	if (signe)
		str[n++] = '-';
	str[n] = '\0';
	return (ft_strrev(str));
}
