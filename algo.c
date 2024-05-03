/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_four_element.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 00:32:18 by shebaz            #+#    #+#             */
/*   Updated: 2024/04/29 17:08:41 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_four_element(t_stack **stack_a, t_stack **stack_b)
{
	execute_print_move(stack_a, stack_b, "pb\n");
	sort_three_element(stack_a);
	push_back_to_stacka(stack_a, stack_b);
}

void	algo_functions(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
		execute_print_move(stack_a, stack_b, "sa\n");
	else if (ft_lstsize(*stack_a) == 5)
		sort_five_element(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 4)
		sort_four_element(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 3)
		sort_three_element(stack_a);
	else
		push_half_to_stackb(stack_a, stack_b);
	if (!is_stack_sorted(*stack_a, 0))
		sort_stacka(stack_a);
}
