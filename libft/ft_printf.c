/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micabrer <micabrer@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:21:29 by micabrer          #+#    #+#             */
/*   Updated: 2024/01/10 18:13:19 by micabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_process_format(char format_type, va_list *args, int *len, int *i)
{
	if (format_type == 's')
		ft_putstr_len(va_arg(*args, char *), len);
	else if (format_type == 'd' || format_type == 'i')
		ft_print_int(va_arg(*args, int), len);
	else if (format_type == 'u')
		ft_print_uint(va_arg(*args, unsigned int), len);
	else if (format_type == 'x')
		ft_print_hex(va_arg(*args, unsigned int), len, 'x');
	else if (format_type == 'X')
		ft_print_hex(va_arg(*args, unsigned int), len, 'X');
	else if (format_type == 'p')
		ft_print_addr(va_arg(*args, size_t), len);
	else if (format_type == 'c')
		ft_putchar_len(va_arg(*args, int), len);
	else if (format_type == '%')
		ft_putchar_len('%', len);
	else
		(*i)--;
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		length;
	va_list	args;

	i = 0;
	length = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			ft_process_format(str[i], &args, &length, &i);
			i++;
		}
		else
		{
			ft_putchar_len((char)str[i], &length);
			i++;
		}
	}
	va_end(args);
	return (length);
}
