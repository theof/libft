/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 12:18:56 by tvallee           #+#    #+#             */
/*   Updated: 2014/11/06 22:03:26 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*r;
	size_t	j;
	size_t	i;
	int		a;

	if (!s)
		return (0);
	a = 0;
	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	j = (ft_strlen(s) > 0) ? ft_strlen(s) - 1 : 0;
	while (j && (s[j] == ' ' || s[j] == '\n' || s[j] == '\t'))
		j--;
	r = malloc(sizeof(char) * (j - i + 2));
	if (r)
	{
		while (i + a <= j)
		{
			r[a] = s[i + a];
			a++;
		}
		r[i] = '\0';
	}
	return (r);
}
