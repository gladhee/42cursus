/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:29:52 by heechoi           #+#    #+#             */
/*   Updated: 2023/11/28 13:48:51 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int					ft_printf(const char *input, ...);
int					ft_format(const char format, va_list ap);
int					ft_print_nbr(int nbr);
int					ft_print_str(char *str);
int					ft_print_char(char c);
size_t				ft_nbr_len(unsigned int nbr);
char				*ft_uitoa(unsigned int nbr);
int					ft_print_unsigned_nbr(unsigned int nbr);
char				ft_convert_hex(int c, char format);
size_t				ft_hex_len(unsigned int nbr);
char				*ft_uitoxa(unsigned int nbr, char format);
int					ft_print_hex(unsigned int nbr, char format);
int					ft_print_ptr(void *ptr);
unsigned long long	ft_ptr_len(unsigned long long ptr);
char				*ft_ulltoxa(unsigned long long ptr);
int					ft_err(va_list ap);

#endif
