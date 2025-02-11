/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:45:11 by jeongkim          #+#    #+#             */
/*   Updated: 2025/02/09 10:51:51 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define LINE_SIZE 16

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_mem_addr(unsigned long num)
{
	char	buffer[16];
	char	*hex_digits;
	int		i;

	hex_digits = "0123456789abcdef";
	i = 0;
	while (num > 0 || i < LINE_SIZE)
	{
		buffer[i] = hex_digits[num % 16];
		num /= 16;
		i++;
	}
	while (i < 16)
	{
		buffer[i] = '0';
		i++;
	}
	while (i > 0)
		write(1, &buffer[--i], 1);
}

void	ft_mem_bytes(unsigned char *mem, unsigned int remain)
{
	unsigned int	i;
	char			*hex_digits;

	hex_digits = "0123456789abcdef";
	i = 0;
	while (i < LINE_SIZE)
	{
		if (i < remain)
		{
			write(1, &hex_digits[mem[i] / 16], 1);
			write(1, &hex_digits[mem[i] % 16], 1);
		}
		else
			write(1, "  ", 2);
		if (i % 2)
			write(1, " ", 1);
		i++;
	}
}

void	ft_mem_chars(unsigned char *mem, unsigned int remain)
{
	unsigned int	i;
	char			c;

	i = 0;
	while (i < LINE_SIZE)
	{
		if (i < remain)
		{
			if (mem[i] >= 32 && mem[i] <= 126)
				c = mem[i];
			else
				c = '.';
			write(1, &c, 1);
		}
		else
			write(1, " ", 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	*mem_blk;
	unsigned int	remain_size;

	mem_blk = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		remain_size = size - i;
		if (remain_size > LINE_SIZE)
			remain_size = LINE_SIZE;
		ft_mem_addr((unsigned long)&mem_blk[i]);
		ft_putstr(": ");
		ft_mem_bytes(&mem_blk[i], remain_size);
		write(1, " ", 1);
		ft_mem_chars(&mem_blk[i], remain_size);
		write(1, "\n", 1);
		i += LINE_SIZE;
	}
	return (addr);
}
