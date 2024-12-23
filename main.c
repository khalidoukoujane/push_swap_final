/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khoukouj <khoukouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:24:31 by khoukouj          #+#    #+#             */
/*   Updated: 2024/12/23 14:44:20 by khoukouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(char *str, int i, int sign)
{
	long	res;

	res = 0;
	sign = 1;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		(write(2, "Error\n", 6), exit(1));
	while (str[i])
	{
		res = res * 10 + (str[i] - '0');
		if ((res * sign) > INT_MAX || (res * sign) < INT_MIN
			|| (str[i] < '0' || str[i] > '9'))
			(write(2, "Error\n", 6), exit(1));
		i++;
	}
	if (str[i])
		(write(2, "Error\n", 6), exit(1));
	return (res * sign);
}

void	ft_stack_init(t_stack_node **a, char **av, int i)
{
	int		j;
	long	nbr;
	char	**str;

	i = 1;
	while (av[i])
	{
		str = split(av[i], ' ');
		if (!str)
			ft_free_errors(a);
		j = 0;
		while (str[j])
		{
			nbr = ft_atol(str[j], 0, 0);
			if (duplicate_error(*a, (int)nbr))
				ft_free_errors(a);
			(free(str[j]), ft_lstadd_back(a, ft_lstnew((int)nbr, 0)));
			j++;
		}
		if (j == 0)
			(write(2, "Error\n", 6), exit(1));
		free(str);
		i++;
	}
}

int	main(int ac, char *av[])
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if (ac == 2 && av[1][0] == '\0')
		(write(2, "Error\n", 6), exit(1));
	ft_stack_init(&a, av, 0);
	if (stack_not_sorted(&a))
	{
		move_to_b(&a, &b, 0, 0);
		move_back_to_a(&a, &b, 0);
	}
	free_stack(&a);
}
