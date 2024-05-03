/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:43:49 by shebaz            #+#    #+#             */
/*   Updated: 2024/04/29 17:26:19 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_bonus.h"

void	check_mov(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (ft_strcmp(str, "ra\n") == 0)
		ra(stack_a);
	else if (ft_strcmp(str, "rb\n") == 0)
		rb(stack_b);
	else if (ft_strcmp(str, "sa\n") == 0)
		sa(*stack_a);
	else if (ft_strcmp(str, "sb\n") == 0)
		sb(*stack_b);
	else if (ft_strcmp(str, "rra\n") == 0)
		rra(stack_a);
	else if (ft_strcmp(str, "rrb\n") == 0)
		rrb(stack_b);
	else if (ft_strcmp(str, "rr\n") == 0)
		rr(stack_a, stack_b);
	else if (ft_strcmp(str, "rrr\n") == 0)
		rrr(stack_a, stack_b);
	else if (ft_strcmp(str, "pa\n") == 0)
		pa(stack_a, stack_b);
	else if (ft_strcmp(str, "pb\n") == 0)
		pb(stack_a, stack_b);
	else
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	clean_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

int	check_type(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (j < ft_strlen(tab[i]))
		{
			if (tab[i][j] < 48 || tab[i][j] > 57)
			{
				if (tab[i][0] != '-' && tab[i][0] != '+')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
