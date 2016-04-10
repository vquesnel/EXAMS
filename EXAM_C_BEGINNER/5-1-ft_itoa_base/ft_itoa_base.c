/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 22:45:23 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/10 16:19:05 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "stdio.h"

int		int_len(int nb, int base)
{
	int i;

	i = 0;
	if (nb < 0 && base == 10)
	{
		++i;
		nb = -nb;
	}
	if (nb < 0 && base != 10)
		nb =-nb;
	while (nb)
	{
		nb /= base;
		++i;
	}
	return (i);
}

long	max_power(long nb, int base)
{
	long max;

	max = base;
	while (max < nb)
		max *= base;
	if (max > nb)
		max /= base;
	return (max);
}

char	*ft_itoa_base(int value, int base)
{
	long	nb;
	long	max;
	char	hex[16] = "0123456789ABCDEF";
	char	*text;
	int		i;
	int		j;

	if ((text = (char *)malloc(sizeof(char) * int_len(value, base) + 1)) == NULL)
		return (NULL);
	nb = (long)value;
	i = 0;
	j = 0;
	if (nb < 0 && base == 10)
	{
		text[i]= '-';
		i++;
		nb = -nb;
	}
	if (nb < 0 && base != 10)
	{
		nb = -nb;
	}
	max = max_power(nb, base);
	while (max > 0)
	{
		j = nb / max;
		text[i] = hex[j];
		nb %= max;
		max /= base;
		i++;
	}
	text[i] = '\0';
	return (text);
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
