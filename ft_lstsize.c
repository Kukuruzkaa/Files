/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 10:01:36 by ddiakova          #+#    #+#             */
/*   Updated: 2021/01/20 11:21:11 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ****************************************************************************/

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

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (alst != NULL && new != NULL)
	{
		new->next = *alst;
		*alst = new;
	}
}

int		ft_lstsize(t_list *lst)
{
	int counter;

	counter = 0;
	
	if (lst != NULL)
	{
		while (lst)
		{
			lst = lst->next;
			counter++;
		}
	}
	return (counter);
}

int		main(void)
{
	t_list *lst;
	t_list *first;
	t_list *second;
	t_list *third;

	lst = ft_lstnew("today!");
	first = ft_lstnew("day");
	second = ft_lstnew("a wondeful");
	third = ft_lstnew("What");

	ft_lstadd_front(&lst, first);
	ft_lstadd_front(&lst, second);
	ft_lstadd_front(&lst, third);

	printf("%d\n", ft_lstsize(lst));

	while (lst)
	{
		printf("%s\n", lst->content);
			lst = lst->next;
	}
	return (0);
}



