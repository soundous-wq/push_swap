/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soabbas <soabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:20:51 by soabbas           #+#    #+#             */
/*   Updated: 2022/11/21 13:16:15 by soabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

	/* ***********	lst_utils	*********** */

t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	print_list(t_list *lst);

	/* ***********	parsing	*********** */

long long	ft_atoi(char *str);
int		ft_strcmp(char *s1, char *s2);
int		comp_av(char **av);
int     ft_isdigit(char	*str);

	/* **********	mouv	*********** */

void	swap(t_list **lst, char c);
void	rotate(t_list **lst, char c);
void	reverse_rotate(t_list **lst, char c);
void	push_a(t_list **lst_a, t_list **lst_b);
void	push_b(t_list **lst_a, t_list **lst_b);

	/* ***********	algo_3	*********** */

void	algo_3(t_list **lst, char c);
void	algo3_part2(t_list **lst, char c);

	/* ***********	algo_5	*********** */

int		min_index(t_list *lst);
int		push_min(t_list **lst_a, t_list **lst_b, char c);
void	algo_5(t_list **lst_a, t_list **lst_b, char c);

	/* ***********	algo_100_500	*********** */

int		*tableau(t_list **lst);
int		*sort_tab(int *tab, int size);
int		return_mediane(int *tab, int size);
int		max_index(t_list *lst);
void	algo_100(t_list **lst_a, t_list **lst_b);
void	push_max(t_list **lst_a, t_list **lst_b);
int		push_min2(t_list **lst_a, t_list **lst_b, int mediane);

t_list	*main2(int ac, t_list *lst_a);

#endif