/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soabbas <soabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:42:59 by soabbas           #+#    #+#             */
/*   Updated: 2022/11/15 12:08:03 by soabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

	/* ***** algo 3 ***** */

void	algo_3(t_list **lst, char c)
{
	t_list	**top;
	t_list	*mid;
	t_list	*bot;

	top = malloc(sizeof(t_list));
	*top = *lst;
	mid = (*lst)->next;
	bot = (*lst)->next->next;
	(*top)->next = mid;
	mid->next = bot;
	bot->next = NULL;
	if (((*top)->content < mid->content) && (mid->content > bot->content)
		&& (bot->content > (*top)->content))
	{
		reverse_rotate(top, c);
		swap(top, c);
	}
	if (((*top)->content > mid->content) && (mid->content < bot->content)
		&& (bot->content > (*top)->content))
		swap(top, c);
	if (((*top)->content < mid->content) && (mid->content > (*top)->content)
		&& (bot->content < (*top)->content))
		reverse_rotate(top, c);
	*lst = (*top);
	algo3_part2(lst, c);
}

void	algo3_part2(t_list **lst, char c)
{
	t_list	**top;
	t_list	*mid;
	t_list	*bot;

	top = malloc(sizeof(t_list));
	*top = *lst;
	mid = (*lst)->next;
	bot = (*lst)->next->next;
	(*top)->next = mid;
	mid->next = bot;
	bot->next = NULL;
	if (((*top)->content > mid->content) && (mid->content > bot->content)
		&& (bot->content < (*top)->content))
	{
		swap(top, c);
		reverse_rotate(top, c);
	}
	if (((*top)->content > mid->content) && (mid->content < bot->content)
		&& (bot->content < (*top)->content))
		rotate(top, c);
	*lst = *top;
}

	/* ***** algo 5 ***** */

int	min_index(t_list *lst)
{
	int		index;
	int		tmp;
	int		i;
	int		size;

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
	int		index;
	int		size;
	
	index = min_index(*lst_a);
	size = ft_lstsize(*lst_a);
	if (index < (size / 2))
	{
		while (index > 1)
		{	
			rotate(lst_a, c);
			index--;
		}
		push_b(lst_a, lst_b);
	}
	else
		while (index < size)
		{
			reverse_rotate(lst_a, c);
			index++;
		}
	push_b(lst_a, lst_b);
}

void	algo_5(t_list **lst_a, t_list **lst_b, char c)
{
	push_min(lst_a, lst_b, c);
	push_min(lst_a, lst_b, c);
	algo_3(lst_a, c);
	push_a(lst_a, lst_b);
	push_a(lst_a, lst_b);
}