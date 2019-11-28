/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 14:41:07 by admadene          #+#    #+#             */
/*   Updated: 2019/11/28 14:41:10 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define ABS(X) (X < 0) ? X * (-1) : X

#include <stdarg.h>
#include <libc.h>

typedef struct	s_fonction
{
	char	*(*f)();
	char	*(*flag)(char*, char*);
}				t_fonction;

#endif
