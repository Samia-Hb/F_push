/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:40:27 by shebaz            #+#    #+#             */
/*   Updated: 2024/04/29 18:05:15 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_bonus.h"

void	additional_case(char *str, int tmp, int i)
{
	if (str[i] != '\0' || (str[i] < '0' && str[i] > '9') || tmp > 1
		|| (tmp == 1 && ft_strlen(str) == 1))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	skip_plus_moins(char *str, int *i, int *tmp, int *signe)
{
	while (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			*signe = -1;
		(*i)++;
		(*tmp)++;
	}
}

long	ft_atoi(char *str)
{
	int		i;
	int		tmp;
	int		signe;
	long	result;

	i = 0;
	tmp = 0;
	signe = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	skip_plus_moins(str, &i, &tmp, &signe);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	additional_case(str, tmp, i);
	return (signe * result);
}
