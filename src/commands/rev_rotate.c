/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgonza <armgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:14:23 by armgonza          #+#    #+#             */
/*   Updated: 2024/09/18 11:14:24 by armgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
/* rotates a stack's bottom node, to the top
Assign to the `next` attribute of the node before itself,
`NULL` effectively setting it as the current last node
and do some more thing to be de first node in the
linked list structure, im too lazy rigth now i need to sleep bro
tengo sueño :C */
static void	rev_rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last_node(*stack);
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	*stack = last_node;
	last_node->next->prev = last_node;
}
/*Rotate the bottom of `a` to the top of the stack 
and print the instruction*/

void	rra(t_stack_node **a)
{
	rev_rotate(a);
	ft_printf("rra\n");
}
/*Rotate the bottom of `b` to the top of 
the stack and print the instruction*/

void	rrb(t_stack_node **b)
{
	rev_rotate(b);
	ft_printf("rrb\n");
}
/*Simultaneously rotate both stacks' bottom nodes to the top
 of their stacks, halving the cost of instructions*/

void	rrr(t_stack_node **a, t_stack_node **b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_printf("rrr\n");
}
