/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <mchoma@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 04:14:24 by mchoma            #+#    #+#             */
/*   Updated: 2025/05/14 04:14:25 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>

t_list	*add_back(t_list *node, char c)
{
	t_list	*end;

	end = malloc(sizeof(t_list));
	end->let = c;
	end->next = NULL;
	node->next = end;
	return (end);
}

char	*freelist(t_list *node)
{
	t_list	*tmp;

	while(node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	return (NULL);
}

char	*lst_to_arr(t_list *first)
{
	t_list	*tmp;
	size_t	len;
	char	*str;

	len = 0;
	tmp = first;
	while(tmp)
	{
		tmp = tmp->next;
		len ++;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (freelist(first));
	len = 0;
	tmp = first;
	while (first)
	{
		str[len] = first->let;
		first = first->next;
		len ++;
	}
	freelist(tmp);
	str[len] = 0;	
	return (str);
}


char *reader(int fd)
{
	t_list	*end;
	t_list	*front;
	int	readsize;
	char	tmp[1];
	char	*rt;

	readsize = 1;
	front = malloc(sizeof(t_list));
	if (front == NULL)
		return (NULL);
	readsize = read(fd, tmp, 1);
//	printf("%i readsize \n\n", readsize);
	if(readsize == 0)
		return NULL;
	front->let = *tmp;
	front->next = NULL;
	if (*tmp == '\n')
	{
//		printf("88\n");
		return (lst_to_arr(front));
	}
	readsize = read(fd, tmp, 1);
	if(readsize == 0)
		return NULL;
	end = add_back(front, *tmp);
	if (*tmp == '\n')
	{		
//		printf("97\n");
		return (lst_to_arr(front));
	}
	while(*tmp != '\n' && readsize == 1)
	{
		readsize = read(fd, tmp, 1);
		end = add_back(end, *tmp);
	}
	if (readsize == -1)	
		return (freelist(front));
//	printf("%i, front->let\n", front->let);
	rt = lst_to_arr(front);
	return rt;
}
