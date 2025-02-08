/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:23:27 by jeongkim          #+#    #+#             */
/*   Updated: 2025/02/08 15:23:31 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		swapped;
	char	*tmp;

	if (!tab || !tab[0])
		return ;
	while (1)
	{
		swapped = 0;
		i = 0;
		while (tab[i + 1])
		{
			if (cmp(tab[i], tab[i + 1]) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				swapped = 1;
			}
			i++;
		}
		if (!swapped)
			break ;
	}
}
