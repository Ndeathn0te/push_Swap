/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgonza <armgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:14:33 by armgonza          #+#    #+#             */
/*   Updated: 2024/09/18 11:14:34 by armgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/*
Define a function that rotates both the top `a` 
and `b` nodes to the bottom of their stacks,
if it's the cheapest move till the cheapest is on the
and update the index of 2 structs
*/
static void	cheapc_rr(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b);
	index_median_updater(*a);
	index_median_updater(*b);
}

/*Define a function that rotates both the 
bottom `a` and `b` nodes to the top of their stacks,
if it's the cheapest move till the 
cheapest move reach the top*/
static void	cheapc_rrr(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b);
	index_median_updater(*a);
	index_median_updater(*b);
}
/*function that prepares the cheapest nodes on top
of the stacks for pushing `a` nodes to stack `b`,
until there are three nodes left in `a`*/

static void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_a_node;

	cheapest_a_node = get_cheapest_node(*a);
	if (cheapest_a_node->above_median
		&& cheapest_a_node->target_node->above_median)
		cheapc_rr(a, b, cheapest_a_node);
	else if (!(cheapest_a_node->above_median)
		&& !(cheapest_a_node->target_node->above_median))
		cheapc_rrr(a, b, cheapest_a_node);
	prep_for_push(a, cheapest_a_node, 'a');
	prep_for_push(b, cheapest_a_node->target_node, 'b');
	pb(b, a);
}
/*Define a function that moves the smallest number to the top
As long as the smallest number is not at the top
Rotate or reverse rotate according to the position of the node on the median*/

static void	min_on_top(t_stack_node **a)
{
	while ((*a)->nbr != find_min_nbr_node(*a)->nbr)
	{
		if (find_min_nbr_node(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}
/*function that sorts stack `a` if it has more than 3 nodes
turk algorithm this will be hard to explain bro :D
2 steps:If stack `a` has more than three nodes and aren't
 sorted start rotating, so if isn`t sorted rotate again
so if is,nt sorted rotate Move all `b` nodes back to a sorted stack `a`
update the index and median and ensure the min is on top at the end 
(not in all cases its occurs)*/

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !is_sorted(*a))
		pb(b, a);
	if (len_a-- > 3 && !is_sorted(*a))
		pb(b, a);
	while (len_a-- > 3 && !is_sorted(*a))
	{
		prep_push_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		prep_push_b(*a, *b);
		move_b_to_a(a, b);
	}
	index_median_updater(*a);
	min_on_top(a);
}
