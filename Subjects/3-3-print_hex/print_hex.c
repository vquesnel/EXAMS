/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 11:14:33 by vquesnel          #+#    #+#             */
/*   Updated: 2016/03/09 18:02:35 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_atoi(char *str)
{
	int		res;
	int		i;

	res = 0;
	i = 0;
	if (str[i] == '-')
	{
		write(1, "-", 1);
		i++;
	}
	while (str[i])
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res);
}

int		power(int nb)
{
	int		power;

	power = 16;
	while (power < nb)
		power = power * 16;
	if (power > nb)
		power = power / 16;
	return (power);
}

void	print_hex(int nb)
{
	int		pwr;
	int		index;
	int		rest;
	char	hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

	pwr = power(nb);
	while (pwr > 0)
	{
		index = nb / pwr;
		rest = nb % pwr;
		write(1, &hex[index], 1);
		pwr = pwr / 16;
		nb = rest;
	}
}

int		main(int ac, char **av)
{
	int		n;

	if (ac == 2)
	{
		n = ft_atoi(av[1]);
		if (n == 0)
		{
			write(1, "0\n", 2);
			return (0);
		}
		print_hex(n);
	}
	write(1, "\n", 1);
	return(0);
}
