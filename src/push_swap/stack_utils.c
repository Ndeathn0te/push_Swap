/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgonza <armgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:15:06 by armgonza          #+#    #+#             */
/*   Updated: 2024/09/18 11:15:12 by armgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/*Define a function that calculates and returns the length of a stack*/
int	stack_len(t_stack_node *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

/*Define a function that returns the pointer to the last node*/

t_stack_node	*find_last_node(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

/*checks if the stack is sorted in ascending order
steps:Check if the current value is larger than 
the next node's value, indicating it is out of 
sort and returns false if is not */

bool	is_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}
/*Define a function that searches a stack and 
returns the node with the smallest number*/

t_stack_node	*find_min_nbr_node(t_stack_node *stack)
{
	long			max;
	t_stack_node	*min_node;

	if (!stack)
		return (NULL);
	max = LONG_MAX;
	while (stack)
	{
		if (stack->nbr < max)
		{
			max = stack->nbr;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

/*Define a function that searches in a stack and
 returns the node with the biggest number*/

t_stack_node	*find_biggest_nbr(t_stack_node *stack)
{
	long			min;
	t_stack_node	*max_node;

	if (!stack)
		return (NULL);
	min = LONG_MIN;
	while (stack)
	{
		if (stack->nbr > min)
		{
			min = stack->nbr;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}
