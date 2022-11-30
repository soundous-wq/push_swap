/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soabbas <soabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:42:59 by soabbas           #+#    #+#             */
/*   Updated: 2022/11/21 12:32:19 by soabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ***** ALGO 3 ***** */

void	algo_3(t_list **lst, char c)
{
	t_list	*mid;	
	t_list	*bot;

	mid = (*lst)->next;
	if (mid->next == NULL)
	{
		if (((*lst)->content) > mid->content)
			swap(lst, 'a');
		return ;
	}
	bot = mid->next;
	mid->next = bot;
	bot->next = NULL;
	if (((*lst)->content > mid->content) && (mid->content < bot->content)
		&& (bot->content > (*lst)->content))
		swap(lst, c);
	if (((*lst)->content < mid->content) && (mid->content > (*lst)->content)
		&& (bot->content < (*lst)->content))
		reverse_rotate(lst, c);
	algo3_part2(lst, c);
}

void	algo3_part2(t_list **lst, char c)
{
	t_list	*mid;
	t_list	*bot;

	mid = (*lst)->next;
	bot = (*lst)->next->next;
	(*lst)->next = mid;
	mid->next = bot;
	bot->next = NULL;
	if (((*lst)->content < mid->content) && (mid->content > bot->content)
		&& (bot->content > (*lst)->content))
	{
		reverse_rotate(lst, c);
		swap(lst, c);
	}
	if (((*lst)->content > mid->content) && (mid->content > bot->content)
		&& (bot->content < (*lst)->content))
	{
		swap(lst, c);
		reverse_rotate(lst, c);
	}
	if (((*lst)->content > mid->content) && (mid->content < bot->content)
		&& (bot->content < (*lst)->content))
		rotate(lst, c);
}

/* ***** ALGO 5 ***** */

int	min_index(t_list *lst)
{
	int	index;
	int	tmp;
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize(lst);
	tmp = lst->content;
	while (i <= size)
	{
		if (tmp > lst->content)
		{
			index = i;
			tmp = lst->content;
		}
		i++;
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
	return (index);
}

void	push_min(t_list **lst_a, t_list **lst_b, char c)
{
	int	index;
	int	size;

	index = min_index(*lst_a);
	size = ft_lstsize(*lst_a);
	if (index <= (size / 2))
	{
		while (index >= 1)
		{
			rotate(lst_a, c);
			index--;
		}
		push_b(lst_a, lst_b);
	}
	else
	{
		while (index < size)
		{
			reverse_rotate(lst_a, c);
			index++;
		}
		push_b(lst_a, lst_b);
	}
}

void	algo_5(t_list **lst_a, t_list **lst_b, char c)
{
	push_min(lst_a, lst_b, c);
	push_min(lst_a, lst_b, c);
	algo_3(lst_a, c);
	push_a(lst_a, lst_b);
	push_a(lst_a, lst_b);
}
