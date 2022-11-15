/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soabbas <soabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:56:08 by soabbas           #+#    #+#             */
/*   Updated: 2022/11/15 10:36:09 by soabbas          ###   ########.fr       */
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
	return (tab);
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

	i = 1;
	while (i < (size / 5))
		i++;
	return (tab[i]);
}

void	algo_100(t_list **lst_a, t_list **lst_b, char c)
{
	int		size;

	size = ft_lstsize(*lst_a);
	while (size >= 3)
	{
		push_min(lst_a, lst_b, c);
		size--;
	}
	printf("***** A *****\n");
	algo_3(lst_a, c);
	printf("***** A *****\n");

	print_list(*lst_a);
}
