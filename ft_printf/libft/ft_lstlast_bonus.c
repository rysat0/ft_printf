/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 21:16:39 by rysato            #+#    #+#             */
/*   Updated: 2025/04/30 21:47:57 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <stdio.h>

// lst: The beginning of the list.
t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

// int	main(void)
// {
// 	t_list *a = ft_lstnew("start");
// 	t_list *b = ft_lstnew("middle");
// 	t_list *c = ft_lstnew("end");

// 	a->next = b;
// 	b->next = c;

// 	t_list *last = ft_lstlast(a);
// 	printf("Last node content: %s\n", (char *)last->content);
// }
