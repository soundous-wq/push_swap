/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soabbas <soabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:18:52 by soabbas           #+#    #+#             */
/*   Updated: 2022/10/04 16:31:07 by soabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_B(t_lst *n1, t_lst *n2)
{
	int tmp;
	
	if (!n1 || !n2)
		return ;
	tmp = n1->content;
	n1->content = n2->content;
	n2->content = tmp;
}

void	rotate_B(t_lst **lst)
{
	t_lst	*tmp;
	t_lst	*tmp_2;

	tmp = *lst;
	*lst = (*lst)->next;
	tmp_2 = ft_lstlast(*lst);
	tmp->next = NULL;
	tmp_2->next = tmp;
}

void	reverse_rotate_B(t_lst **lst)
{
	t_lst	*tmp;
	t_lst	*tmp2;

	tmp = *lst;
	*lst = ft_lstlast(*lst);
	(*lst)->next = tmp;
	tmp2 = tmp;
	while (tmp2->next != *lst)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
}

void	push_a(t_lst **lst_a, t_lst **lst_b)
{
	t_lst	*tmp_a;
	t_lst	*tmp_b;

	if (!lst_b)
		return ;
	tmp_a = *lst_a;
	tmp_b = *lst_b;
	tmp_b->next = tmp_a;
	tmp_a->next = NULL;
}

int main(void)
{
	int nb_a = 1;
	int nb_b = 2;
	t_lst *tmp_a;
	t_lst *tmp_b;
	t_lst **lst;

	tmp_a = add_node(&lst ,creat_node(nb_a));
	printf("TEST\n");
	tmp_b = add_node(&lst ,creat_node(nb_b));	
	printf("tmp_b->content : %d\n", tmp_b->content);
	push_a(&tmp_a, &tmp_b);
	return 0;
}