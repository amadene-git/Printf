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

//********************** FLAG S ***********************



//********************** FORMAT D **********************



//********************** FCT INIT *********************

t_fonction	*fonction_format_init(void)
{
	t_fonction	*fonct;

	fonct = (t_fonction*)malloc(sizeof(t_fonction) * 26);

	(fonct + 'c' - 'a')->f = &format_c;
	(fonct + 's' - 'a')->f = &format_s;
	(fonct + 'd' - 'a')->f = &format_d;

	(fonct + 'c' - 'a')->flag = &flag_c;
	(fonct + 's' - 'a')->flag = &flag_s;
	(fonct + 'd' - 'a')->flag = &flag_d;
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
	while (!ft_isalpha(str[i]))
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
		if (str[i] == '%')
		{
			j = i;
			while (str[++i] && !ft_isalpha(str[i]))
				if (str[i] == '*')
					str = insert_string(str, ft_itoa(va_arg(ap, int)), i, i + 1);
			format = (fonct + str[i] - 'a')->f(va_arg(ap, void*));
			format = (fonct + str[i] - 'a')->flag(format, read_flag(str + j + 1));
			str = insert_string(str, format, j, i + 1);
			i = j;
		}
		i++;
	}
	ft_putstr(str);
	free(str);
	free(fonct);
	va_end(ap);
	return (0);
}

int main()
{
	printf("\n///c///\n");
	ft_printf("ft: %c %5c %-4c|\n", 'a', '	', '7');
	printf("pf: %c %5c %-4c|\n", 'a', '	', '7');
	printf("\n");
	printf("///s///\n");
	ft_printf("ft: %.15s %100s %-8.35s %.*s|\n", "Coco", "Tristan", NULL, -15, "lol");
	printf("pf: %.15s %100s %-8.35s %.*s|\n", "Coco", "Tristan", NULL, -15, "lol");
	printf("\n");
	// printf("///p///\n");
	// ft = ft_printf("ft: %----24p et hello %2p %12.p %53p\n", ptr, ptr, NULL, ptr);
	// true = printf("pf: %----24p et hello %2p %12.p %53p\n", ptr, ptr, NULL, ptr);
	// printf("ft: %d\n", ft);
	// printf("pf: %d\n", true);
	// printf("\n");
	printf("///d///\n");
	ft_printf("ft: %01.*d %7d %-9d %05d %*d %0*d %03.*d|\n", 8, -18, 18, 18, 18, -8, 18, -8, 18, -15, 5);
	printf("pf: %01.*d %7d %-9d %05d %*d %0*d %03.*d|\n", 8, -18, 18, 18, 18, -8, 18, -8, 18, -15, 5);
	printf("\n");
}
