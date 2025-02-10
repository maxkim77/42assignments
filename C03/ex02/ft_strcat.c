/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:22:37 by jeongkim          #+#    #+#             */
/*   Updated: 2025/01/27 16:43:09 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	dest_i;
	int	src_j;

	dest_i = 0;
	while (dest[dest_i] != '\0')
		dest_i++;
	src_j = 0;
	while (src[src_j] != '\0')
	{
		dest[dest_i + src_j] = src[src_j];
		src_j++;
	}
	dest[dest_i + src_j] = '\0';
	return (dest);
}
