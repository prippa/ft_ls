/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 15:47:31 by prippa            #+#    #+#             */
/*   Updated: 2018/01/18 15:47:33 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_show_dir(char *path)
{
	t_ls			ls;
	DIR				*directory;
	struct dirent	*dp;

	if (!(directory = opendir(path)))
		ft_printf("ls: %s: No such file or directory\n", path);
	else
	{
		dp = readdir(directory);
		while (dp)
		{
			if (dp->d_name[0] != '.')
				ft_printf("%s\n", dp->d_name);
			dp = readdir(directory);
		}
	}
}
