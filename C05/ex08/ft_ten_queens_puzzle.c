/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:44:07 by lquehec           #+#    #+#             */
/*   Updated: 2025/02/13 01:03:43 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	ft_is_valid(int *pos_queen, int new_q_row, int new_q_col)
{
	int	ex_q_col;

	ex_q_col = 0;
	while (ex_q_col < new_q_col)
	{
		if ((pos_queen[ex_q_col] == new_q_row)
			|| (pos_queen[ex_q_col] + ex_q_col == new_q_row + new_q_col)
			|| (pos_queen[ex_q_col] - ex_q_col == new_q_row - new_q_col))
			return (0);
		ex_q_col++;
	}
	return (1);
}

void	ft_print_queen(int *pos_queen, int q_ten)
{
	int	q_col;

	q_col = 0;
	while (q_col < q_ten)
	{
		ft_putchar(pos_queen[q_col] + '0');
		q_col++;
	}
	ft_putchar('\n');
}

void	ft_find_queen(int *pos_queen, int col, int q_ten, int *ans_cnt)
{
	int	row;

	row = 0;
	if (col == q_ten)
	{
		ft_print_queen(pos_queen, q_ten);
		*ans_cnt += 1;
	}
	else
	{
		while (row < q_ten)
		{
			if (ft_is_valid(pos_queen, row, col))
			{
				pos_queen[col] = row;
				ft_find_queen(pos_queen, col + 1, q_ten, ans_cnt);
			}
			row++;
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	q_col;
	int	ans_cnt;
	int	q_ten;
	int	pos_queen[10];

	q_ten = 10;
	q_col = -1;
	while (++q_col < q_ten)
		pos_queen[q_col] = 0;
	ans_cnt = 0;
	ft_find_queen(pos_queen, 0, q_ten, &ans_cnt);
	return (ans_cnt);
}

/*int	main(void)
{
	ft_ten_queens_puzzle();
	printf("OUTPUT: %d\n", ft_ten_queens_puzzle());
	return (0);
}*/
