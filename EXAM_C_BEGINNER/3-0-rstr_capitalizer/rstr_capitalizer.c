/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 11:05:56 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/02 15:16:49 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rstr_capitalizer(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		++i;
	}
	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') && (str[i + 1] == ' ' ||\
					str[i] == '\t' || !str[i + 1] || str[i + 1] == '\n' || \
					str[i + 1] == '\v' || str[i + 1] == '\r'\
					|| str[i + 1] == '\f'))
		{
			str[i] -= 32;
			write(1, &str[i], 1);
		}
		else
			write(1, &str[i], 1);
		++i;
	}
}

int		main(int ac, char **av)
{
	int i;

	i = 1;
	if (ac > 1)
	{
		av++;
		while (*av)
		{
			rstr_capitalizer(*av);
			write(1, "\n", 1);
			av++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
