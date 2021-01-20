/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:24:06 by ddiakova          #+#    #+#             */
/*   Updated: 2021/01/20 17:15:44 by ddiakova         ###   ########.fr       */
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
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

t_list *ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return NULL;

	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *last;

	last = ft_lstlast(*alst);

	if (alst != NULL && new != NULL)
	{	
		last->next = new;
		new->next = NULL;
	}
}


int		main(void)
{
	t_list *lst;
	t_list *new;

	lst = ft_lstnew("say hello");
	new = ft_lstnew( "bonjour");

	ft_lstadd_back(&lst, new);

	while (lst)
	{
		printf("%s\n", lst->content);
			lst = lst->next;
	}
	return 0;
}
