# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_memalloc.cvim                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/04 23:23:58 by tvallee           #+#    #+#              #
#    Updated: 2014/11/04 23:30:55 by tvallee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#include "libft.h"

void	ft_memdel(void **ap)
{
	if (ap != NULL)
	{
		if (*ap != NULL)
			free(*ap);
	}
	*ap = NULL;
}
