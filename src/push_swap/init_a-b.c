/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a-b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgonza <armgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:14:46 by armgonza          #+#    #+#             */
/*   Updated: 2024/09/18 11:14:47 by armgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/*updates the index starting from 0 and the median of the nodes,
Calculate the median by dividing the length of a stack by 2*/

void	index_median_updater(t_stack_node *stack)
{
	int	index;
	int	median;

	index = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = index;
		if (index <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++index;
	}
}
/*Find `a` node's target in stack `b`
Assign the smallest `long` as the closest_smaller
number for protecction and reference
Check if `b` node is smaller than `a` node && bigger than
the closest_smaller number
If true, update the value of the closest_smaller number¡
Assign the current `b` node as the `target_node`
Move to the next `b` node for comparison, until a
"closer smaller number" is found
Check if the LONG_MIN hasn't changed,
it means we haven't found anything smaller
If no change, find the biggest `nbr` and set this as the target node
If change "closer smaller number" is found, and the best match has changed*/

static void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b_node;
	t_stack_node	*target_node;
	long			closest_smaller;

	while (a)
	{
		closest_smaller = LONG_MIN;
		current_b_node = b;
		while (current_b_node)
		{
			if (current_b_node->nbr < a->nbr
				&& current_b_node->nbr > closest_smaller)
			{
				closest_smaller = current_b_node->nbr;
				target_node = current_b_node;
			}
			current_b_node = current_b_node->next;
		}
		if (closest_smaller == LONG_MIN)
			a->target_node = find_biggest_nbr(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

/*Define a function that analyses the cost of 
the `a` node along with it's target `b` node,
which is the sum of the number of instructions for both 
the nodes to rotate to the top of their stacks
steps: Assign the current `a` node's push cost, its' index value
Check if the above_median data is false, meaning it is below median
If false update a cost to the stack's length - index
Check if `a` node's target node `b` is above median
If so, update `a` node's push cost, the sum of (its current index)
	+ (its target `b` node's index)
Move to the next `a` node for its cost analysis*/

static void	cost_analysis_a(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = len_a - (a->index);
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}
/*function that sets a node's `cheapest` attribute as `true` or `false`
asignando el mayor long como el valor mas barato hasta ahora, recorremos
 y si encontramos que el nodo actual recorrido es mas barato que el valor
  definido es menor que long max o la posicion guardad del nodo anteior
actualizamos el valor mas barato (de menor valor) como el nodo actual 
actualizando el cheapest value al coste de push del estack*/

void	set_cheapest_push(t_stack_node *stack)
{
	long			cheapest_value;
	t_stack_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}
/*ready for our pushing and sorting. These functions set
 the data inside the node's structure*/

void	prep_push_a(t_stack_node *a, t_stack_node *b)
{
	index_median_updater(a);
	index_median_updater(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest_push(a);
}
