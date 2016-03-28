#include <stdlib.h>
#include <stdio.h>

int             tab_len(int start, int end)
{
	int             len;

	len = 0;
	if (start < end)
	{
		while (start <= end)
		{
			len++;
			start++;
		}
	}
	else
	{
		while (start >= end)
		{
			len++;
			start--;
		}
	}
	return (len);
}

int             *ft_rrange(int start, int end)
{
	int             *tab;
	int             i;

	tab = (int *)malloc(sizeof(int) * tab_len(start, end));
	i = 0;
	if (end < start)
	{
		while (end <= start)
			tab[i++] = end++;
	}
	else
	{
		while (start <= end)
			tab[i++] = start++;
	}
	return (tab);
}
int main(int ac, char **av)
{
	int *tab;
	int i = 0;

	(void)ac;
	tab = ft_rrange(atoi(av[1]), atoi(av[2]));
	while (tab[i] >= atoi(av[1]))
	{
		printf("%i\n", tab[i]);
		i++;
	}
	return (0);
}
