/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 14:40:48 by admadene          #+#    #+#             */
/*   Updated: 2019/11/28 14:40:50 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//********************** LIBFT *************************

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_strlen(char const *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char const *s)
{
	char	*str;
	char	*strcpy;

	if (!(str = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	strcpy = str;
	while (*s)
		*strcpy++ = *s++;
	*strcpy = '\0';
	return (str);
}


void	ft_bzero(void *s, size_t n)
{
	unsigned char *str;

	str = (unsigned char*)s;
	while (n--)
		*str++ = 0;
}

void		*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;

	if(!(str = (char*)malloc(nmemb * size)))
		return (NULL);
	ft_bzero(str, nmemb * size);
	return (str);
}

void		ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

char	*ft_strrev(char *str)
{
	char	tmp;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
	return (str);
}

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

//************************ FORMAT C ***************************

int		ft_atoi_flag_c(char *str)
{
	int i;
	int ret;
	int signe;

	i = 0;
	ret = 0;
	signe = (*str == '-') ? -1 : 1;
	while (str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		ret = (ret * 10) + ((str[i] - '0') * signe);
		i++;
	}
	return (ret);
}

char	*format_c(int c)
{
	char	*str;

	if (!(str = (char*)malloc(sizeof(char) * 2)))
		return (NULL);
	str[0] = c;
	str[1] = 0;
	return (str);
}

char	*flag_c(char *format, char *flag)
{
	int		i;
	int		width;
	char	*ret;

	i = 0;
	width = ABS(ft_atoi_flag_c(flag));
	if (!(ret = (char*)ft_calloc(sizeof(char), width + 2)))
		return (NULL);
	while (width > 1)
	{
		ret[i++] = ' ';
		width--;
	}
	ret[i++] = *format;
	ret[i] = 0;
	ret = (ft_atoi_flag_c(flag) < 0) ? ft_strrev(ret) : ret;
	free(format);
	free(flag);
	return (ret);
}

//********************** FLAG S ***********************

char	*format_s(char *str)
{
	char *ret;

	if (!str)
		return (ft_strdup("(null)"));
	if(!(ret = ft_strdup(str)))
		return (NULL);
	return (ret);
}


char	*flag_s(char *format, char *flag)
{
	int		width;
	int		precision;
	char	*ret;
	int		i;
	int 	j;
	int		len;

	i = 0;
	width = ft_atoi_flag_c(flag);
	while (flag[i] != '.' && flag[i])
		i++;
	if (flag[i] == '.')
		precision = ft_atoi_flag_c(flag + i + 1);
	else
		precision = - 1;
	len = (precision < 0) ? ft_strlen(format) : precision; 
	if (!(ret = (char*)ft_calloc(sizeof(char), ft_strlen(format) + (ABS(precision)) + (ABS(width)))))
		return (NULL);
	i = 0;
	j = 0;
	if (width > 0)
	{
		while (width > len)
		{
			ret[i] = ' ';
			i++;
			width--;
		}
		while (len && format[j])
		{
			ret[i] = format[j];
			i++;
			j++;
			len--;
		}
		ret[i] = 0;
	}
	else if (width < 0)
	{
		while (len && format[j])
		{
			ret[i] = format[j];
			i++;
			j++;
			len--;
			width++;
		}
		while (width < 0)
		{
			ret[i] = ' ';
			i++;
			width++;
		}
		ret[i] = 0;
	}
	else
		while (len && format[j])
		{
			ret[i] = format[j];
			i++;
			j++;
			len--;
		}
	free(format);
	free(flag);
	return (ret);
}

//********************** FORMAT D **********************

char	*format_d(int nb)
{
	char	*ret;

	if (!(ret = ft_itoa(nb)))
		return (NULL);
	return (ret);
}

char	*flag_d(char *format, char *flag)
{
	int		width;
	int		precision;
	char	*ret;
	int		zero;
	int		i;
	int		j;

	zero = 0;
	if (flag[0] == '0')
		zero = 1;
	width = ft_atoi_flag_c(flag + zero);
	while (flag[i] && flag[i] != '.')
		i++;
	if (flag[i] == '.')
	{
		precision = ft_atoi_flag_c(flag + i + zero + 1);
		zero = 0;
	}
	else
		precision = -1;
	i = 0;
	j = 0;
	while (width > 0)
	{
		if ()
		width--;
	}
}

//********************** FCT INIT *********************

t_fonction	*fonction_format_init(void)
{
	t_fonction	*fonct;

	fonct = (t_fonction*)malloc(sizeof(t_fonction) * 26);
	
	(fonct + 'c' - 'a')->f = &format_c;
	(fonct + 's' - 'a')->f = &format_s;

	(fonct + 'c' - 'a')->flag = &flag_c;
	(fonct + 's' - 'a')->flag = &flag_s;
	return (fonct);
}


//*********************** FT_PRINTF *************************

char	*insert_string(char *str, char *to_insert, int start, int end)
{
	char	*ret;
	int		i;

	if (!(ret = (char*)ft_calloc(sizeof(char), (ft_strlen(str) \
	+ ft_strlen(to_insert) + (end - start) + 1))))
		return (NULL);
	i = -1;
	while (++i < start)
		ret[i] = str[i];
	while (i < start + ft_strlen(to_insert))
	{
		ret[i] = to_insert[i - start];
		i++;
	}
	while (str[i - ft_strlen(to_insert) + (end - start)])
	{
		ret[i] = str[i - ft_strlen(to_insert) + (end - start)];
		i++;
	}
	ret[i] = 0;
	free(str);
	free(to_insert);
	return (ret);
}

char	*read_flag(char *str)
{
	int		i;
	char	*ret;

	i = 0;
	while (!ft_isalpha(str[i]))
		i++;
	if (!(ret = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while(!ft_isalpha(str[i]))
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

int ft_printf(char const *fmt, ...)
{
	int			i;
	int			j;
	char		*str;
	char		*format;
	t_fonction	*fonct;
	va_list		ap;

	fonct = fonction_format_init();
	va_start(ap, fmt);
	str = ft_strdup(fmt);
	i = 0;
	while (str[i])
	{
		if (str[i++] == '%')
		{
			j = i;
			while (str[i] && !ft_isalpha(str[i]))
				i++;
			format = (fonct + str[i] - 'a')->f(va_arg(ap, void*));
			format = (fonct + str[i] - 'a')->flag(format, read_flag(str + j));
			str = insert_string(str, format, j - 1, i + 1);
			i = j;
		}
	}
	ft_putstr(str);
	free(str);
	free(fonct);
	va_end(ap);
	return (0);
}

int main()
{
	ft_printf("|%s|\n","salut");
}
