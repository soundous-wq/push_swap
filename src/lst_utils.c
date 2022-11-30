/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soabbas <soabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:20:24 by soabbas           #+#    #+#             */
/*   Updated: 2022/11/21 13:48:57 by soabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	if (!lst)
		return (NULL);
	last = lst;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

int	*tableau(t_list **lst)
{
	int		i;
	int		*tab;
	t_list	*temp;

	if (!*lst)
		return (0);
	i = 0;
	temp = *lst;
	tab = calloc(sizeof(int), (ft_lstsize(*lst)));
	if (!tab)
		return (0);
	while (temp)
	{
		tab[i] = temp->content;
		temp = temp->next;
		i++;
	}
	return (tab);
}

void	clear_list(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return ;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		free(lst);
		lst = tmp;
	}
}

int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (0);
	else if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9')))
			return (0);
		i++;
	}
	return (1);
}

// void	print_list(t_list *lst)
// {
// 	while (lst)
// 	{
// 		printf("%d\n", lst->content);
// 		lst = lst->next;
// 	}
// }
