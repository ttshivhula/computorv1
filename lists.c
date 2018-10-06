/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:38:22 by ttshivhu          #+#    #+#             */
/*   Updated: 2018/10/05 09:53:35 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <computorv1.h>

static int	val_exist(t_values **head, double value, int exponent)
{
	t_values *tmp;

	tmp = *head;
	while (tmp)
	{
		if (tmp->exponent == exponent)
		{
			tmp->value += value;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void		add_val(t_values **head, double value,
		int exponent, t_garbage **gb)
{
	t_values *tmp;

	if (!*head)
	{
		*head = (t_values *)GMALLOC(gb, sizeof(t_values));
		(*head)->value = value;
		(*head)->exponent = exponent;
		(*head)->next = NULL;
		return ;
	}
	if (!val_exist(head, value, exponent))
	{
		tmp = (t_values *)GMALLOC(gb ,sizeof(t_values));
		tmp->value = value;
		tmp->exponent = exponent;
		tmp->next = *head;
		*head = tmp;
	}
}

static int	deletenode(t_values **head_ref, t_garbage **gb)
{
	t_values	*temp;
	t_values	*prev;

	temp = *head_ref;
	if (temp != NULL && temp->value == 0)
	{
		*head_ref = temp->next;
		GKILL(gb, temp);
		return (1);
	}
	while (temp != NULL && temp->value != 0)
	{
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL)
		return (0);
	prev->next = temp->next;
	GKILL(gb, temp);
	return (1);
}

void		clean(t_values **head, t_garbage **gb)
{
	int ret;

	ret = deletenode(head, gb);
	if (ret)
		clean(head, gb);
}
