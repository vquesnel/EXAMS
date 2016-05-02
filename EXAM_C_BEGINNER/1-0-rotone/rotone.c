/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 15:13:06 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/02 15:04:25 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rotone(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 97 && str[i] <= 121)
			str[i] = str[i] + 1;
		else if (str[i] == 122 || str[i] == 90)
			str[i] = str[i] - 25;
		else if (str[i] >= 65 && str[i] <= 89)
			str[i] = str[i] + 1;
		write(1, &str[i], 1);
		i++;
	}
}

int		main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac == 2)
		rotone(av[1]);
	write(1, "\n", 1);
	return (0);
}
