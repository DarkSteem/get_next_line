/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nberen <nberen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:40:01 by nberen            #+#    #+#             */
/*   Updated: 2021/12/21 17:30:29 by nberen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

# ifndef FD_MAX_COUNT
#  define FD_MAX_COUNT 8192
# endif

char		*get_next_line(int fd);

size_t		ft_strlen(const char *s);

char		*ft_strjoin(char *s1, char *s2);

int			ft_check_endl(char *s);

char		*ft_get_line(char *s);

char		*ft_new_static_str(char *s);

int			ft_check_endl(char *s);

#endif