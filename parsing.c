/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soabbas <soabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:46:57 by soabbas           #+#    #+#             */
/*   Updated: 2022/11/17 18:50:36 by soabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoi(char *str)
{
	int		i;
	int		signe;
	long long	result;

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

int		comp_av(char **av)
{
	int i;
	int	y;
	
	i = 1;
	y = i + 1;
	while (av[i])
	{
		y = i + 1;
		while (av[y])
		{
			if(!ft_strcmp(av[i], av[y]))
				return (0);
			y++;
		}
		i++;
	}
	return (1);
}

int     ft_isdigit(char	*str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
	}
	return (1);
}