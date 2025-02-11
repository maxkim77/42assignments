/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 08:43:47 by jeongkim          #+#    #+#             */
/*   Updated: 2025/01/27 08:44:11 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	init_hex_digits(char *hex_digits)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i < 10)
			hex_digits[i] = '0' + i;
		else
			hex_digits[i] = 'a' + (i - 10);
		i++;
	}
	hex_digits[16] = '\0';
}

void	ft_putstr_non_printable(char *str)
{
	char	hex_digits[17];
	char	hex_print[4];
	int		i;

	init_hex_digits(hex_digits);
	i = 0;
	while (str[i])
	{
		if (str[i] >= 32 && str[i] <= 126)
			write(1, &str[i], 1);
		else
		{
			hex_print[0] = '\\';
			hex_print[1] = hex_digits[(unsigned char)str[i] / 16];
			hex_print[2] = hex_digits[(unsigned char)str[i] % 16];
			write(1, hex_print, 3);
		}
		i++;
	}
}
