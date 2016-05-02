/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 10:42:17 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/02 15:04:02 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	search(char *str, char c, char new)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			str[i] = new;
			write(1, &str[i], 1);
		}
		else
			write(1, &str[i], 1);
		++i;
	}
}

int		main(int ac, char **av)
{
	if (ac == 4)
		search(av[1], av[2][0], av[3][0]);
	write(1, "\n", 1);
	return (0);
}
