/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:21:52 by jeongkim          #+#    #+#             */
/*   Updated: 2025/02/09 17:44:00 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (i < length)
	{
		if (f(tab[i]) == 1)
			n++;
		i++;
	}
	return (n);
}
