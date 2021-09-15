#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
	int compt;

	compt = 0;
	while (str[compt])
		compt++;
	return (compt);
}

void ft_print_tab(int *tab, int argc)
{
	int i;
	
	i = 0;
	while (i < argc -1)
	{
		printf("%d ", tab[i]);
		i++;
	}
}

int ft_atoi(char *str)
{
	int neg_pos;
	int result;
	int index;
	int compt;

	result = 0;
	index = ft_strlen(str) - 1;
	compt = 1;
	neg_pos = 1;
	if (str[0] == '-')
		neg_pos = -1;
	while (index >= 0)
	{
		if (index == 0 && neg_pos == -1)
			break ;
		if (str[index] >= '0' && str[index] <= '9')
			result += compt * (str[index] - '0');
		else
			return (1);
		index--;
		compt *= 10;
	}
	result *= neg_pos;
	return (result);
}

int main(int argc, char **argv)
{
	int *tab_a;
	int *tab_b;
	int i;
	int pivot;

	i = 1;
	tab_a = malloc(sizeof(int) * (argc -1));
	tab_b = malloc(sizeof(int) * (argc -1));
	while (i < argc)
	{
		tab_a[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	ft_print_tab(tab_a, argc);
	pivot = tab[0];
	while (tab_a)
}
