/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftataje- <ftataje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:52:29 by ftataje-          #+#    #+#             */
/*   Updated: 2022/09/26 14:28:47 by ftataje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (to_find[i] == '\0')
		return ((char *)str);
	while (str[j] != '\0' && j < len)
	{
		while (str[j + i] == to_find[i] && str[j + i] != '\0' && j + i < len)
		{
			i++;
		}
		if (to_find[i] == '\0')
		{
			return ((char *)str + j);
		}
		j++;
		i = 0;
	}
	return (0);
}

/* int	main(void)
{
	char	str1[] = "01: one 02: two 03: three";
	char	str2[] = "02";
	int		n;

	n = 4;
	printf("%s | %s\n", str1, str2);
	printf("%s\n", ft_strnstr(str1, str2, n));
	//printf("%s\n", strnstr(str1, str2, n));
} */
