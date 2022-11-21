/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soabbas <soabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:25:11 by soabbas           #+#    #+#             */
/*   Updated: 2022/11/21 19:58:43 by soabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	int		i;
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*lst_a;
	
	if (ac < 3)
		return (0);
	i = 0;
	while (++i < ac)
	{
		if (!comp_av(av))
			return (0);
		// if (!ft_isdigit(av[i]))
		// 	return (0);
		tmp = ft_lstnew(atoi(av[i]));
		ft_lstadd_back(&lst_a, tmp);
	}
	int size = ft_lstsize(lst_a);
	sort_tab(tableau(&lst_a), size);
	tmp2 = lst_a;
	while (tmp2->next)
	{
		if (tmp2->content > tmp2->next->content)
		{
			lst_a = main2(ac, lst_a);
			break ;
		}
		tmp2 = tmp2->next;
	}
	// printf("*** result ***\n");
	// print_list(lst_a);
}

t_list	*main2(int ac, t_list *lst_a)
{
	// printf("yessssssssssssssssssssssssssssssssssssssssssssssssss\n");
	t_list	*lst_b;
	t_list	*tmp;
	// int size;
	// int *tab;
	// int mediane;
	
	tmp = lst_a;
	lst_b = 0;
	// tab = sort_tab(tableau(&tmp), size);
	// mediane = return_mediane(tab, size);
	if (ac == 4 || ac == 3)
	{
		// printf("algo 3\n");
		algo_3(&tmp, 'a');
	}
	if (ac == 6)
	{
		// printf("\nalgo 5\n");
		algo_5(&tmp, &lst_b, 'a');
	}
	else if (ac > 6 && ac <= 101)
	{
		// printf("\nalgo 100\n");
		algo_100(&tmp, &lst_b);
	}
	lst_a = tmp;
	return (lst_a);
}
