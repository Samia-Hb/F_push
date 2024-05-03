/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus_P2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:45:44 by shebaz            #+#    #+#             */
/*   Updated: 2024/04/19 15:48:10 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_bonus.h"

void	rb(t_stack **stackB)//it works
{
	t_stack	*last;

	if (*stackB == NULL || (*stackB)->next == NULL)
		return ;
	last = *stackB;
	while (last->next != NULL)
		last = last->next;
	last->next = *stackB;
	*stackB = (*stackB)-> next;
	last->next->next = NULL;
}

void	rr(t_stack **stackA, t_stack **stackB)
{
	ra(stackA);
	rb(stackB);
}

void	rra(t_stack **stackA)//it works
{
	t_stack	*last;
	t_stack	*new_end;

	last = *stackA;
	new_end = NULL;
	while (last ->next != NULL)
	{
		new_end = last;
		last = last->next;
	}
	last -> next = *stackA;
	*stackA = last;
	new_end ->next = NULL;
}

void	rrb(t_stack **stackB)//it works
{
	t_stack	*last;
	t_stack	*new_end;

	last = *stackB;
	new_end = NULL;
	while (last->next != NULL)
	{
		new_end = last;
		last = last->next;
	}
	last -> next = *stackB;
	*stackB = last;
	new_end ->next = NULL;
}

void	rrr(t_stack **stackA, t_stack **stackB)
{
	rra(stackA);
	rrb(stackB);
}
