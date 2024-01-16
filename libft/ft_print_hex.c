/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micabrer <micabrer@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:25:27 by micabrer          #+#    #+#             */
/*   Updated: 2024/01/10 18:13:08 by micabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_hex(unsigned int decimal, int *length, char hex_case)
{
	int		i;
	char	hex_digits[25];
	char	*base_character;

	if (hex_case == 'X')
		base_character = "0123456789ABCDEF";
	else
		base_character = "0123456789abcdef";
	i = 0;
	if (decimal == 0)
	{
		ft_putchar_len('0', length);
		return ;
	}
	while (decimal != 0)
	{
		hex_digits[i] = base_character[decimal % 16];
		decimal = decimal / 16;
		i++;
	}
	while (i--)
		ft_putchar_len(hex_digits[i], length);
}
