# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

size_t  ft_strlen(char *s);
char    *ft_strchr(char *s, int c);
char    *ft_strdup(char *s);
char    *strjoin(char *s1, char *s2);
static char	*read_to_stash(int fd, char *stash);
static char	*extract_line(char *stash);
static char	*clean_stash(char *stash);
char		*get_next_line(int fd);

# endif