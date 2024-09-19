/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgonza <armgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:15:02 by armgonza          #+#    #+#             */
/*   Updated: 2024/09/18 20:52:37 by armgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/*function that converts every string into a long value
works like atoi but returning long*/
static long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n' || \
			*s == '\r' || *s == '\f' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}
/*function that searches for the last node to append 
	to the linked list steps: Allocate memory for the new 
	Check if the stack is empty or currently pointing to NULL,
	 indicating a first node needs +6	69+*-0071to be found
	If empty, update the pointer *stack to point to the node,
	 effectively making it the new head of the linked list
	If the stack is not empty, it means there
	 are existing nodes in the linked list
	In which case, find the last node*/

static void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*new_node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->nbr = n;
	if (!(*stack))
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}
/*Define a function that initiates stack `a` by handling
 any errors and appending required nodes to complete a stack
if (n > INT_MAX || n < INT_MIN) //Check for overflow 
If no errors, append the node to the linked list by taking 
and create a new node and assign `n` to nbr in that new node*/

void	init_stack_a(t_stack_node **a, char **argv)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (syntax_error(argv[i]))
			free_error(a);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			free_error(a);
		if (dup_arg_error(*a, (int)nbr))
			free_error(a);
		append_node(a, (int)nbr);
		i++;
	}
}
/*
Define a function that searches for the cheapest node,
 that is set by bool
*/

t_stack_node	*get_cheapest_node(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
/*Define a function that moves the required node to the top of the stack
Check if the required node is not already the first node If not, and it
 is stack `b`, execute the other set of instructions*/

void	prep_for_push(t_stack_node **stack,
						t_stack_node *top_node,
						char stack_name)
	{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}
