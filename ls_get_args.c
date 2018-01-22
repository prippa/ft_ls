/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_get_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:33:49 by prippa            #+#    #+#             */
/*   Updated: 2018/01/22 16:33:50 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ls_get_path(t_lspath *pth, char **argv)
{
	return (1);
}

static int		ls_get_flags(t_lspath *pth, char **argv)
{
	PI = 0;
	while (argv[PI] && argv[PI][0] == '-')
	{
		PJ = 1;
		if (!argv[PI][PJ])
			return (0);
		while (argv[PI][PJ])
		{
			if (argv[PI][PJ] == 'R')
				pth->flags[R_BIG] = 'R';
			else if (argv[PI][PJ] == 'r')
				pth->flags[R_MINI] = 'r';
			else if (argv[PI][PJ] == 'a')
				pth->flags[A_MINI] = 'a';
			else if (argv[PI][PJ] == 'l')
				pth->flags[L_MINI] = 'l';
			else if (argv[PI][PJ] == 't')
				pth->flags[T_MINI] = 't';
			else if (argv[PI][PJ] != '1')
				return ((int)argv[PI][PJ]);
			PJ++;
		}
		PI++;
	}
	return (0);
}

void		ls_get_args(t_lspath *pth, char **argv)
{
	ft_bzero(pth->flags, LS_FLAG_SIZE);
	pth->files = NULL;
	pth->dirs = NULL;
	pth->e_files = NULL;
	if ((PJ = ls_get_flags(pth, argv)) > 0)
	{
		ft_printf("ls: illegal option -- %c\n", PJ);
		ft_putendl("usage: ls [-lRart1] [file ...]");
		exit(0);
	}
	ls_get_path(pth, argv);
}
