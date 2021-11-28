/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lblanche <lblanche@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 11:34:35 by lblanche          #+#    #+#             */
/*   Updated: 2021/11/27 11:38:52 by lblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"

int	ft_isspace(char *str)
{
	return (*str == '\n' || *str == '\f' || *str == '\r' || *str == '\v'
		|| *str == '\t' || *str == ' ');
}

char	*ft_split(char *tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab[i] != ':')
		i++;
	i++;
	while (ft_isspace(&tab[i]) == 1)
		i++;
	while (tab[i] != '\0')
	{
		if (!(ft_isspace(&tab[i]) && ft_isspace(&tab[i + 1])))
		{
			tab[j] = tab[i];
			tab[i] = ' ';
			j++;
		}
		i++;
	}
	tab[j - 1] = '\0';
	return (tab);
}
