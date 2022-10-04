/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soabbas <soabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:52:48 by soabbas           #+#    #+#             */
/*   Updated: 2022/09/30 18:34:11 by soabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_lstsize(t_lst *lst)
{
	int     size;

    size = 0;
    while (lst)
    {
        lst = lst->next;
        size++;
    }
	free(lst);
    return (size);
}

t_lst  *ft_lstlast(t_lst *lst)
{
    t_lst  *last;

    if (!lst)
        return (NULL);
    last = lst;
    while (last->next)
        last = last->next;
    return (last);
}

t_lst		*add_node(t_lst	**lst, t_lst *new_node)
{
	int	size;
	t_lst	*tmp;


	size = ft_lstsize(*lst);
	if (!new_node)
		return (NULL); 
	tmp = ft_lstlast(*lst);
	if (!size)
		return (new_node);
	tmp->next = new_node;
	new_node->next = NULL;
	return (new_node);
}

t_lst		*creat_node(int	nb)
{
	int i;
	t_lst	*new_node;

	i = 0;
	new_node = malloc(sizeof(*new_node));
	if(!new_node)
		return (NULL);
	new_node->content = nb;
	new_node->next = NULL;
	return (new_node);
}
