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

static void		ls_mem(t_lspath *pth, int f_len, int d_len, int e_len)
{
	pth->files = (char **)malloc(sizeof(char *) * f_len + 1);
	pth->files[f_len] = NULL;
	PJ = 0;
	while (PJ < f_len)
	{
		pth->files[PJ] = (char *)malloc(sizeof(char) * LS_NAME_SIZE + 1);
		pth->files[PJ][LS_NAME_SIZE] = '\0';
		PJ++;
	}
	pth->dirs = (char **)malloc(sizeof(char *) * d_len + 1);
	pth->dirs[d_len] = NULL;
	PJ = 0;
	while (PJ < d_len)
	{
		pth->dirs[PJ] = (char *)malloc(sizeof(char) * LS_NAME_SIZE + 1);
		pth->dirs[PJ][LS_NAME_SIZE] = '\0';
		PJ++;
	}
	pth->e_path = (char **)malloc(sizeof(char *) * e_len + 1);
	pth->e_path[e_len] = NULL;
}

static void		ls_get_mem(t_lspath *pth, char **argv)
{
	int f_len;
	int d_len;
	int e_len;

	PJ = PI;
	f_len = 0;
	d_len = 0;
	e_len = 0;
	while (argv[PJ])
	{
		if (ls_isdir(argv[PJ]))
			d_len++;
		else if (ls_isfile(argv[PJ]))
			f_len++;
		else
			e_len++;
		PJ++;
	}
	ls_mem(pth, f_len, d_len, e_len);
}

static void		ls_get_path(t_lspath *pth, char **argv)
{
	int f_len;
	int d_len;
	int e_len;

	ls_get_mem(pth, argv);
	f_len = 0;
	d_len = 0;
	e_len = 0;
	while (argv[PI])
	{
		if (ls_isdir(argv[PI]))
			ft_strcpy(pth->dirs[d_len++], argv[PI]);
		else if (ls_isfile(argv[PI]))
			ft_strcpy(pth->files[f_len++], argv[PI]);
		else
			pth->e_path[e_len++] = ft_strdup(argv[PI]);
		PI++;
	}
}

static void		e_path_sort(char ***arr)
{
	int		i;
	int		j;
	int		len;
	char	*buf;

	len = ft_arrlen(*arr);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len - 1)
		{
			if (ft_strcmp((*arr)[j], (*arr)[j + 1]) > 0)
			{
				buf = ft_strdup((*arr)[j]);
				free((*arr)[j]);
				(*arr)[j] = ft_strdup((*arr)[j + 1]);
				free((*arr)[j + 1]);
				(*arr)[j + 1] = ft_strdup(buf);
				free(buf);
			}
			j++;
		}
		i++;
	}
}

void			ls_get_args(t_lspath *pth, char **argv)
{
	ft_bzero(pth->flags, LS_FLAG_SIZE);
	pth->files = NULL;
	pth->dirs = NULL;
	pth->e_path = NULL;
	if ((PJ = ls_get_flags(pth, argv)) > 0)
	{
		ft_printf("ls: illegal option -- %c\n", PJ);
		ft_putendl("usage: ls [-lRGart1] [file ...]");
		exit(0);
	}
	ls_get_path(pth, argv);
	ls_base_sort(&pth->files);
	ls_base_sort(&pth->dirs);
	e_path_sort(&pth->e_path);
}
