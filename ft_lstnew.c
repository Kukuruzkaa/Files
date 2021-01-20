/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 10:15:57 by ddiakova          #+#    #+#             */
/*   Updated: 2021/01/19 15:09:58 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;


t_list *ft_lstnew(void *content)
{
	t_list *lst;

	if (!(lst = (t_list*)malloc(sizeof(t_list))))
			return (NULL);
	lst -> content = content;
	lst -> next = NULL;
	return (lst);
}

int		main(void)
{
	t_list *lst;

	lst = ft_lstnew("Hrgg544555");
	while (lst)
	{
		printf("%s\n", lst->content);
			lst = lst ->next;
	}
	return 0;
}
