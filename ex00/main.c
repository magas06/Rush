/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lblanche <lblanche@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 11:34:46 by lblanche          #+#    #+#             */
/*   Updated: 2021/11/28 14:53:58 by lblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"

int	check_arg(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	i = 0;
	while (str[i] == '0')
		i++;
	while (str[i])
	{
		i++;
		count++;
	}
	if (count > 39)
		return (0);
	return (1);
}

char	*read_input(void)
{
	int		ret;
	char	*buf;

	buf = malloc(sizeof(char *) * 100);
	if (!buf)
		return (NULL);
	ret = read(0, buf, 100);
	return (buf);
}

void	free_memory(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*process_arg(int argc, char **argv)
{
	char	*arg;

	if (argc > 3)
	{
		ft_put_error("Error\n");
		return (0);
	}
	if (argc == 2)
		arg = argv[1];
	if (argc == 1)
	{
		arg = read_input();
		if (ft_strlen(arg) > 1)
			arg[ft_strlen(arg) - 1] = '\0';
	}
	return (arg);
}

int	main(int argc, char **argv)
{
	char	**tab;
	char	*arg;
	char	*dict;

	dict = DICT;
	if (argc != 3)
		arg = process_arg(argc, argv);
	else
	{
		dict = argv[1];
		arg = argv[2];
	}
	if (!check_arg(arg))
		return (ft_put_error("Error\n"));
	tab = parse_dictionary(dict);
	if (!tab)
		return (ft_put_error("Dict Error\n"));
	ft_print(arg, tab);
	free_memory(tab);
	return (0);
}
