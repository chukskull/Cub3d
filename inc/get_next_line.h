/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrahm <olabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:47:41 by olabrahm          #+#    #+#             */
/*   Updated: 2021/11/16 23:47:41 by olabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

int		ft_strchr_gnl(const char *s, int c);
char	*ft_strncpy(char *dst, char *src, int n);
char	*ft_cut_line(char **content_ptr, char *line);
char	*ft_first_line(char **content_ptr);
char	*get_next_line(int fd);
char	*ft_free_ptr(char **ptr);

#endif