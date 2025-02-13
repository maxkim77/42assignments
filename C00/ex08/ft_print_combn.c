/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:33:24 by jeongkim          #+#    #+#             */
/*   Updated: 2025/02/05 22:59:32 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(int num[], int n)
{
	int		i;
	char	c;

	i = 0;
	while (i < n)
	{
		c = num[i] + '0';
		write(1, &c, 1);
		i++;
	}
	if (num[0] != 10 - n)
		write(1, ", ", 2);
}

void	recursive(int num[], int n, int i)
{
	if (i == 0)
		num[i] = 0;
	else
		num[i] = num[i - 1] + 1;
	while (num[i] < 11 - n + i)
	{
		if (i == n - 1)
			ft_print(num, n);
		else
			recursive(num, n, i + 1);
		num[i] = num[i] + 1;
	}
}

void	ft_print_combn(int n)
{
	int	num[10];

	recursive(num, n, 0);
}
