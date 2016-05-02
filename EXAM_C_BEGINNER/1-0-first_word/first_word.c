/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 14:55:23 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/02 15:07:25 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	first_word(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' ||
				str[i] == '\v' || str[i] == '\n' || str[i] == '\f')
			++i;
		else
		{
			write(1, &str[i], 1);
			if (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\r'
					|| str[i + 1] == '\v' || str[i + 1] == '\n' ||
					str[i + 1] == '\f' || str[i + 1] == '\0')
				break ;
			++i;
		}
	}
}

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	first_word(av[1]);
	write(1, "\n", 1);
	return (0);
}
