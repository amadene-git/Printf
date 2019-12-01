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

//*********** LIBFT **************

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_strlen(char const *str);
char	*ft_strdup(char const *s);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_putstr(char *str);
char	*ft_strrev(char *str);
int		malloc_len(long int nb);
char	*ft_itoa(int nb);


//*********** FORMAT C *********

int		ft_atoi_flag_c(char *str);
char	*format_c(int c);
char	*flag_c(char *format, char *flag);

//********** FORMAT S ***************

char	*format_s(char *str);
char	*flag_s_positive(int width, int precision, char *format, char *ret);
char	*flag_s_negative(int width, int precision, char *format, char *ret);
char	*flag_s(char *format, char *flag);

//********** FORMAT D ***************

char	*format_d(int nb);
char	*flag_d_positive(int width, int precision, char *format, char *ret);
char	*flag_d_negative(int width, int precision, char *format, char *ret);
char	*flag_d(char *format, char *flag);
char	*flag_d_after(int i, int precision, char *ret, char *format);
char	*put_minus(char *ret);
void	set_width_and_precision(int zero, int *precision, int *width, int len);
void	set_flag(char *flag, int *precision, int *width, int *zero);

//********** FT_PRINTF *************

char	*insert_string(char *str, char *to_insert, int start, int end);
#endif
