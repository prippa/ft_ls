/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 17:14:36 by prippa            #+#    #+#             */
/*   Updated: 2018/01/21 17:14:41 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "ft_printf.h"
# include "libft.h"

# include <sys/xattr.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <uuid/uuid.h>
# include <dirent.h>
# include <limits.h>
# include <errno.h>
# include <time.h>
# include <grp.h>
# include <pwd.h>

# define LS_NAME_SIZE 255
# define LS_FLAG_SIZE 6
# define LS_MODE_SIZE 11
# define LI ls->i
# define LJ ls->j
# define PI pth->i
# define PJ pth->j
# define FNI ls->file_name[LI]
# define FNJ ls->file_name[LI][LJ]

# define R_BIG 0
# define R_MINI 1
# define A_MINI 2
# define L_MINI 3
# define T_MINI 4
# define G_BIG 5

typedef struct			s_ls
{
	char				**file_name;
	int					i;
	int					j;
}						t_ls;

typedef struct			s_lspath
{
	char				flags[LS_FLAG_SIZE];
	char				**files;
	char				**dirs;
	char				**e_path;
	int					i;
	int					j;
}						t_lspath;

char					*ls_get_mode(char *path, mode_t mode);

int						ls_isname_toolong(char *path);
int						ls_isfile(char *path);
int						ls_isdir(char *path);

void					ls_get_args(t_lspath *pth, char **argv);
int						ls_get_flags(t_lspath *pth, char **argv);

int						ls_print_dir(char *path);
int						ls_print_file(char *path);
void					ls_base_sort(char ***arr);
int						ls_readdir(t_ls *ls, DIR *directory, char *path);

#endif
