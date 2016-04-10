/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 22:45:23 by vquesnel          #+#    #+#             */
/*   Updated: 2016/03/09 22:46:11 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		int_len(int n, int base)
{
	int		len;

	len = 0;
	if (n < 0 && base == 10)
	{
		n = -n;
		len++;
	}
	if (n < 0 && base != 10)
		n = -n;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int		max_power(int value, int base)
{
	int		power;

	power = base;
	if (value < 0)
		value = -value;
	while (power < value)
		power = power * base;
	if (power > value)
		power = power / base;
	return (power);
}

char	*ft_itoa_base(int value, int base)
{
	int		power;
	int		index1;
	int		index2;
	int		rest;
	int		len;
	char	hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
	char	*toa;

	if (base < 2 || base > 16)
		return (0);
	power = max_power(value, base);
	len = int_len(value, base);
	toa = malloc(len + 1);
	index2 = 0;
	if (value < 0 && base == 10)
	{
		toa[index2] = '-';
		value = -value;
		index2++;
	}
	if (value < 0 && base != 10)
		value = -value;
	while (power > 0)
	{
		index1 = value / power;
		rest = value % power;
		toa[index2] = hex[index1];
		power = power / base;
		value = rest;
		index2++;
	}
	toa[index2] = '\0';
	return (toa);
}

int		main(int ac, char **av)
{
	int		value;
	int		base;
	char	*toa;

	if (ac == 3)
	{
		value = atoi(av[1]);
		base = atoi(av[2]);
		toa = ft_itoa_base(value, base);
		printf("%s\n", toa);
	}
	return (0);
}

