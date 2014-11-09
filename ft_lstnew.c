/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:27:47 by tvallee           #+#    #+#             */
/*   Updated: 2014/11/09 19:18:35 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *data, size_t data_size)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	new->content = malloc(data_size);
	new->content = (data) ? ft_memcpy(new->content, (void*)data, data_size)
		: NULL;
	new->content_size = (data) ? data_size : 0;
	new->next = NULL;
	return (new);
}
