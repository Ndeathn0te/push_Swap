/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgonza <armgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:15:40 by armgonza          #+#    #+#             */
/*   Updated: 2024/09/18 20:44:10 by armgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/inc/ft_printf.h"
# include "../libft/inc/libft.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack_node
{
	struct s_stack_node	*prev;
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
}						t_stack_node;

/*stack initiation */
void					init_stack_a(t_stack_node **a, char **argv);

/*commands*/
void					sa(t_stack_node **b);
void					sb(t_stack_node **b);
void					ss(t_stack_node **a, t_stack_node **b);
void					ra(t_stack_node **a);
void					rrr(t_stack_node **a, t_stack_node **b);
void					pa(t_stack_node **a, t_stack_node **b);
void					pb(t_stack_node **b, t_stack_node **a);
void					rb(t_stack_node **b);
void					rr(t_stack_node **a, t_stack_node **b);
void					rra(t_stack_node **a);
void					rrb(t_stack_node **b);
void					move_b_to_a(t_stack_node **a, t_stack_node **b);

/*Nodes initiation */

void					index_median_updater(t_stack_node *stack);
void					set_cheapest_push(t_stack_node *stack);
void					prep_push_a(t_stack_node *a, t_stack_node *b);
void					prep_push_b(t_stack_node *a, t_stack_node *b);
t_stack_node			*get_cheapest_node(t_stack_node *stack);
void					prep_for_push(t_stack_node **s, t_stack_node *n,
							char c);

/*Stack utils */
int						stack_len(t_stack_node *stack);
bool					is_sorted(t_stack_node *stack);
t_stack_node			*find_last_node(t_stack_node *stack);
t_stack_node			*find_min_nbr_node(t_stack_node *stack);
t_stack_node			*find_biggest_nbr(t_stack_node *stack);

/*algorithms*/
void					sort_three(t_stack_node **a);
void					sort_stacks(t_stack_node **a, t_stack_node **b);

/*Handle errors*/
int						syntax_error(char *SHORT_MAX);
int						dup_arg_error(t_stack_node *a, int n);
void					free_stack(t_stack_node **stack);
void					free_error(t_stack_node **a);

#endif