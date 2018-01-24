/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sorting_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 12:16:57 by prippa            #+#    #+#             */
/*   Updated: 2018/01/19 12:17:00 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_base_sort(char ***arr)
{
	int		i;
	int		j;
	char	buf[LS_NAME_SIZE + 1];
	int		len;

	len = ft_arrlen(*arr);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len - 1)
		{
			if (ft_strcmp((*arr)[j], (*arr)[j + 1]) > 0)
			{
				ft_strcpy(buf, (*arr)[j]);
				ft_strcpy((*arr)[j], (*arr)[j + 1]);
				ft_strcpy((*arr)[j + 1], buf);
			}
			j++;
		}
		i++;
	}
}
