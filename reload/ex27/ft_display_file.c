/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:58:16 by jeongkim          #+#    #+#             */
/*   Updated: 2025/03/30 16:58:18 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 4096

void	display_error(const char *message, int length)
{
	write(2, message, length);
}

int	open_file(char *filename)
{
	return (open(filename, O_RDONLY));
}

void	read_and_display(int fd)
{
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;

	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		write(1, buffer, bytes_read);
	}
}

int	main(int argc, char *argv[])
{
	int		fd;

	if (argc < 2)
		display_error("File name missing.\n", 19);
	else if (argc > 2)
		display_error("Too many arguments.\n", 20);
	else
	{
		fd = open_file(argv[1]);
		if (fd == -1)
			display_error("Cannot read file.\n", 18);
		else
		{
			read_and_display(fd);
			close(fd);
		}
	}
	return (0);
}
