/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:12:17 by bgresse           #+#    #+#             */
/*   Updated: 2022/11/23 10:23:52 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	clear(char **strings, int a)
{
	if (!strings[a])
	{
		while (a >= 0)
		{
			free(strings[a]);
			a--;
		}
		free(strings);
		return (1);
	}
	return (0);
}

static int	ft_wordcount(char const *s, char c)
{
	int	wordcount;
	int	i;

	wordcount = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			while (s[i] == c)
				i++;
		else
		{
			while (s[i] && s[i] != c)
				i++;
			wordcount++;
		}
	}
	return (wordcount);
}

static	char	**tab(char const *s, char **strings, char c, size_t start)
{
	size_t	end;
	int		wordcount;

	end = 0;
	wordcount = 0;
	while (s[start])
	{
		if (s[start] == c)
			while (s[start] == c)
				start++;
		else
		{
			end = start;
			while (s[end] && s[end] != c)
				end++;
			strings[wordcount] = ft_substr(s, start, (end - start));
			if (wordcount < ft_wordcount(s, c) && clear (strings, wordcount))
				return (NULL);
			wordcount++;
			start = end;
		}
	}
	strings[wordcount] = NULL;
	return (strings);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	int		wordcount;

	if (!s)
		return (NULL);
	wordcount = ft_wordcount(s, c);
	strings = malloc(sizeof(char *) * (wordcount + 1));
	if (!strings)
		return (NULL);
	return (tab(s, strings, c, 0));
}
