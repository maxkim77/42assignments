/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 00:31:13 by jeongkim          #+#    #+#             */
/*   Updated: 2025/02/13 00:31:14 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_separator(char c, char *charset)
{
	int	i;

	i = 0;
	if (!charset)
		return (0);
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str || !charset)
		return (0);
	while (str[i])
	{
		while (str[i] && ft_is_separator(str[i], charset))
			i++;
		if (str[i])
			count++;
		while (str[i] && !ft_is_separator(str[i], charset))
			i++;
	}
	return (count);
}

int	ft_word_length(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !ft_is_separator(str[i], charset))
		i++;
	return (i);
}

char	*ft_extract_word(char *str, char *charset)
{
	int		len;
	int		i;
	char	*word;

	len = ft_word_length(str, charset);
	i = 0;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**words;
	int		i;
	int		word_count;

	i = 0;
	if (!str || !charset)
		return (NULL);
	word_count = ft_count_words(str, charset);
	words = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!words)
		return (NULL);
	while (*str)
	{
		while (*str && ft_is_separator(*str, charset))
			str++;
		if (*str)
		{
			words[i] = ft_extract_word(str, charset);
			i++;
		}
		while (*str && !ft_is_separator(*str, charset))
			str++;
	}
	words[i] = NULL;
	return (words);
}
