/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lblanche <lblanche@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 11:34:24 by lblanche          #+#    #+#             */
/*   Updated: 2021/11/27 14:31:19 by lblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# define DICT "numbers.dict"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

int		ft_strlen(char *str);
void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
int		count_total(char *str);
int		check_arg(char *str);
char	**parse_dictionary(char *file_to_open);
void	ft_print(char *str, char **tab);
char	*ft_split(char *tab);
int		zero_check(char *str);
int		ft_put_error(char *str);

#endif
