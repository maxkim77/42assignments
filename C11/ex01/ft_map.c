/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:34:03 by jeongkim          #+#    #+#             */
/*   Updated: 2025/02/10 02:20:55 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*tab2;

	i = 0;
	tab2 = (int *)malloc(sizeof(int) * length);
	if (tab2 == NULL)
		return (0);
	while (i < length)
	{
		tab2[i] = f(tab[i]);
		i++;
	}
	return (tab2);
}
