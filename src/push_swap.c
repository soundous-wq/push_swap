/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soabbas <soabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:25:11 by soabbas           #+#    #+#             */
/*   Updated: 2022/11/30 11:39:14 by soabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!new)
		return ;
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

	node = calloc(sizeof(t_list), 1);
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

int	is_sorted(t_list *lst_a)
{
	t_list	*tmp2;

	tmp2 = lst_a;
	while (tmp2->next)
	{
		if (tmp2->content > tmp2->next->content)
			return (0);
		tmp2 = tmp2->next;
	}
	return (1);
}

t_list	*sorter(int ac, t_list *lst_a)
{
	t_list	*tmp;
	t_list	*lst_b;

	tmp = lst_a;
	lst_b = NULL;
	if (ac == 2)
		swap(&tmp, 'a');
	else if (ac == 3)
		algo_3(&tmp, 'a');
	else if (ac == 5)
		algo_5(&tmp, &lst_b, 'a');
	else if (ac == 4 || (ac >= 6))
		algos(&tmp, &lst_b);
	clear_list(lst_b);
	return (tmp);
}
