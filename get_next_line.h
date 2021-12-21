#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

char	*get_next_line(int fd);

size_t	ft_strlen(const char *s);

char	*ft_strjoin(char *s1, char *s2);

int		ft_check_endl(char *s);

char	*ft_get_line(char *s);

char	*ft_new_static_str(char *s);

int		ft_check_endl(char *s);


#endif