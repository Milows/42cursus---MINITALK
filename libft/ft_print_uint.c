/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micabrer <micabrer@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:00:05 by micabrer          #+#    #+#             */
/*   Updated: 2024/01/10 18:13:15 by micabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_uint(unsigned int unumber, int *length)
{
	if (unumber >= 10)
		ft_print_uint(unumber / 10, length);
	ft_putchar_len(unumber % 10 + '0', length);
}
