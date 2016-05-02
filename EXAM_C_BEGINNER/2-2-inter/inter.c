/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_inter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 19:52:23 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/02 15:13:14 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_first(char *str, char c, int pos)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			break ;
		i++;
	}
	if (i == pos)
		return (1);
	return (0);
}

int		is_instring(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (1);
}

void	inter(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (is_first(s1, s1[i], i) && is_instring(s2, s1[i]))
			write(1, &s1[i], 1);
		i++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 3)
		inter(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
