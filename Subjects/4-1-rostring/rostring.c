/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 11:43:10 by vquesnel          #+#    #+#             */
/*   Updated: 2016/03/21 12:18:41 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rostring(char *str)
{
	int i;
	int j;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\f' || str[i] == '\r' || str[i] == '\v')
		++i;
	j = i;
	while (str[i] >= 41 && str[i] <= 126)
		++i;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\f' || str[i] == '\r' || str[i] == '\v')
		++i;
		while (str[i] >= 41 && str[i] <= 126)
	{
		write(1, &str[i], 1);
			++i;
	}
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\f' || str[i] == '\r' || str[i] == '\v')
		++i;
	write(1 , " ", 1);
	}
	while (str[j] >= 41 && str[j] <= 126)
	{
		write(1, &str[j], 1);
		++j;
	}
}

int main(int ac, char **av)
{
	if (ac >= 2)
		rostring(av[1]);
	write(1, "\n", 1);
	return (0);
}
