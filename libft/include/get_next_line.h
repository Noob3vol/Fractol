/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:53:34 by iguidado          #+#    #+#             */
/*   Updated: 2021/12/19 13:42:49 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# define BUFF_SIZE 32

int		ft_mv_buff(char *buff);
char	*ft_buffdup(char *buff);
char	*ft_linecat(char *line, char *buff);
int		ft_dump_buff(char **line, char *buff);
int		get_next_line(int fd, char **line);

#endif
