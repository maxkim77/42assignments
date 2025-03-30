/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:32:12 by jeongkim          #+#    #+#             */
/*   Updated: 2025/03/30 16:32:14 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	range_size;
	int	i;

	if (min >= max)
		return (NULL);
	range_size = (max - min);
	range = malloc((range_size) * sizeof(int));
	i = 0;
	while (i < range_size)
	{
		range[i] = (min + i);
		i++;
	}
	return (range);
}
