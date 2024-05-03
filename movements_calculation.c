/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_calculation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:02:52 by shebaz            #+#    #+#             */
/*   Updated: 2024/04/28 10:30:59 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*copied_stack(t_stack *stack)
{
	t_stack	*copy;
	t_stack	*current;
	t_stack	*tail;
	t_stack	*node;

	copy = NULL;
	current = stack;
	tail = NULL;
	while (current)
	{
		node = malloc(sizeof(t_stack));
		if (!node)
			return (NULL);
		node->data = current->data;
		node->index = current->index;
		node->next = NULL;
		if (!copy)
			copy = node;
		else
			tail->next = node;
		tail = node;
		current = current->next;
	}
	return (copy);
}

int	find_closest_pos(t_stack *stackA, int element)//done
{
	t_stack	*courant;
	int		min_diff;
	int		close_pos;
	int		min;

	min_diff = INT_MAX;
	close_pos = -1;
	courant = stackA;
	while (courant)
	{
		if (courant->data > element && courant->data < min_diff)
		{
			min_diff = courant->data;
			close_pos = pos(stackA, min_diff);
		}
		courant = courant->next;
	}
	if (close_pos == -1)
	{
		min = min_element(stackA);
		close_pos = pos(stackA, min);
	}
	return (close_pos);
}

int	cal_mouvement_stacka(t_stack *stackA, int element, int k, int *move)
{
	t_stack	*copy_a;

	copy_a = copied_stack(stackA);
	if (k <= ft_lstsize(copy_a) / 2)
	{
		while (k != 0)
		{
			ra(&copy_a);
			(*move)++;
			k--;
		}
	}
	else if (k > ft_lstsize(copy_a) / 2)
	{
		while (k != 0)
		{
			rra(&copy_a);
			(*move)++;
			k = find_closest_pos(copy_a, element);
		}
	}
	clean_stack(copy_a);
	return (*move);
}

int	calcule_mouvement_stackb(t_stack *stackB, t_stack *stackA, int element)
{
	int		movements;
	int		position;
	t_stack	*copy_a;
	t_stack	*copy_b;

	movements = 0;
	copy_a = copied_stack(stackA);
	copy_b = copied_stack(stackB);
	while (pos(copy_b, element) != 0)
	{
		if (pos(stackB, element) == 1)
			sb(copy_b);
		else if (pos(copy_b, element) <= ft_lstsize(copy_b) / 2)
			rb(&copy_b);
		else
			rrb(&copy_b);
		movements++;
	}
	position = find_closest_pos(stackA, element);
	movements += cal_mouvement_stacka(copy_a, element, position, &movements);
	pa(&copy_a, &copy_b);
	clean_stack(copy_a);
	clean_stack(copy_b);
	return (movements + 1);
}

void	sort_stacka_before(t_stack **stackA, int pos, int element)//done
{
	while (pos != 0)
	{
		if (pos <= ft_lstsize(*stackA) / 2)
		{
			ra(stackA);
			ft_printf("ra\n");
		}
		else if (pos > ft_lstsize(*stackA) / 2)
		{
			rra(stackA);
			ft_printf("rra\n");
		}
		pos = find_closest_pos(*stackA, element);
	}
}
