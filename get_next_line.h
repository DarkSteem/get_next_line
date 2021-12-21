/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nberen <nberen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:22:18 by nberen            #+#    #+#             */
/*   Updated: 2021/12/21 14:50:07 by nberen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 99999999
# endif

char		*get_next_line(int fd);

size_t		ft_strlen(const char *str);

char		*ft_strjoin(char *s1, char *s2);

int			ft_check_endl(char *s);

char		*ft_get_line(char *s);

char		*ft_new_static_str(char *s);

char		*ft_read_static_str(int fd, char *str);

#endif