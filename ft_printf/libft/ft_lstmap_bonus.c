/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 22:29:49 by rysato            #+#    #+#             */
/*   Updated: 2025/05/01 18:40:23 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <ctype.h>
// #include <stdio.h>

// void	del_content(void *content)
// {
// 	free(content);
// }
// void	*toupper_content(void *content)
// {
// 	char	*str = (char *)content;
// 	char	*result;
// 	size_t	i;

// 	result = malloc(sizeof(char) * (ft_strlen(str) + 1));
// 	if (!result)
// 		return (NULL);
// 	i = 0;
// 	while (str[i])
// 	{
// 		result[i] = toupper((unsigned char)str[i]);
// 		i++;
// 	}
// 	result[i] = '\0';
// 	return (result);
// }

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*newlist;
	void	*new_content;

	if (lst == NULL || f == NULL)
		return (NULL);
	newlist = NULL;
	while (lst != NULL)
	{
		new_content = f(lst->content);
		node = ft_lstnew(new_content);
		if (node == NULL)
		{
			del(new_content);
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		ft_lstadd_back(&newlist, node);
		lst = lst->next;
	}
	return (newlist);
}

// int	main(void)
// {
// 	t_list	*a = ft_lstnew(ft_strdup("one"));
// 	t_list	*b = ft_lstnew(ft_strdup("two"));
// 	t_list	*c = ft_lstnew(ft_strdup("three"));
// 	t_list	*cur;
// 	t_list	*mapped;

// 	a->next = b;
// 	b->next = c;

// 	printf("🧪 original list:\n");
// 	cur = a;
// 	while (cur)
// 	{
// 		printf("  %s\n", (char *)cur->content);
// 		cur = cur->next;
// 	}

// 	mapped = ft_lstmap(a, toupper_content, del_content);

// 	printf("\n🧪 mapped list (uppercased):\n");
// 	cur = mapped;
// 	while (cur)
// 	{
// 		printf("  %s\n", (char *)cur->content);
// 		cur = cur->next;
// 	}

// 	ft_lstclear(&a, del_content);
// 	ft_lstclear(&mapped, del_content);
// 	return (0);
// }
