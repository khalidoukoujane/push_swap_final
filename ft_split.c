/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khoukouj <khoukouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:46:08 by khoukouj          #+#    #+#             */
/*   Updated: 2024/12/18 21:18:31 by khoukouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_sep(char set, char c)
{
	if (set == c)
		return (1);
	return (0);
}

static int	count_words(const char *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && check_sep(str[i], c) == 1)
			i++;
		if (str[i] && check_sep(str[i], c) == 0)
		{
			count++;
			while (str[i] && check_sep(str[i], c) == 0)
				i++;
		}
	}
	return (count);
}

static char	*ft_create_word(const char *str, char c)
{
	int		i;
	char	*word;

	i = 0;
	while (str[i] && check_sep(str[i], c) == 0)
		i++;
	word = (char *)malloc(i + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (str[i] && check_sep(str[i], c) == 0)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

static char	**free_ptr(char **split, int i)
{
	while (--i >= 0)
		free(split[i]);
	free(split);
	return (NULL);
}

char	**split(char *s, char c)
{
	char	**split;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	split = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	while (*s)
	{
		while (*s && check_sep(*s, c))
			s++;
		if (*s && check_sep(*s, c) == 0)
		{
			split[i] = ft_create_word(s, c);
			if (!split[i])
				return (free_ptr(split, i));
			while (*s && check_sep(*s, c) == 0)
				s++;
			i++;
		}
	}
	split[i] = NULL;
	return (split);
}
