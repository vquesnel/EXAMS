/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 16:09:55 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/02 15:15:09 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	pgcd(int a, int b)
{
	int pgcd;

	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	if (a <= b)
	{
		pgcd = a;
		while (pgcd != 1)
		{
			if ((a % pgcd == 0) && (b % pgcd == 0))
			{
				printf("%d", pgcd);
				return (0);
			}
			pgcd--;
		}
	}
	else if (b < a)
	{
		pgcd = b;
		while (pgcd != 1)
		{
			if ((a % pgcd == 0) && (b % pgcd == 0))
			{
				printf("%d", pgcd);
				return (0);
			}
			pgcd--;
		}
	}
	printf("1");
	return (0);
}

int	main(int ac, char **av)
{
	if (ac == 3)
		pgcd(atoi(av[1]), atoi(av[2]));
	printf("\n");
	return (0);
}
