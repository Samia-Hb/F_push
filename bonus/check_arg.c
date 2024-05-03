/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:49:20 by shebaz            #+#    #+#             */
/*   Updated: 2024/04/29 17:10:07 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_bonus.h"

int	check_duplicate(long *arr, int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < nbr_of_arguments(argc, argv) - 1)
	{
		if (arr[i] > INT_MAX || arr[i] < INT_MIN)
			return (0);
		j = i + 1;
		while (j < nbr_of_arguments(argc, argv))
		{
			if (arr[i] == arr[j] || arr[j] > INT_MAX || arr[j] < INT_MIN)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	while_boucle(char **argv, int *i, long **arr, int *j)
{
	int		k;
	char	**tab;

	if (ft_counter(argv[*i], ' ') == 0)
	{
		free(*arr);
		return (0);
	}
	tab = ft_split(argv[*i], ' ');
	if (!check_type(tab))
	{
		free(*arr);
		free_tab(tab);
		return (0);
	}
	k = 0;
	while (tab[k])
	{
		(*arr)[(*j)++] = ft_atoi(tab[k]);
		k++;
	}
	free_tab(tab);
	return (1);
}

long	*check_arguments(int argc, char **argv)
{
	int		i;
	int		j;
	long	*arr;

	i = 1;
	j = 0;
	arr = malloc(nbr_of_arguments(argc, argv) * sizeof(long));
	if (!arr)
		return (0);
	while (i < argc)
	{
		if (while_boucle(argv, &i, &arr, &j) == 0)
			return (0);
		i++;
	}
	return (arr);
}

int	check(char **argv)
{
	int		i;

	i = 1;
	while (argv[i])
	{
		if (ft_counter(argv[i], ' ') == 0 || ft_strlen(argv[i]) == 0)
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		i++;
	}
	return (1);
}

int	check_all(int argc, char **argv, long *arr)
{
	check(argv);
	if (nbr_of_arguments(argc, argv) == 1)
	{
		if (ft_atoi(argv[1]) > INT_MAX || ft_atoi(argv[1]) < INT_MIN
			|| !check_arguments(argc, argv))
			write(2, "Error\n", 6);
		return (0);
	}
	if (!arr)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (!arr || !check_duplicate(arr, argc, argv))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}
