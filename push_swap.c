/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:03:12 by shebaz            #+#    #+#             */
/*   Updated: 2024/04/28 10:25:30 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_sorted(t_stack *s, int element)
{
	t_stack	*courant;
	t_stack	*courant1;

	courant = s;
	while (courant)
	{
		courant1 = courant -> next;
		while (courant1)
		{
			if (element == 1 && courant->data < courant1->data)
				return (0);
			else if (element == 0 && courant->data > courant1->data)
				return (0);
			courant1 = courant1->next;
		}
		courant = courant->next;
	}
	return (1);
}

void	insert_index(t_stack *copyA, t_stack *stackA)
{
	t_stack	*courant;
	t_stack	*courant_c;

	courant = stackA;
	while (courant)
	{
		courant_c = copyA;
		while (courant_c)
		{
			if (courant_c->data == courant->data)
				courant->index = courant_c->index;
			courant_c = courant_c->next;
		}
		courant = courant->next;
	}
	clean_stack(copyA);
}

void	sort_copya(t_stack **copyA)
{
	t_stack	*courant;
	t_stack	*courant1;
	int		tmp;

	courant = *copyA;
	while (courant)
	{
		courant1 = courant->next;
		while (courant1)
		{
			if (courant->data > courant1->data)
			{
				tmp = courant->data;
				courant->data = courant1->data;
				courant1->data = tmp;
			}
			courant1 = courant1->next;
		}
		courant = courant->next;
	}
}

void	index_stack(t_stack *stackA)
{
	t_stack	*copy_a;
	t_stack	*courant;
	int		i;

	copy_a = copied_stack(stackA);
	courant = copy_a;
	sort_copya(&copy_a);
	courant = copy_a;
	i = 0;
	while (courant)
	{
		courant->index = i;
		i++;
		courant = courant->next;
	}
	insert_index(copy_a, stackA);
}

void	push_half_to_stackb(t_stack **stackA, t_stack **stackB)
{
	int	i;
	int	max;
	int	half_size;

	i = 0;
	max = ft_lstsize(*stackA);
	half_size = ft_lstsize(*stackA) / 2;
	index_stack(*stackA);
	while (i < max)
	{
		if ((*stackA)->index < half_size)
			execute_print_move(stackA, stackB, "pb\n");
		else
			execute_print_move(stackA, stackB, "ra\n");
		i++;
	}
	push_to_stackb(stackA, stackB);
	push_back_to_stacka(stackA, stackB);
}
