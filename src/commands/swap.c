/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgonza <armgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:14:39 by armgonza          #+#    #+#             */
/*   Updated: 2024/09/18 11:14:41 by armgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/*
This function swaps the first two nodes of a 
doubly linked list. If the list is empty or has only one node,
it does nothing. It updates the `next` and 
`prev` pointers so that the second node becomes the new head,
and the first node becomes the second. 
It also adjusts the pointers of adjacent
nodes to maintain the integrity of the list*/
static void	swap(t_stack_node **head)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}
/*Swap the first two nodes of stack `a` and print the instruction*/

void	sa(t_stack_node **a)

{
	swap(a);
	ft_printf("sa\n");
}
/*Swap the first two nodes of stack `b` and print the instruction*/

void	sb(t_stack_node **b)

{
	swap(b);
	ft_printf("sb\n");
}
/*Stimutaneously swap the first two nodes of
 the stack and print the instruction*/

void	ss(t_stack_node **a, t_stack_node **b)

{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
