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

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_fonction
{
	char	*(*f)();
	char	*(*flag)(char*, char*);
}				t_fonction;

typedef	struct	s_printf
{
	int			i;
	int			j;
	int			len;
	char		*str;
	char		*format;
	t_fonction	*fonct;
	va_list		ap;

}				t_printf;

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_strlen(char const *str);
char			*ft_strdup(char const *s);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
void			ft_putstr(char *str);
char			*ft_strrev(char *str);
int				malloc_len(long int nb);
char			*ft_itoa(int nb);
int				malloc_len_unsigned_lhex(unsigned long int nb);
char			*ft_utoxa(unsigned int nb);
char			*ft_utoxa_maj(unsigned int nb);
int				malloc_len_unsigned_ll(unsigned long int nb);
char			*ft_utoa(unsigned int nb);
int				malloc_len_unsigned_lluh(unsigned long long int nb);
char			*ft_llutoxa(unsigned long long int nb);
int				abs(int nb);
int				ft_atoi_flag_c(char *str);
char			*format_c(int c);
char			*flag_c(char *format, char *flag);
char			*format_s(char *str);
char			*flag_s_positive(int width, int preci, char *format, char *ret);
char			*flag_s_negative(int width, int preci, char *format, char *ret);
char			*flag_s(char *format, char *flag);
char			*format_d(int nb);
char			*flag_d_positive(int width, int preci, char *format, char *ret);
char			*flag_d_negative(int width, int preci, char *format, char *ret);
char			*flag_d(char *format, char *flag);
char			*flag_d_after(int i, int precision, char *ret, char *format);
char			*put_minus(char *ret, char *flag);
void			set_width_and_precis(int zero, int *preci, int *width, int len);
void			set_flag(char *flag, int *precision, int *width, int *zero);
int				len_f(char *format, int precision);
char			*format_x(unsigned int nb);
char			*format_x_maj(unsigned int nb);
char			*format_u(unsigned int nb);
char			*format_p(void	*ptr);
char			*flag_p_null(char *format);
char			*flag_p_positive(int width, int preci, char *format, char *ret);
char			*flag_p_negative(int width, int preci, char *format, char *ret);
char			*flag_p(char *format, char *flag);
char			*format_percent(char *flag);
char			*insert_string(char *str, char *to_insert, int start, int end);
int				is_flag(char c);
int				is_format(char c);
char			*read_flag(char *str);
t_fonction		*fonction_format_init(void);
t_fonction		*fonction_flag_init(t_fonction *fonct);
char			*get_wildcard(char *str, int *i, va_list *ap);
char			*get_percent(char *str, char *format, int *i, int *j);
void			structure_init(t_printf *ws, char const *fmt);
void			convert_format(t_printf *ws);
void			print_format_c(t_printf *ws);
void			end_ft_printf(t_printf *ws);
int				ft_printf(const char *fmt, ...);

#endif
