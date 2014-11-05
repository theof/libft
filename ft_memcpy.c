/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:18:52 by tvallee           #+#    #+#             */
/*   Updated: 2014/11/05 18:46:20 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		*(unsigned char *)(dst + i) = *(unsigned char *)(src + i++);
	return (dst);
}
