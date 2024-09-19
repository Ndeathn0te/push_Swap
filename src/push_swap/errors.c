/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgonza <armgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:14:43 by armgonza          #+#    #+#             */
/*   Updated: 2024/09/18 20:47:39 by armgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
/* handle syntax errors, and returns
`1` for `error` should any of the following conditions are met
steps: Check if the first character of the input string
 does not contain a sign or a digit
Check if the first character of the input string contains a sign,
 but the second character does not contain a digit
do a while to continue with the numbers check*/
int	syntax_error(char *str_n)
{
	if (!(*str_n == '+'
			|| *str_n == '-'
			|| (*str_n >= '0' && *str_n <= '9')))
		return (1);
	if ((*str_n == '+'
			|| *str_n == '-')
		&& !(str_n[1] >= '0' && str_n[1] <= '9'))
		return (1);
	while (*++str_n)
	{
		if (!(*str_n >= '0' && *str_n <= '9'))
			return (1);
	}
	return (0);
}
/*Define a function that checks for duplicate 
input numbers in stack `a`Check for an empty stack
Loop until the end of stack `a` is reached
Check if the current node nbr's value is equal to `n`.*/

int	dup_arg_error(t_stack_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}
/*Define a function to free a stack if there are errors : steps
Check for an empty stack
Assign to `tmp_get_next` the pointer to the next node bcause
if you delete de current node you cannot access*/

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp_get_next;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp_get_next = current->next;
		free(current);
		current = tmp_get_next;
	}
	*stack = NULL;
}
/*Define a function that, upon encountering a unique error,
 to free the stack and print an error message*/

void	free_error(t_stack_node **a)
{
	free_stack(a);
	ft_printf("Error\n");
	exit(1);
}
