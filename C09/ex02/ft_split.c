/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 15:43:05 by pmaury            #+#    #+#             */
/*   Updated: 2021/02/02 13:25:05 by pmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strndup(char *src, int n)
{
	int		i;
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * (n + 1))))
			return (0);
	i = 0;
	while (i < n)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int		count_words(char *str, char *charset)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (is_separator(str[i]), charset[i])
			i++;
		if (str[i])
		{
			words++;
			while (!is_separator(str[i]), charset[i])
				i++;
		}
	}
	return (words);
}

int		*count_words_len(char *str, char *charset)
{
	int	index;
	int	i;
	int	words_count;
	int	*words_len;

	i = 0;
	words_count = count_words(str, charset);
	words_len = malloc(words_count * sizeof(int));
	while (i <= words_count)
	{
		words_size[i] = 0;
		i++;
	}
	i = 0;
	index = 0;
	while (str[i] != '\0')
	{
		if (!is_separator(str[i], charset))
			words_len[index]++;
		else if (i > 0 && !is_separator(str[i - 1], charset))
			index++;
		i++;
	}
	return (words_len);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		len;
	int		words;
	char	**tab;

	i = 0;
	j = 0;
	words = count_words(str);
	tab = (char)malloc(sizeof(char *) * (words + 1));
	tab[words] = 0;
	while (str[i])
	{
		if (is_separator(str[i]) == 0)
		{
			len = count_words_len(&str[i]);
			tab[j++] = ft_strndup(&str[i], len);
			i += len;
		}
		else
			i++;
	}
	return (tab);
}

#include <stdio.h>

int		main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 3)
	{
		while (av[i])
		{
			printf("%s \n", ft_split(av[1], av[2]));
			i++;
		}
	}
	return (0);
}
