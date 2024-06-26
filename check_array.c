/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 23:33:44 by jcreux            #+#    #+#             */
/*   Updated: 2019/03/11 17:08:58 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

static int	find_tetri(char *s)
{
	int			i;
	static char	*tetri_array[19] = {O, I, IR, T, TR, HL, HR, S, Z, AL,
									AR, L, LR, J, JR, L2, L2R, J2, J2R};

	i = 0;
	while (i < 19)
	{
		if (ft_strstr(s, tetri_array[i]))
			return (i);
		i++;
	}
	return (-1);
}

char		**check_array(char **array)
{
	int			i;
	char		*tmp;
	static char	*tetri_array[19] = {O, I, IR, T, TR, HL, HR, S, Z, AL,
									AR, L, LR, J, JR, L2, L2R, J2, J2R};

	i = 0;
	while (array[i])
	{
		if (find_tetri(array[i]) == -1)
			error();
		tmp = array[i];
		array[i] = tetri_array[find_tetri(array[i])];
		free(tmp);
		i++;
	}
	return (array);
}
