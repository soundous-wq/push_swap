/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soabbas <soabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:38:28 by soabbas           #+#    #+#             */
/*   Updated: 2022/11/30 11:39:48 by soabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		i;
	t_list	*tmp;
	t_list	*lst_a;

	tmp = NULL;
	lst_a = NULL;
	if (ac <= 1 || (!comp_av(av, ac)))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	i = 0;
	while (++i < ac)
	{
		tmp = ft_lstnew(ft_atoi(av[i]));
		ft_lstadd_back(&lst_a, tmp);
	}
	ac -= 1;
	if (!is_sorted(lst_a))
		lst_a = sorter(ac, lst_a);
	clear_list(lst_a);
}
