/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 01:43:15 by jeongkim          #+#    #+#             */
/*   Updated: 2025/02/10 01:43:48 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	check(char *n1, char *n2, int ope, int *nb)
{
	nb[0] = ft_atoi(n1);
	nb[1] = ft_atoi(n2);
	if (nb[1] == 0 && (ope == 2 || ope == 4))
	{
		if (ope == 2)
			ft_putstr("Stop : division by zero");
		else
			ft_putstr("Stop : modulo by zero");
		return (0);
	}
	return (1);
}

void	do_op(char *n1, char *op, char *n2)
{
	int		(*tab[5])(int, int);
	int		ope;
	int		nb[2];

	tab[0] = add;
	tab[1] = sub;
	tab[2] = div;
	tab[3] = mul;
	tab[4] = mod;
	ope = parse_op(op);
	if (ope != -1)
	{
		if (check(n1, n2, ope, nb))
			ft_putnbr(tab[ope](nb[0], nb[1]));
		ft_putchar('\n');
	}
	else
	{
		ft_putnbr(0);
		ft_putchar('\n');
	}
}

int	parse_op(char *op)
{
	int		i;
	char	*list;

	list = "+-/*%";
	i = 0;
	while (list[i])
	{
		if (list[i] == op[0] && op[1] == '\0')
			return (i);
		i++;
	}
	return (-1);
}
