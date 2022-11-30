/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soabbas <soabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:46:57 by soabbas           #+#    #+#             */
/*   Updated: 2022/11/22 19:50:45 by soabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoi(char *str)
{
	int			i;
	int			signe;
	long long	result;
	long long	res;

	i = 0;
	signe = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
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
	res = (result * signe);
	if (res < INT_MIN || res > INT_MAX)
		return (INT_MIN);
	return ((long long)signe * result);
}

int	comp_av(char **av, int ac)
{
	int	i;
	int	y;
	int	*tab;

	i = 0;
	y = 0;
	tab = calloc(sizeof(int), ac);
	if (!tab)
		return (0);
	while (++i < ac)
	{
		if (!ft_isdigit(av[i]))
			return (free(tab), 0);
		tab[y++] = ft_atoi(av[i]);
	}
	if (!comp_av_2(tab, ac))
		return (free(tab), 0);
	return (free(tab), 1);
}

int	comp_av_2(int *tab, int ac)
{
	int	i;
	int	y;

	i = 0;
	while (i < ac - 1)
	{
		y = i + 1;
		while (y < ac - 1)
		{
			if (tab[i] == tab[y])
				return (0);
			y++;
		}
		i++;
	}
	return (1);
}

int	return_mediane(int *tab, int size)
{
	int	i;
	int	res;

	i = 0;
	if (size >= 0 && size <= 100)
	{
		while (i <= (size / 5))
			i++;
		res = tab[i];
	}
	else if (size >= 101 && size <= 150)
	{
		while (i <= (size / 7))
			i++;
		res = tab[i];
	}
	if (size >= 151)
		res = return_mediane_2(tab, size);
	return (free(tab), res);
}

int	return_mediane_2(int *tab, int size)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (size >= 151 && size <= 250)
	{
		while (i <= (size / 15))
			i++;
	}
	else if (size > 250 && size <= 500)
	{
		while (i++ <= (size / 17))
			i++;
	}
	else
		return_mediane(tab, size);
	res = tab[i];
	return (res);
}
