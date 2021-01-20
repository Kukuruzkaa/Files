/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 10:15:57 by ddiakova          #+#    #+#             */
/*   Updated: 2021/01/20 09:52:17 by ddiakova         ###   ########.fr       */
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





void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (alst != NULL && new != NULL)
	{
		new->next = *alst;
		*alst = new;
	}
}



int		main(void)
{
	t_list *lst;
	t_list *new;

	lst = ft_lstnew("say hello");
	new = ft_lstnew( "bonjour");

	ft_lstadd_front(&lst, new);

	while (lst)
	{
		printf("%s\n", lst->content);
			lst = lst->next;
	}
	return 0;
}
