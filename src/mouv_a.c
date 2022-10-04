/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soabbas <soabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:44:23 by soabbas           #+#    #+#             */
/*   Updated: 2022/10/04 12:03:44 by soabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_A(t_lst *n1, t_lst *n2)
{
	int tmp;
	
	if (!n1 || !n2)
		return ;
	tmp = n1->content;
	n1->content = n2->content;
	n2->content = tmp;
}

void	rotate_A(t_lst **lst)
{
	t_lst	*tmp;
	t_lst	*tmp_2;

	tmp = *lst;
	*lst = (*lst)->next;
	tmp_2 = ft_lstlast(*lst);
	tmp->next = NULL;
	tmp_2->next = tmp;
}

void	reverse_rotate_A(t_lst **lst)
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

// int main(int ac, char **av)
// {
// 	int i;
// 	t_lst	*lst;
	
// 	lst = creat_node(ft_atoi(av[1]));
// 	i = 2;
// 	while (i < ac)
// 	{
// 		add_node(&lst, creat_node(ft_atoi(av[i])));	
// 		i++;
// 	}
// 	print_lst(lst);
// 	printf("*************************\n");
// 	reverse_rotate_A(&lst);
// 	print_lst(lst);
// 	free(lst);
// 	return 0;
// }