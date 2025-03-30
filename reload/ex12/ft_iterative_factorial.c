/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:00:06 by jeongkim          #+#    #+#             */
/*   Updated: 2025/03/30 16:00:08 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	r;

	r = nb;
	if (r < 0 || r > 15)
		return (0);
	else if (r == 0 || r == 1)
		return (1);
	else
	{
		while (r > 1)
		{
			r--;
			nb *= r;
		}
	}
	return (nb);
}
