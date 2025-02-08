/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:21:50 by jeongkim          #+#    #+#             */
/*   Updated: 2025/02/09 17:55:45 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	asc;
	int	desc;

	if (length <= 1)
		return (1);
	asc = 1;
	desc = 1;
	i = 0;
	while (++i < length)
	{
		if (f(tab[i - 1], tab[i]) > 0)
			asc = 0;
		if (f(tab[i - 1], tab[i]) < 0)
			desc = 0;
	}
	return (asc || desc);
}
