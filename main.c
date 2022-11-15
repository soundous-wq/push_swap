/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soabbas <soabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:25:11 by soabbas           #+#    #+#             */
/*   Updated: 2022/11/15 11:30:11 by soabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	int		i;
	t_list	*lst_a;
	t_list	*tmp;
	t_list	*lst_b;
	// t_list	*tmp2; 

	if (ac < 3)
		return (0);
	i = 1;
	lst_b = 0;
	while (i < ac)
	{
		if (!comp_av(av))
			return (0);
		tmp = ft_lstnew(atoi(av[i]));
		ft_lstadd_back(&lst_a, tmp);
		i++;
	}
	printf("min : %d\n", min_index(lst_a));
	if (ac == 4)
		algo_3(&lst_a, 'a');
	if (ac == 6)
		algo_5(&lst_a, &lst_b, 'a');

	// tmp2 = lst_a;
	// int size = ft_lstsize(lst_a);
	// int *tab = sort_tab(tableau(&lst_a), size);
	// int mediane = return_mediane(tab, size);

	// printf("mediane : %d\n", mediane);
	// printf("max : %d\n", max_index(lst_a));
		printf("**** A ****\n");
	print_list(lst_a);

}
