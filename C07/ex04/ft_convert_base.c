/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 22:22:12 by jeongkim          #+#    #+#             */
/*   Updated: 2025/02/12 12:24:09 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);
int	ft_is_valid_base(char *base);
int	ft_get_digit_from_base(char c, char *base);
int	ft_skip_whitespace(char *str, int *i);
int	ft_check_sign(char *str, int *i);

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	res;
	int	neg;
	int	base_len;
	int	digit;

	base_len = ft_strlen(base);
	if (base_len < 2)
		return (0);
	i = 0;
	ft_skip_whitespace(str, &i);
	neg = ft_check_sign(str, &i);
	res = 0;
	while (str[i])
	{
		digit = ft_get_digit_from_base(str[i], base);
		if (digit == -1)
			break ;
		res = (res * base_len) + digit;
		i++;
	}
	return (res * neg);
}

int	ft_base_num_len(int nbr, char *base)
{
	int	len;
	int	base_num_len;

	base_num_len = ft_strlen(base);
	if (base_num_len < 2)
		return (0);
	len = 1;
	if (nbr < 0)
		len++;
	while (nbr / base_num_len)
	{
		len++;
		nbr /= base_num_len;
	}
	return (len);
}

void	ft_recursive_putnbr_base(int nbr, char *base, char *result, int *index)
{
	unsigned int	nbr_abs;
	unsigned int	base_len;

	base_len = ft_strlen(base);
	if (base_len < 2)
		return ;
	if (nbr < 0)
	{
		result[(*index)++] = '-';
		nbr_abs = (unsigned int)(-nbr);
	}
	else
		nbr_abs = (unsigned int)nbr;
	if (nbr_abs >= base_len)
		ft_recursive_putnbr_base(nbr_abs / base_len, base, result, index);
	result[(*index)++] = base[nbr_abs % base_len];
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		decimal;
	int		result_len;
	char	*result;
	int		index;

	if (!ft_is_valid_base(base_from) || !ft_is_valid_base(base_to))
		return (NULL);
	decimal = ft_atoi_base(nbr, base_from);
	result_len = ft_base_num_len(decimal, base_to) + 1;
	result = (char *)malloc(sizeof(char) * result_len);
	if (!result)
		return (NULL);
	index = 0;
	ft_recursive_putnbr_base(decimal, base_to, result, &index);
	result[index] = '\0';
	return (result);
}
