/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:30:43 by tvallee           #+#    #+#             */
/*   Updated: 2014/11/07 18:34:04 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*r;

	if (s)
	{
		i = 0;
		r = malloc(sizeof(char) * len);
		if (r)
		{
			while (i < len)
			{
				r[i] = s[start + i];
				i++;
			}
			r[i] = 0;
		}
		return (r);
	}
	return (NULL);
}