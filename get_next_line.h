/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanjeon <chanjeon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 05:23:13 by chanjeon          #+#    #+#             */
/*   Updated: 2022/06/27 04:41:59 by chanjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define FD_MAX 256

typedef struct s_file_list
{
	int					fd;
	char				*remainder;
	struct s_file_list	*next;
}						t_list;

int		ft_strlen_gnl(const char *s);
char	*ft_strndup_gnl(char *src, int n);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_strjoin_gnl(char *s1, char *s2);

char	*get_next_line(int fd);

#endif
