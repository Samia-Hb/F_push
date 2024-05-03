/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:29:58 by shebaz            #+#    #+#             */
/*   Updated: 2024/04/29 17:26:47 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_bonus.h"

int	nbr_of_arguments(int argc, char **argv)//done
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (i < argc)
	{
		count += ft_counter(argv[i], ' ');
		i++;
	}
	return (count);
}

void	check_input(char *str, t_stack **stack_a, t_stack **stack_b, long *arr)
{
	if (str[0] == '\n')
	{
		write(2, "Error\n", 6);
		free(arr);
		exit(1);
	}
	check_mov(stack_a, stack_b, str);
	free(str);
}

void	fill_the_stack(int argc, char **argv, t_stack **stackA)//done
{
	long	*arr;
	int		size;

	size = nbr_of_arguments(argc, argv);
	arr = check_arguments(argc, argv);
	while (size > 0)
	{
		push(stackA, arr[size - 1]);
		size--;
	}
	free(arr);
}

void	second_half_main(t_stack **stack_a, t_stack **stack_b, long *arr)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (str == NULL)
			break ;
		check_input(str, stack_a, stack_b, arr);
	}
	if (is_stack_sorted(*stack_a, 0) && *stack_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	long	*arr;

	stack_a = NULL;
	stack_b = NULL;
	arr = check_arguments(argc, argv);
	if (!check_all(argc, argv, arr))
	{
		free(arr);
		return (0);
	}
	else
		fill_the_stack(argc, argv, &stack_a);
	if (is_stack_sorted(stack_a, 0))
	{
		free(arr);
		return (0);
	}
	second_half_main(&stack_a, &stack_b, arr);
	free(arr);
	clean_stack(stack_a);
	return (0);
}
