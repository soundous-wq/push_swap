/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soabbas <soabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:56:08 by soabbas           #+#    #+#             */
/*   Updated: 2022/11/22 19:43:01 by soabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sort_tab(int *tab, int size)
{
	int	i;
	int	y;
	int	temp;

	i = 0;
	while (i < size)
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
	return (tab);
}

int	max_index(t_list *lst)
{
	int		i;
	int		size;
	int		max;
	int		index;
	t_list	*tmp2;

	i = 0;
	index = 0;
	size = ft_lstsize(lst);
	max = lst->content;
	tmp2 = lst;
	while (i <= size)
	{
		if (max < tmp2->content)
		{
			index = i;
			max = tmp2->content;
		}
		i++;
		if (tmp2->next == NULL)
			return (index);
		tmp2 = tmp2->next;
	}
	return (index);
}

int	push_inf_mediane(t_list **lst_a, t_list **lst_b, int mediane)
{
	int	size_lst;

	size_lst = ft_lstsize(*lst_a);
	if ((*lst_a)->content < mediane)
	{
		push_b(lst_a, lst_b);
		size_lst--;
		return (size_lst);
	}
	else
		rotate(lst_a, 'a');
	size_lst--;
	return (size_lst);
}

void	push_max(t_list **lst_a, t_list **lst_b)
{
	int	index;
	int	size;

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
	else if (index > (size / 2))
	{
		while (index < size)
		{
			reverse_rotate(lst_b, 'b');
			index++;
		}
		push_a(lst_a, lst_b);
	}
}

void	algos(t_list **lst_a, t_list **lst_b)
{
	int		size;
	t_list	*tmp;
	int		mediane;

	mediane = 0;
	tmp = *lst_a;
	size = ft_lstsize(tmp);
	while (size >= 3)
	{
		mediane = return_mediane(sort_tab(tableau(&tmp), size), size);
		size = push_inf_mediane(&tmp, lst_b, mediane);
	}
	algo_3(&tmp, 'a');
	*lst_a = tmp;
	while (*lst_b)
		push_max(lst_a, lst_b);
}
