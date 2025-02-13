/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:34:01 by jeongkim          #+#    #+#             */
/*   Updated: 2025/02/05 20:48:06 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_number(int num)
{
	char	ten;
	char	one;

	ten = '0' + (num / 10);
	one = '0' + (num % 10);
	ft_putchar(ten);
	ft_putchar(one);
}

void	ft_print_comb2(void)
{
	int	first2;
	int	second2;

	first2 = 0;
	while (first2 <= 98)
	{
		second2 = first2 + 1;
		while (second2 <= 99)
		{
			ft_print_number(first2);
			ft_putchar(' ');
			ft_print_number(second2);
			if (first2 != 98)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			second2++;
		}
		first2++;
	}
}
