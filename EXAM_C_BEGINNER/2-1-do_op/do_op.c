/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_do_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 17:34:00 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/02 15:12:19 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar('0' + nb);
}

int		main(int ac, char **av)
{
	int	res;

	res = 0;
	if (ac != 4)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (*av[2] == '*')
		res = atoi(av[1]) * atoi(av[3]);
	else if (*av[2] == '/')
		res = atoi(av[1]) / atoi(av[3]);
	else if (*av[2] == '%')
		res = atoi(av[1]) % atoi(av[3]);
	else if (*av[2] == '+')
		res = atoi(av[1]) + atoi(av[3]);
	else if (*av[2] == '-')
		res = atoi(av[1]) - atoi(av[3]);
	ft_putnbr(res);
	ft_putchar('\n');
	return (0);
}
