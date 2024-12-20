/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khoukouj <khoukouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:57:06 by khoukouj          #+#    #+#             */
/*   Updated: 2024/12/17 15:34:11 by khoukouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*a1;
	t_stack_node	*b1;

	if (*b == NULL)
		return ;
	a1 = *a;
	b1 = *b;
	*b = b1->next;
	b1->next = a1;
	*a = b1;
	write(1, "pa\n", 3);
}

void	pb(t_stack_node **b, t_stack_node **a)
{
	t_stack_node	*a1;
	t_stack_node	*b1;

	if (*a == NULL)
		return ;
	a1 = *a;
	b1 = *b;
	*a = a1->next;
	a1->next = b1;
	*b = a1;
	write(1, "pb\n", 3);
}

t_stack_node	*ft_lstnew(int value, int index)
{
	t_stack_node	*node;

	node = malloc(sizeof(t_stack_node));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->index = index;
	node->next = NULL;
	return (node);
}
