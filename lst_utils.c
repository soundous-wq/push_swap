/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soabbas <soabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:20:24 by soabbas           #+#    #+#             */
/*   Updated: 2022/11/15 11:18:40 by soabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list  *temp;
	
	if (*lst)
	{
		temp = *lst;
		while (temp->next)
        temp = temp->next;
		temp->next = new;
	}
	else if (*lst == NULL)
	        *lst = new;
}

t_list	*ft_lstnew(int content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	if (!lst)
		return (NULL);
	last = lst;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

int	ft_lstsize(t_list *lst)
{
	int		size;

	size = 1;
	while (lst->next)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%d\n", lst->content);
		lst = lst->next;
	}
}

// bool ft_fill_initial_struct(int ac, char **av, t_list **lst)
// {
// 	t_list	*tmp;
// 	t_list	*new;
// 	size_t	i;

// 	i = 1;
// 	tmp = *lst;
// 	while (i < ac)
// 	{
// 		new = ft_lstnew(av[i]);
// 		if (!new)
// 			return (false);
// 		ft_lstadd_back(tmp, new);
// 		if (!tmp)
// 			return (false);
// 	}
// 	return (true);
// }