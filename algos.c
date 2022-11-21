/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soabbas <soabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:56:08 by soabbas           #+#    #+#             */
/*   Updated: 2022/11/21 20:03:20 by soabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*tableau(t_list **lst)
{
	int		i;
	int		*tab;
	t_list	*temp;

	temp = *lst;
	i = 0;
	tab = malloc(sizeof(int) * (ft_lstsize(*lst) + 1));
	while (temp)
	{
		tab[i] = temp->content;
		temp = temp->next;
		i++;
	}
	return (tab);
}

int		*sort_tab(int *tab, int size)
{
	int		i;
	int		y;
	int		temp;
	int		*tab2 = 0;

	i = 0;
	while (i <= size)
	{
		y = i + 1;
		while (y < size)
		{
			if (tab[i] > tab[y])
			{
				temp = tab[i];
				tab[i] = tab[y];
				tab[y] = temp;
			}
			y++;
		}
		i++;
	}
	y = 0;
	while (y <= 4)
	{
		tab2[y] = tab[i];
		i--;
		y++;
	}
	y = 0;
	while (y)
		printf("tab[y] : %d\n", tab2[y]);
	return (tab2);
}

int	max_index(t_list *lst)
{
	int		i;
	int 	size;
	int		tmp;
	int		index;
	t_list	*tmp2;

	i = 0;
	size = ft_lstsize(lst);
	tmp = lst->content;
	tmp2 = lst;
	while (i <= size)
	{
		if (tmp < tmp2->content)
		{
			index = i;
			tmp = tmp2->content;
		}
		i++;
		if (tmp2->next == NULL)
			break ;
		tmp2 = tmp2->next;
	}
	return (index);
}

int		return_mediane(int *tab, int size)
{
	int		i;

	i = 0;
	while (i < (size / 2))
		i++;
	return (tab[i]);
}

int		push_min2(t_list **lst_a, t_list **lst_b, int mediane)
{
	int		size_tab;

	size_tab = ft_lstsize(*lst_a);
	if ((*lst_a)->content < mediane)
	{
		push_b(lst_a, lst_b);
		size_tab--;
		return (size_tab);
	}
	else
		rotate(lst_a, 'a');
	return (size_tab);
}

void	push_max(t_list **lst_a, t_list **lst_b)
{
	int		index;
	int		size;
	
	index = max_index(*lst_b);
	size = ft_lstsize(*lst_b);
	if (index <= (size / 2))
	{
		while (index >= 1)
		{	
			rotate(lst_b, 'b');
			index--;
		}
		push_a(lst_a, lst_b);
		return ;
	}
	if (index > (size / 2))
	{
		while (index <= size)
		{
			reverse_rotate(lst_b, 'b');
			index++;
		}
		push_a(lst_a, lst_b);
	}
}

void	algo_100(t_list **lst_a, t_list **lst_b)
{
	int		size;
	int 	mediane;
	t_list	*tmp;
	t_list	*tmp2 = NULL;

	tmp = *lst_a;
	size = ft_lstsize(tmp);
	mediane = return_mediane(sort_tab(tableau(&tmp), size), size);
	while (size >= 5)
	{
		// printf("***** tmp *****\n");
		// print_list(tmp);
		// printf("tmp->content : %d\n", tmp->content);
		size = push_min2(&tmp, lst_b, mediane);
		mediane = return_mediane(sort_tab(tableau(&tmp), size), size);
		// printf("tmp->content : %d\n", tmp->content);
		// printf("tmp->content : %d\n", tmp->content);
	}
		// printf("mediane : %d\n", mediane);
		// printf ("***** lst_a *****\n");
		// print_list(*lst_a);
		// printf ("********************\n");
		
	algo_5(&tmp, &tmp2, 'a');
	*lst_a = tmp;
		// printf("***** lst_b *****\n");
		// print_list(*lst_b);
	while (*lst_b)
	{
		push_max(lst_a, lst_b);
		// printf("================================\n\n");
	}
}