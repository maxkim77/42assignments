/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 22:56:36 by jeongkim          #+#    #+#             */
/*   Updated: 2025/02/11 16:48:27 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_total_length(int size, char **strs, char *sep)
{
	int	total;
	int	i;

	total = 0;
	i = 0;
	while (i < size)
	{
		total += ft_strlen(strs[i]);
		if (i < size - 1)
			total += ft_strlen(sep);
		i++;
	}
	return (total);
}

void	ft_copy_strs(char *result, char **strs, char *sep, int size)
{
	int	i;
	int	j;
	int	k;
	int	index;

	i = 0;
	index = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			result[index++] = strs[i][j++];
		if (i < size - 1)
		{
			k = 0;
			while (sep[k])
				result[index++] = sep[k++];
		}
		i++;
	}
	result[index] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total_length;
	char	*result;

	if (size == 0)
	{
		result = malloc(1);
		if (!result)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	total_length = ft_total_length(size, strs, sep);
	result = (char *)malloc(sizeof(char) * (total_length + 1));
	if (!result)
		return (NULL);
	ft_copy_strs(result, strs, sep, size);
	return (result);
}
