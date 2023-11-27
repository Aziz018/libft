/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkheta <aelkheta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:30:09 by aelkheta          #+#    #+#             */
/*   Updated: 2023/11/22 20:06:08 by aelkheta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_cnt;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	new_cnt = NULL;
	while (lst)
	{
		new_cnt = ft_lstnew(f(lst->content));
		if (!new_cnt)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_cnt);
		lst = lst->next;
	}
	return (new_lst);
}
/*
void	del(void *s)
{
	free(s);
}

void	*upper(void *str)
{
	char	*s;

	s = (char *)str;
	while (*s)
	{
		*s -= 32;
		s++;
	}
	return (str);
}

int	main(void)
{
	t_list	*one;
	t_list	*two;
	t_list	*last;
	t_list	*result;

	one = ft_lstnew(strdup("one"));
	two = ft_lstnew(strdup("two"));
	last = ft_lstnew(strdup("last"));
	one->next = two;
	two->next = last;
	last->next = NULL;
	result = ft_lstmap(one, upper, del);
	while (result)
	{
		printf("%s\n", (char *)result->content);
		result = result->next;
	}
	ft_lstclear(&result, del);
	return (0);
}
*/