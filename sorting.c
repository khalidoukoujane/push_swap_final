/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khoukouj <khoukouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:34:34 by khoukouj          #+#    #+#             */
/*   Updated: 2024/12/17 15:54:03 by khoukouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	biggest_node = get_max(*a);
	if (*a == biggest_node)
		ra(a);
	else if ((*a)->next == biggest_node)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
}

void	sort_four(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*min_node;

	min_node = get_min(*a);
	if (stack_not_sorted(a))
	{
		while (true)
		{
			if (min_node->value != (*a)->value)
				rra(a, false);
			else
				break ;
		}
		pb(b, a);
		sort_three(a);
		pa(a, b);
		return ;
	}
}

void	sort_five(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*min_node;

	if (stack_not_sorted(a))
	{
		min_node = get_min(*a);
		while (true)
		{
			if ((*a)->next == min_node)
				ra(a);
			else if (min_node->value != (*a)->value)
				rra(a, false);
			else
				break ;
		}
		pb(b, a);
		sort_four(a, b);
		pa(a, b);
		return ;
	}
}
