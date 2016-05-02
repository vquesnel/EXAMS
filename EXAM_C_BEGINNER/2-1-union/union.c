/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 17:51:25 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/02 15:11:25 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	srchchar(char c, char *str, int pos)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			break ;
		i++;
	}
	if (i == pos)
		write(1, &str[i], 1);
}

void	ft_union(char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	while (s1[i])
	{
		srchchar(s1[i], s1, i);
		i++;
	}
	i = 0;
	while (s2[i])
	{
		j = 0;
		while (s1[j])
		{
			if (s2[i] == s1[j])
				break ;
			j++;
		}
		if (!s1[j])
			srchchar(s2[i], s2, i);
		i++;
	}
}

int		main(int ac, char **av)
{
	if (ac != 3)
		return (0);
	ft_union(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
