/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micabrer <micabrer@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:53:21 by micabrer          #+#    #+#             */
/*   Updated: 2024/01/16 21:36:24 by micabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// Standard C Libraries

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>

// Protoypes

void	ft_putchar_len(char character, int *length);
void	ft_putstr_len(char *args, int *length);
void	ft_print_int(int number, int *length);
void	ft_print_addr(size_t pointer, int *length);
void	ft_print_uint(unsigned int unumber, int *length);
void	ft_print_hex(unsigned int decimal, int *length, char hex_case);
int		ft_printf(const char *str, ...);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);

#endif