/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 07:55:49 by jeongkim          #+#    #+#             */
/*   Updated: 2025/01/28 07:55:51 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_negative(int index, char *str)
{
	int	sign_count;

	sign_count = 0;
	while (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			sign_count++;
		index++;
	}
	return (sign_count % 2);
}

int	ft_atoi(char *str)
{
	int	i;
	int	result;
	int	is_neg;

	i = 0;
	result = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v' || str[i] == '\f')
		i++;
	is_neg = is_negative(i, str);
	while (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (is_neg)
		return (-result);
	return (result);
}
