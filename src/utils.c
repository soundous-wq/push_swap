/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soabbas <soabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:31:32 by soabbas           #+#    #+#             */
/*   Updated: 2022/10/04 13:59:41 by soabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long long	ft_atoi(char *str)
{
	int		i;
	int		signe;
	long long	result;

	i = 0;
	signe = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		signe *= -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	
	return ((long long)result * signe);
}

int     ft_strcmp(char *s1, char *s2)
{
    int     i;

    i = 0;
	if (!s2)
		return (0);
    while (s1[i] || s2[i])
    {
        if (s1[i] != s2[i])
                return (s1[i] - s2[i]);
        i++;
    }
    return (0);
}

void	print_lst(t_lst *lst)
{
	t_lst	 *tmp;
	
	tmp = lst;
	while (tmp)
	{
		printf("lst->content : %d\n", tmp->content);
		printf("lst->next : %p\n\n", tmp->next);
		tmp = tmp->next;
	}
}

void	print_lst_b(t_lst *lst)
{
	t_lst	 *tmp;
	
	tmp = lst;
	while (tmp->next)
	{
		printf("lst->content : %d\n", tmp->content);
		printf("lst->next : %p\n\n", tmp->next);
		tmp = tmp->next;
	}
}

// res = add_node(&lst, creat_node(nb));
// int main(int ac, char **av)
// {
//     int i;
//     int y;

//     i = 1;
//     y = i + 1;
//     while (av[y])
//     {
//         while (ft_strcmp(av[i], av[y]) && (y < ac - 1))
//             y++;
//         if (!ft_strcmp(av[i], av[y]))
//         {
//             write(2, "Error\n", 6);
//             return (0);
//         }
//         i++;
//         y = i + 1;
//     }
//     return (0);
// }