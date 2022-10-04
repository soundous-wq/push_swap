/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soabbas <soabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:53:22 by soabbas           #+#    #+#             */
/*   Updated: 2022/10/04 16:22:35 by soabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>


typedef struct s_list
{
    int content;
    struct s_list *next;
}	t_lst ;

void	swap_A(t_lst *n1, t_lst *n2);
void	rotate_A(t_lst **lst);
void	reverse_rotate_A(t_lst **lst);


void	swap_B(t_lst *n1, t_lst *n2);
void	rotate_B(t_lst **lst);
void	reverse_rotate_B(t_lst **lst);
void	push_a(t_lst **lst_a, t_lst **lst_b);

/* LISTES */

int		ft_lstsize(t_lst *lst);
void	free_lst(t_lst *lst);
void	print_lst(t_lst *lst);
t_lst	*creat_node(int	nb);
t_lst	*ft_lstlast(t_lst *lst);
t_lst		*add_node(t_lst	**lst, t_lst *new_node);


/**************************************************************/

int	check_doublons(char *str);
long long	ft_atoi(char *str);

#endif