/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarollan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:16:11 by rarollan          #+#    #+#             */
/*   Updated: 2022/05/23 11:21:44 by rarollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h> //remove for push
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <fcntl.h>

/*#ifndef BUFFER_SIZE
# define BUFFER_SIZE 7 
# endif*/

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int	end_line(char *str);
int	ft_strchr(char *s, int c);
void	get_line(char *line, char *buffer);
size_t	ft_strlen(const char *s);

#endif
