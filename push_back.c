/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:03:00 by shebaz            #+#    #+#             */
/*   Updated: 2024/04/28 17:08:05 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	calculate_min_element(t_stack *stackA, t_stack *stackB, int long min_count)
{
	t_stack	*courant;
	int		*count;
	int		i;
	int		min_element;

	i = 0;
	min_element = INT_MAX;
	courant = stackB;
	count = malloc(ft_lstsize(stackB) * sizeof(int));
	if (!count)
		return (0);
	while (i < ft_lstsize(stackB) && courant != NULL)
	{
		count[i] = calcule_mouvement_stackb(stackB, stackA, courant->data);
		if (count[i] < min_count)
		{
			min_count = count[i];
			min_element = courant->data;
		}
		courant = courant->next;
		i++;
	}
	free(count);
	return (min_element);
}

void	execute_print_move(t_stack **stackA, t_stack **stackB, char *str)
{
	if (!ft_strcmp(str, "ra\n"))
		ra(stackA);
	else if (!ft_strcmp(str, "rb\n"))
		rb(stackB);
	else if (!ft_strcmp(str, "sa\n"))
		sa(*stackA);
	else if (!ft_strcmp(str, "sb\n"))
		sb(*stackB);
	else if (!ft_strcmp(str, "rra\n"))
		rra(stackA);
	else if (!ft_strcmp(str, "rrb\n"))
		rrb(stackB);
	else if (!ft_strcmp(str, "rr\n"))
		rr(stackA, stackB);
	else if (!ft_strcmp(str, "rrr\n"))
		rrr(stackA, stackB);
	else if (!ft_strcmp(str, "pa\n"))
		pa(stackA, stackB);
	else if (!ft_strcmp(str, "pb\n"))
		pb(stackA, stackB);
	ft_putstring(str);
}

void	push_min_to_stacka(int ele, t_stack **stackA, t_stack **stackB)
{
	while (pos(*stackB, ele) != 0)
	{
		if (pos(*stackB, ele) <= ft_lstsize(*stackB) / 2)
		{
			if (find_closest_pos(*stackA, ele) <= ft_lstsize(*stackA) / 2)
			{
				while (find_closest_pos(*stackA, ele) != 0
					&& pos(*stackB, ele) != 0)
					execute_print_move(stackA, stackB, "rr\n");
			}
			if (pos(*stackB, ele) != 0)
				execute_print_move(stackA, stackB, "rb\n");
		}
		else
		{
			if (find_closest_pos(*stackA, ele) > ft_lstsize(*stackA) / 2)
			{
				while (find_closest_pos(*stackA, ele) != 0
					&& pos(*stackB, ele) != 0)
					execute_print_move(stackA, stackB, "rrr\n");
			}
			if (pos(*stackB, ele) != 0)
				execute_print_move(stackA, stackB, "rrb\n");
		}
	}
}

void	push_back_to_stacka(t_stack **stackA, t_stack **stackB)
{
	int	min_element;
	int	close_pos;

	while (*stackB != NULL)
	{
		if (ft_lstsize(*stackA) == 0)
		{
			pa(stackA, stackB);
			ft_printf("pa\n");
		}
		else
		{
			min_element = calculate_min_element(*stackA, *stackB, INT_MAX);
			push_min_to_stacka(min_element, stackA, stackB);
			close_pos = find_closest_pos(*stackA, min_element);
			sort_stacka_before(stackA, close_pos, min_element);
			execute_print_move(stackA, stackB, "pa\n");
		}
	}
}
