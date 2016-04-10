/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 16:26:11 by vquesnel          #+#    #+#             */
/*   Updated: 2016/03/08 17:03:02 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	last_word(char *str)
{
	int i;

	i = ft_strlen(str) - 1;
	while ((str[i] == ' ' || str[i] == '\t') && i >= 0)
		i--;
	while ((str[i] >= 33 && str[i] <= 126) && (str[i - 1] != ' ' || str[i - 1] != '\t'))
		i--;
	while (str[++i] >= 33 && str[i] <= 126)
			write(1, &str[i], 1);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	else
		last_word(av[1]);
	write(1, "\n", 1);
	return (0);
}
