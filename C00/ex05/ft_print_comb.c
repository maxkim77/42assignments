/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:12:05 by jeongkim          #+#    #+#             */
/*   Updated: 2025/02/05 20:21:29 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putcomb(char hun, char ten, char one)
{
	ft_putchar(hun);
	ft_putchar(ten);
	ft_putchar(one);
}

void	ft_print_comb(void)
{
	char	hun;
	char	ten;
	char	one;

	hun = '0';
	while (hun <= '7')
	{
		ten = hun + 1;
		while (ten <= '8')
		{
			one = ten + 1;
			while (one <= '9')
			{
				ft_putcomb(hun, ten, one);
				if (!(hun == '7' && ten == '8' && one == '9'))
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
				one++;
			}
			ten++;
		}
		hun++;
	}
}
