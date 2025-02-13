/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arphueng <arphueng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:17:08 by arphueng          #+#    #+#             */
/*   Updated: 2024/11/13 16:16:53 by arphueng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

//utils
int		ft_strlen(char *buffer);
char	*ft_strdup(char *buffer);
char	*ft_strchr(char *s, int i);
char	*ft_strjoin(char *buffer, char *next);
char	*ft_substr(char *buffer, int start, int len);

//main
char	*get_next_line(int fd);
char	*get_leftover(char *line);
char	*read_line(int fd, char *buffer, char *leftover);

#endif
