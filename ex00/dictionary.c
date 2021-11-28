/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lblanche <lblanche@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 11:33:28 by lblanche          #+#    #+#             */
/*   Updated: 2021/11/27 15:57:51 by lblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (count_total(tab[i]) > count_total(tab[j]))
			{
				temp = tab[j];
				tab[j] = tab[i];
				tab[i] = temp;
			}
			j++;
		}
		i++;
	}
}

int	count_lines(char *file_to_open)
{
	int		count;
	char	buf[2];
	int		fd;

	fd = open(file_to_open, O_RDONLY);
	if (fd == -1)
		return (-1);
	count = 0;
	while (read(fd, buf, 1))
	{
		if (buf[0] == '\n')
			count++;
	}
	close(fd);
	if (count < 41)
		return (-1);
	return (count);
}

void	malloc_tab(char **tab, int fd, char *file_to_open)
{
	int		i;
	int		count;
	char	buf[2];

	fd = open(file_to_open, O_RDONLY);
	if (fd == -1)
		return ;
	i = 0;
	count = 0;
	while (read(fd, buf, 1))
	{
		i++;
		if (buf[0] == '\n')
		{
			tab[count] = malloc(sizeof(char *) * (i + 1));
			if (!tab)
				return ;
			i = 0;
			count++;
		}
	}
	tab[count] = NULL;
}

void	read_and_fill(char **tab, int fd, char *file_to_open)
{
	int		i;
	int		count;
	char	buf[2];

	fd = open(file_to_open, O_RDONLY);
	if (fd == -1)
		return ;
	i = 0;
	count = 0;
	while (read(fd, buf, 1))
	{
		tab[count][i] = buf[0];
		tab[count][i + 1] = '\0';
		i++;
		if (buf[0] == '\n')
		{
			i = 0;
			count++;
		}
	}
	tab[count] = NULL;
}

char	**parse_dictionary(char *file_to_open)
{
	char	**tab;
	int		fd;
	int		i;

	fd = open(file_to_open, O_RDONLY);
	if (fd == -1)
		return (NULL);
	if (!(count_lines(file_to_open) < 41))
		tab = malloc(sizeof(char *) * (count_lines(file_to_open) + 1));
	else
		tab = NULL;
	if (!tab)
		return (NULL);
	close(fd);
	malloc_tab(tab, fd, file_to_open);
	close(fd);
	read_and_fill(tab, fd, file_to_open);
	ft_sort_string_tab(tab);
	if (close(fd) == -1)
		return (NULL);
	i = -1;
	while (tab[++i])
		ft_split(tab[i]);
	return (tab);
}
