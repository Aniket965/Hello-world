/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 09:51:58 by zfaria            #+#    #+#             */
/*   Updated: 2018/10/10 15:49:14 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c);

int		g_lines;
int		g_width;

void	print_line(int spaces)
{
	int	i;
	int	stars;

	stars = (g_width * 2 + 1) - spaces * 2;
	i = 0;
	while (i < spaces)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putchar('/');
	i = 0;
	while (i++ < stars)
		ft_putchar('*');
	ft_putchar('\\');
	ft_putchar('\n');
}

void	print_door_floor(int spaces, int door_size, int line)
{
	int	i;
	int	stars;

	stars = g_width - line - door_size / 2;
	i = 0;
	while (i++ < spaces)
		ft_putchar(' ');
	ft_putchar('/');
	i = 0;
	while (i++ < stars)
		ft_putchar('*');
	i = 0;
	while (i++ < door_size)
	{
		if (door_size >= 5 && i == door_size - 1 && line == door_size / 2)
			ft_putchar('$');
		else
			ft_putchar('|');
	}
	i = 0;
	while (i++ < stars)
		ft_putchar('*');
	ft_putchar('\\');
	ft_putchar('\n');
}

int		get_spaces(int floor, int floors, int line)
{
	int offset;

	offset = 0;
	while (floor < floors)
	{
		offset += (floor - 1) / 2 + 2;
		floor++;
	}
	return (g_lines - line + offset);
}

void	print_pyramid(int size, int door_size)
{
	int	i;
	int	j;
	int	spaces;
	int	lines;

	i = 1;
	j = 1;
	lines = 0;
	spaces = 0;
	while (i <= size)
	{
		lines += i + 2;
		while (j <= lines)
		{
			spaces = get_spaces(i, size, j);
			if (i == size && (lines - j < door_size))
				print_door_floor(spaces, door_size, lines - j);
			else
				print_line(spaces);
			j++;
		}
		i++;
	}
}

void	sastantua(int size)
{
	int	i;
	int	door_size;

	i = 0;
	while (i++ < size)
		g_lines += i + 2;
	g_width = get_spaces(1, size, 1);
	door_size = size % 2 == 1 ? size : size - 1;
	print_pyramid(size, door_size);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	argc++;
	sastantua(atoi(argv[1]));
	return (0);
}
