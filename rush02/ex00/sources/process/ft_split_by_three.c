/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_by_three.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:42:57 by jeongkim          #+#    #+#             */
/*   Updated: 2025/02/09 20:29:32 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int	ft_nbr_count_by_three(char *nb)
{
	int	len;

	len = ft_strlen(nb) / 3;
	if (ft_strlen(nb) % 3 != 0)
		len++;
	return (len);
}

char	**ft_split_nbr_by_three(char *nbr, int size)
{
	char	**trio_nbr;
	int		i;
	int		k;
	int		item_len;

	trio_nbr = malloc(sizeof(char *) * (size + 1));
	if (!trio_nbr)
		return (0);
	*trio_nbr = 0;
	item_len = ft_strlen(nbr) % 3;
	i = 0;
	k = 0;
	if (item_len == 0)
		item_len = 3;
	while (nbr[i])
	{
		trio_nbr[k++] = ft_add_word(nbr + i, item_len);
		i += item_len;
		if (item_len != 3)
			item_len = 3;
	}
	trio_nbr[size] = 0;
	return (trio_nbr);
}
