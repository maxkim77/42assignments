/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 22:14:33 by jeongkim          #+#    #+#             */
/*   Updated: 2025/01/29 13:57:12 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	n;
	int	result;

	if (nb < 0 || nb > 12)
		return (0);
	n = 1;
	result = 1;
	while (n <= nb)
	{
		result = n * result;
		n++;
	}
	return (result);
}
