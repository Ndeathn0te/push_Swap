/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b-a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgonza <armgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:14:49 by armgonza          #+#    #+#             */
/*   Updated: 2024/09/18 11:14:50 by armgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/*Define a function that sets for the current `a` node,
 its target node from stack `a` a cuyo valor sea mayor que el 
 de b para asignarlo como el "nodo objetivo"
steps: Set the bigger node to the max long and Check if the `a`
 node's value is bigger than `b` node, && smaller than the 
 "closest bigger" so far*/
static void	set_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a_node;
	t_stack_node	*target_a_node;
	long			closest_bigger;

	while (b)
	{
		closest_bigger = LONG_MAX;
		current_a_node = a;
		while (current_a_node)
		{
			if (current_a_node->nbr > b->nbr
				&& current_a_node->nbr < closest_bigger)
			{
				closest_bigger = current_a_node->nbr;
				target_a_node = current_a_node;
			}
			current_a_node = current_a_node->next;
		}
		if (closest_bigger == LONG_MAX)
			b->target_node = find_min_nbr_node(a);
		else
			b->target_node = target_a_node;
		b = b->next;
	}
}
/*prepares the nodes for pushing `b` to `a`*/

void	prep_push_b(t_stack_node *a, t_stack_node *b)
{
	index_median_updater(a);
	index_median_updater(b);
	set_target_b(a, b);
}
