/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftataje- <ftataje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:25:39 by ftataje-          #+#    #+#             */
/*   Updated: 2022/09/26 14:28:56 by ftataje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (new != 0)
	{
		while (s1[i] != '\0')
		{
			new[i] = s1[i];
			i++;
		}
		while (s2[j] != '\0')
		{
			new[i + j] = s2[j];
			j++;
		}
		new[i + j] = '\0';
		return (new);
	}
	return (0);
}

/*int	main(void)
{
	char	a[] = "Bitcoin";
	char	b[] = "Ethereum";
	char	*res;
	res = ft_strjoin(a, b);
	printf(":%s:", res);
	return (0);
}*/

//en una nueva variable se concatena los strings
