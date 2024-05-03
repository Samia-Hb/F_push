/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:14:44 by shebaz            #+#    #+#             */
/*   Updated: 2024/04/29 17:09:12 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MIN -2147483648
# define INT_MAX 2147483647
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include "LIBFT/libft.h"
# include "FT_PRINTF/ft_printf.h"

typedef struct stack
{
	int				data;
	int				index;
	struct stack	*next;
}	t_stack;

void	sa(t_stack *stackA);
void	sb(t_stack *stackB);
void	pa(t_stack **stackA, t_stack **stackB);
void	pb(t_stack **stackA, t_stack **stackB);
void	ra(t_stack **stackA);
void	rb(t_stack **stackB);
void	rr(t_stack **stackA, t_stack **stackB);
void	rra(t_stack **stackA);
void	rrb(t_stack **stackB);
void	rrr(t_stack **stackA, t_stack **stackB);
void	push(t_stack **stackA, int data);
t_stack	*pop(t_stack **stack_s);

int		check_all(int argc, char **argv, long *arr);
long	*check_arguments(int argc, char **argv);
int		check_type(char **tab);
int		check_duplicate(long *arr, int argc, char **argv);
void	sort_three_element(t_stack **stackA);
void	sort_five_element(t_stack **stackA, t_stack **stackB);
void	sort_stacka_before(t_stack **stackA, int pos, int element);
void	sort_stacka(t_stack **stackA);
void	sort_four_element(t_stack **stack_a, t_stack **stack_b);

void	push_back_to_stacka(t_stack **stackA, t_stack **stackB);
void	push_to_stackb(t_stack **stackA, t_stack **stackB);
void	push_half_to_stackb(t_stack **stackA, t_stack **stackB);
void	push_min_to_stacka(int ele, t_stack **stackA, t_stack **stackB);
int		pos(t_stack *stack, int element);

int		ft_lstsize(t_stack *lst);
int		find_max_elememt(t_stack *stackB);
int		ft_counter(char const *str, char c);
void	fill_the_stack(int argc, char **argv, t_stack **stackA);
int		find_closest_pos(t_stack *stackA, int element);
long	ft_atoi(char *str);

int		calculate_min_element(t_stack *stackA, t_stack *stackB, int long nbr);
int		calcule_mouvement_stackb(t_stack *stackB, t_stack *stackA, int ele);
int		cal_mouvement_stacka(t_stack *stackA, int ele, int k, int *move);
t_stack	*copied_stack(t_stack *stack_to_copy);

int		min_element(t_stack *stackA);
void	execute_print_move(t_stack **stackA, t_stack **stackB, char *str);
int		nbr_of_arguments(int argc, char **argv);
int		is_stack_sorted(t_stack *s, int element);
void	clean_stack(t_stack *stack);
void	free_tab(char **tab);
void	algo_functions(t_stack **stack_a, t_stack **stack_b);
#endif
