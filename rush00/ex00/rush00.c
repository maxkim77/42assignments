/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:02:13 by jeongkim          #+#    #+#             */
/*   Updated: 2025/01/26 14:02:15 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	x_col;
	int	y_row;

	if (x <= 0 || y <= 0)
		return ;
	y_row = 1;
	while (y_row <= y)
	{
		x_col = 1;
		while (x_col <= x)
		{
			if ((y_row == 1 || y_row == y) && (x_col == 1 || x_col == x))
				ft_putchar('o');
			else if (y_row == 1 || y_row == y)
				ft_putchar('-');
			else if (x_col == 1 || x_col == x)
				ft_putchar('|');
			else
				ft_putchar(' ');
			x_col++;
		}
		ft_putchar('\n');
		y_row++;
	}
}
