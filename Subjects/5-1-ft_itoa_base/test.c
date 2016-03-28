/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 18:17:39 by vquesnel          #+#    #+#             */
/*   Updated: 2016/03/22 15:26:08 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void			ft_itoa_base(int nb, int base)
{
	long n;

	n = (long)nb;
	if (n < 0 && base == 10)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n < 0 && base != 10)
		n = -n;
	if (n >= base)
			ft_itoa_base(n / base, base);
	if ((n % base) < 10)
		ft_putchar((n % base) + 48);
	else
		ft_putchar((n % base) - 10 + 65);
}


int main(int ac, char **av)
{
	if (ac == 3)
		ft_itoa_base(atoi(av[1]), atoi(av[2]));
	write(1, "\n", 1);
}

