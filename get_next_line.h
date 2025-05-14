/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <mchoma@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 01:19:37 by mchoma            #+#    #+#             */
/*   Updated: 2025/05/14 01:19:37 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


typedef struct s_list
{
char let;
struct s_list *next;
} t_list;


# include <stdlib.h>
# include <unistd.h>


char *reader(int fd);
char	*get_next_line(int fd);

#endif

