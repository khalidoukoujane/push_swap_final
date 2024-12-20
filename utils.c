/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khoukouj <khoukouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:35:09 by khoukouj          #+#    #+#             */
/*   Updated: 2024/12/17 15:38:40 by khoukouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*get_max(t_stack_node *stack)
{
	t_stack_node	*curr;
	t_stack_node	*tmp;

	curr = stack;
	tmp = curr;
	while (curr)
	{
		if (curr->value > tmp->value)
			tmp = curr;
		curr = curr->next;
	}
	return (tmp);
}

t_stack_node	*get_min(t_stack_node *stack)
{
	t_stack_node	*curr;
	t_stack_node	*tmp;

	curr = stack;
	tmp = curr;
	while (curr)
	{
		if (curr->value < tmp->value)
			tmp = curr;
		curr = curr->next;
	}
	return (tmp);
}

int	stack_not_sorted(t_stack_node **stack)
{
	t_stack_node	*curr;

	curr = (*stack);
	while (curr)
	{
		if (curr->next != NULL)
		{
			if (curr->value > curr->next->value)
				return (1);
		}
		curr = curr->next;
	}
	return (0);
}
