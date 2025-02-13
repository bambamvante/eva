/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arphueng <arphueng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:43:07 by arphueng          #+#    #+#             */
/*   Updated: 2024/11/13 16:12:07 by arphueng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
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