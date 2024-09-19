/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgonza <armgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:14:30 by armgonza          #+#    #+#             */
/*   Updated: 2024/09/18 11:14:31 by armgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/*rotates the stack's top node to the bottom of the stack
steps: Assign to the pointer of the top node,
	the node after it (second from the top)
Complete setting the current top node by
 detaching it from its previous top node
Reconnect the second node's prev pointer to point 
to what was previously the last node in the stack*/
static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}
/*Rotate the top `a` node to the bottom of the stack,
	and print the instruction*/

void	ra(t_stack_node **a)
{
	rotate(a);
	ft_printf("ra\n");
}
/*Rotate the top `b` node to the bottom of the stack,
	and print the instruction*/

void	rb(t_stack_node **b)
{
	rotate(b);
	ft_printf("rb\n");
}
/*Simultaneously rotate both the top `a` and `b` nodes
 to the bottom of the stack, and print the instruction*/

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}

/*Define a function that prepares `b`'s target `a
` nodes for pushing all `b` nodes back to stack `a`
ensuring b target a node is on top of the stack */

void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b);
}
