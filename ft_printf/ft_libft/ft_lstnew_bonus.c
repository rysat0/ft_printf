/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:00:28 by rysato            #+#    #+#             */
/*   Updated: 2025/04/30 21:47:56 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*newnode;

	newnode = malloc(sizeof(t_list));
	if (newnode == NULL)
		return (NULL);
	newnode->content = content;
	newnode->next = NULL;
	return (newnode);
}

// int	main(void)
// {
// 	t_list	*node;

// 	node = ft_lstnew("Hello!");
// 	if (node)
// 	{
// 		printf("Content: %s\n", (char *)node->content);
// 		printf("Next: %p\n", node->next);
// 	}
// 	else
// 		printf("Allocation failed\n");
// 	return (0);
// }
