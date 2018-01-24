/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:54:06 by prippa            #+#    #+#             */
/*   Updated: 2018/01/08 17:54:08 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ls_lobi(t_lspath *pth)
{
	PI = 0;
	while (pth->e_path[PI])
	{
		if (ls_isname_toolong(pth->e_path[PI]))
			ft_printf("ls: %s: File name too long\n", pth->e_path[PI]);
		else
			ft_printf("ls: %s: No such file or directory\n", pth->e_path[PI]);
		PI++;
	}
	PI = 0;
	while (pth->files[PI])
		ls_print_file(pth->files[PI++]);
	PI = 0;
	if (pth->files[0] || pth->e_path[0])
		ft_printf("\n%s:\n", pth->dirs[PI]);
	while (pth->dirs[PI])
	{
		ls_print_dir(pth->dirs[PI]);
		PI++;
		if (pth->dirs[PI])
			ft_printf("\n%s:\n", pth->dirs[PI]);
	}
}

int				main(int argc, char **argv)
{
    struct stat 	fileStat;
	struct passwd	*pwd;
	struct group	*grp;
	char 			*tmp;

	if(argc != 2)
        return (0);
    stat(argv[1], &fileStat);
    pwd = getpwuid(fileStat.st_uid);
    grp = getgrgid(fileStat.st_gid);
    tmp = ls_get_mode(argv[1], fileStat.st_mode);
 	ft_printf("%s %d %s  %s %d",
 		tmp,
 		fileStat.st_nlink,
 		pwd->pw_name,
 		grp->gr_name,
 		fileStat.st_size);
	free(tmp);
	tmp = ft_strdup(ctime(&fileStat.st_mtime));
 	ft_printf(" %3.3s %2.2s %5.5s", &tmp[4], &tmp[8], &tmp[11]);
 	ft_printf(" %s\n", argv[1]);
 	free(tmp);
	// t_lspath pth;

	// if (argc == 1)
	// 	ls_print_dir(".");
	// else
	// {
	// 	ls_get_args(&pth, argv + 1);
	// 	ls_lobi(&pth);
	// }
	//system("leaks ft_ls");
	return (0);
}
