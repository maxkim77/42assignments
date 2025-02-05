/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 22:22:09 by jeongkim          #+#    #+#             */
/*   Updated: 2025/02/11 22:49:58 by jeongkim         ###   ########.fr       */
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

int	ft_is_valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-'
			|| base[i] <= 32 || base[i] > 126)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_get_digit_from_base(char c, char *base)
{
	int	base_num;

	base_num = 0;
	while (base[base_num])
	{
		if (base[base_num] == c)
			return (base_num);
		base_num++;
	}
	return (-1);
}

int	ft_skip_whitespace(char *str, int *i)
{
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	return (*i);
}

int	ft_check_sign(char *str, int *i)
{
	int	neg;

	neg = 1;
	while (str[*i] == '-' || str[*i] == '+')
	{
		if (str[(*i)++] == '-')
			neg *= -1;
	}
	return (neg);
}
