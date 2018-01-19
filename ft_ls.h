
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

# define FILE_NAME_SIZE 255

typedef struct			s_ls
{
	char				**file_name;
	char				*path;
}						t_ls;

void					ls_show_dir(char *path);
void					ls_base_sort(t_ls *ls);

#endif
