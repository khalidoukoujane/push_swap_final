/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khoukouj <khoukouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:02:52 by khoukouj          #+#    #+#             */
/*   Updated: 2024/12/17 15:55:24 by khoukouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*lst_last(t_stack_node *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

int	ft_lstsize(t_stack_node *head)
{
	int	i;

	if (!head)
		return (0);
	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

void	ft_lstadd_back(t_stack_node **stack, t_stack_node *new)
{
	t_stack_node	*tmp;
	t_stack_node	*last;

	tmp = *stack;
	if (!stack || !new)
		return ;
	while (tmp)
	{
		if (tmp->value > new->value)
			tmp->index++;
		else
			new->index++;
		tmp = tmp->next;
	}
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	last = lst_last(*stack);
	last->next = new;
}

void	set_position(t_stack_node *stack)
{
	t_stack_node	*curr;
	int				i;

	i = 0;
	curr = stack;
	while (curr)
	{
		curr->position_in_stack = i;
		i++;
		curr = curr->next;
	}
}

int	max_node_positon(t_stack_node *stack)
{
	t_stack_node	*tmp;
	t_stack_node	*max;

	tmp = stack;
	max = tmp;
	while (tmp)
	{
		if (tmp->value > max->value)
			max = tmp;
		tmp = tmp->next;
	}
	return (max->position_in_stack);
}
