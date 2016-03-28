/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_last_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 14:31:25 by vquesnel          #+#    #+#             */
/*   Updated: 2016/03/08 14:39:01 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac == 1)
	{
		ft_putchar('\n');
		return (0);
	}
	else
		ft_putstr(av[ac - 1]);
	ft_putchar('\n');
	return (0);
}
