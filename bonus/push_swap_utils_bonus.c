/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:03:02 by shebaz            #+#    #+#             */
/*   Updated: 2024/04/23 22:21:01 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_bonus.h"

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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	push(t_stack **stackA, int data)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
	{
		write(1, "Allocation Failed\n", 18);
		return ;
	}
	node -> data = data;
	node -> next = *stackA;
	*stackA = node;
}

t_stack	*pop(t_stack **stack_s)
{
	t_stack	*tmp;
	t_stack	*courant;

	tmp = *stack_s;
	courant = (*stack_s)-> next;
	tmp -> data = (*stack_s)-> data;
	*stack_s = courant;
	return (tmp);
}

int	ft_lstsize(t_stack *lst)
{
	int		i;
	t_stack	*courant;

	i = 0;
	courant = lst;
	while (courant != NULL)
	{
		i++;
		courant = courant -> next;
	}
	return (i);
}
