/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanjeon <chanjeon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 07:53:42 by chanjeon          #+#    #+#             */
/*   Updated: 2022/06/27 03:41:17 by chanjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_gnl(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strndup_gnl(char *src, int n)
{
	int		i;
	int		len;
	char	*dest;

	if (src[0] == '\0')
		return (NULL);
	if (ft_strlen_gnl(src) < n || n == -1)
		len = ft_strlen_gnl(src);
	else
		len = n;
	dest = (char *)malloc(len + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(&s[i]));
		i++;
	}
	if (c == 0)
		return ((char *)(&s[i]));
	return (NULL);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		s1_len;
	int		s2_len;
	char	*str;

	if (s1 == NULL)
		return (ft_strndup_gnl(s2, -1));
	s1_len = ft_strlen_gnl(s1);
	s2_len = ft_strlen_gnl(s2);
	str = (char *)malloc(s1_len + s2_len + 1);
	if (str == NULL)
		return (NULL);
	str[s1_len + s2_len] = '\0';
	i = -1;
	while (++i < s1_len)
		str[i] = s1[i];
	i = -1;
	while (++i <= s2_len)
		str[s1_len + i] = s2[i];
	free(s1);
	return (str);
}
