/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:45:05 by vquesnel          #+#    #+#             */
/*   Updated: 2016/03/11 17:48:51 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	*init_malloc(void)
{
	int i;
	char *ptr;

	i = 0;
	if ((ptr = (char *)malloc(sizeof(char) * 2050)) == NULL)
		return (NULL);
	while ( i < 2050)
	{
		ptr[i] = 0;
		++i;
	}
	return (ptr);
}

void	brainfuck(char *str)
{
	int i;
	char *ptr;
	int loop;

	i = 0;
	ptr = init_malloc();
	while (str[i])
	{
		if (str[i] == '>')
			ptr++;
		else if (str[i] == '<')
			ptr--;
		else if (str[i] == '+')
			(*ptr)++;
		else if (str[i] == '-')
			(*ptr)--;
		else if (str[i] == '.')
			write(1, ptr, 1);
		else if (str[i] == '[')
		{
			if (*ptr == 0)
			{
				loop = 0;
				while (str[i])
				{
					if (str[i] == '[')
						++loop;
					if (str[i] == ']')
						--loop;
					if (loop == 0)
						break ;
					++i;
				}
			}
		}
		else if (str[i] == ']')
		{
			if (*ptr != 0)
			{
				loop = 0;
				while (str[i])
				{
						if (str[i] == ']')
						++loop;
					if (str[i] == '[')
						--loop;
					if (loop == 0)
						break ;
					--i;
				}
			}
		}
		++i;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
		brainfuck(av[1]);
	else
		write(1, "\n", 1);
	return (0);
}
