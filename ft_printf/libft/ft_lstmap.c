/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togomes- <togomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:08:33 by togomes-          #+#    #+#             */
/*   Updated: 2024/11/17 12:47:17 by togomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_clean(t_list **new_list, void *new_content, void (*del)(void *))
{
	if (new_content)
		del(new_content);
	ft_lstclear(new_list, del);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_obj;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		if (!new_content)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		new_obj = ft_lstnew(new_content);
		if (!new_obj)
		{
			ft_lst_clean(&new_list, new_content, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_obj);
		lst = lst->next;
	}
	return (new_list);
}
