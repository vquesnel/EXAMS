/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 21:50:39 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/18 15:55:59 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void		print_hex(unsigned char hex)
{
	char *tab = "0123456789abcdef";

		ft_putchar(tab[hex / 16]);
	ft_putchar(tab[hex % 16]);
}

static void		print_char(unsigned char hex)
{
	if (hex > 31 && hex < 127)
		ft_putchar(hex);
	else
		ft_putchar('.');
}

static void		make_hexs(unsigned char *line, size_t curline, size_t size)
{
	size_t	i;

	i = 0;
	while (i < 16)
	{
		if (i && i % 2 == 0)
			ft_putchar(' ');
		if (curline * 16 + i < size)
			print_hex(line[i]);
		else
		{
			ft_putchar(' ');
			ft_putchar(' ');
		}
		i++;
	}
}

void		print_memory(const void *addr, size_t size)
{
	size_t			curline;
	unsigned char	*tmp;
	size_t			i;

	curline = 0;
	i = 0;
	tmp = (unsigned char *)addr;
	while (curline * i < size)
	{
		make_hexs(tmp, curline, size);
		ft_putchar(' ');
		i = 0;
		while (i < 16)
		{
			if (curline * 16 + i < size)
				print_char(tmp[i]);
			i++;
		}
		ft_putchar('\n');
		tmp += 16;
		curline++;
	}
}

int	main(void)
{
	int	tab[10] = {0, 23, 150, 255,
		12, 16,  21, 42};

	print_memory(tab, sizeof(tab));
	return (0);
}
