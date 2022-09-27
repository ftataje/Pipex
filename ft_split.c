/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftataje- <ftataje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:27:32 by ftataje-          #+#    #+#             */
/*   Updated: 2022/09/26 14:29:02 by ftataje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t	ft_wordlen(const char *s, char c)
{
	size_t	counter;

	counter = 0;
	while (*s != '\0')
	{
		if (*s == c)
			s++;
		else
		{
			counter++;
			while (*s != '\0' && *s != c)
				s++;
		}
	}
	return (counter);
}

static char	*ft_splitdup(const char *s, size_t start, size_t end)
{
	char	*dst;
	size_t	i;

	i = 0;
	dst = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!dst)
		return (NULL);
	while (start < end)
		dst[i++] = s[start++];
	dst[i] = '\0';
	return (dst);
}

static char	**ft_fill_split(char **dst, const char *s, char c)
{
	size_t	i;
	size_t	p1;
	size_t	start;

	i = 0;
	p1 = 0;
	start = 0;
	while (s[i])
	{
		while (s[i] != c && s[i])
		{
			i++;
			if (s[i] == c || i == ft_strlen(s))
				dst[p1++] = ft_splitdup(s, start, i);
		}
		while (s[i] == c && s[i])
		{
			i++;
			start = i;
		}
	}
	dst[p1] = NULL;
	return (dst);
}

char	**ft_split(const char *s, char c)
{
	char	**dst;

	if (!s)
		return (NULL);
	dst = (char **)malloc(sizeof(char *) * (ft_wordlen(s, c) + 1));
	if (!dst)
		return (NULL);
	ft_fill_split(dst, s, c);
	return (dst);
}

/* int	main(void)
{
	char	a[] = "\0aa\0bbb";

	printf("%c\n", *ft_split(a, "\0")[0]);
	printf("%c\n", *ft_split(a, "\0")[1]);
	return (0);
} */

/*El count_words retorna el numero de partes que se puede dividir
el string entre el caracter indicado como 'c'*/
