/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soabbas <soabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:18:36 by soabbas           #+#    #+#             */
/*   Updated: 2022/11/13 20:00:38 by soabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **lst, char c)
{
	t_list	*tmp;

	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = (*lst)->next;
	(*lst)->next = tmp;
	if (c == 'a')
		write(1, "sa\n", 3);
	if (c == 'b')
		write(1, "sb\n", 3);
}

void	rotate(t_list **lst, char c)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *lst;
	*lst = (*lst)->next;
	tmp2 = ft_lstlast(tmp);
	tmp2->next = tmp;
	tmp->next = NULL;
	if (c == 'a')
		write(1, "ra\n", 3);
	if (c == 'b')
		write(1, "rb\n", 3);
}

void	reverse_rotate(t_list **lst, char c)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *lst;
	while ((*lst)->next->next)
		*lst = (*lst)->next;
	tmp2 = *lst;
	*lst = (*lst)->next;
	tmp2->next = NULL;
	(*lst)->next = tmp;
	if (c == 'a')
		write(1, "rra\n", 4);
	if (c == 'b')
		write(1, "rrb\n", 4);
}

void	push_a(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmpb;
	t_list	*tmp;

	if (!(*lst_b))
		return ;
	tmpb = *lst_b;
	tmp = tmpb->next;
	tmpb->next = *lst_a;
	*lst_a = tmpb;
	*lst_b = tmp;
	write(1, "pa\n", 3);
}

void	push_b(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmpa;
	t_list	*tmp;

	if (!(*lst_a))
		return ;
	tmpa = *lst_a;
	tmp = tmpa->next;
	tmpa->next = *lst_b;
	*lst_b = tmpa;
	*lst_a = tmp;
	write(1, "pb\n", 3);
}
