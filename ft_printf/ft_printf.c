/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:29:49 by heechoi           #+#    #+#             */
/*   Updated: 2023/12/12 12:41:42 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int	ft_err(va_list ap)
{
	va_end(ap);
	return (-1);
}

int	ft_format(const char format, va_list ap)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_print_char((char)va_arg(ap, int));
	else if (format == 's')
		len += ft_print_str(va_arg(ap, char *));
	else if (format == 'p')
		len += ft_print_ptr(va_arg(ap, void *));
	else if (format == 'd' || format == 'i')
		len += ft_print_nbr(va_arg(ap, int));
	else if (format == 'u')
		len += ft_print_unsigned_nbr(va_arg(ap, unsigned int));
	else if (format == 'x' || format == 'X')
		len += ft_print_hex(va_arg(ap, unsigned int), format);
	else if (format == '%')
		len += ft_print_char(format);
	return (len);
}

int	ft_printf(const char *input, ...)
{
	va_list	ap;
	int		input_len;
	int		tmp;

	va_start(ap, input);
	input_len = 0;
	while (*input)
	{
		if (*input == '%' && *(input++ + 1) != '\0')
		{
			tmp = ft_format(*(input++), ap);
			if (tmp == -1)
				return (ft_err(ap));
		}
		else
		{
			tmp = ft_print_char(*(input++));
			if (tmp == -1)
				return (ft_err(ap));
		}
		input_len += tmp;
	}
	va_end(ap);
	return (input_len);
}
