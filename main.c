/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 14:12:55 by ttshivhu          #+#    #+#             */
/*   Updated: 2018/09/11 10:34:21 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef	struct			s_values
{
	double				value;
	unsigned int		exponent;
	struct s_values		*next;
}						t_values;

double	root(double n)
{
	double	lo;
	double	hi;
	double	mid;
	int		i;

	lo = 0;
	hi = n;
	i = -1;
	while (++i < 5000)
	{
		mid = (lo + hi) / 2;
		if (mid * mid == n)
			return mid;
		if (mid * mid > n)
			hi = mid;
		else
			lo = mid;
	}
	return mid;
}

int		val_exist(t_values **head, double value, int exponent)
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

void	add_val(t_values **head, double value, int exponent)
{
	t_values *tmp;

	if (!*head)
	{
		*head = (t_values *)malloc(sizeof(t_values));
		(*head)->value = value;
		(*head)->exponent = exponent;
		(*head)->next = NULL;
		return ;
	}
	if (!val_exist(head, value, exponent))
	{
		tmp = (t_values *)malloc(sizeof(t_values));
		tmp->value = value;
		tmp->exponent = exponent;
		tmp->next = *head;
		*head = tmp;
	}
}

int		deleteNode(t_values **head_ref) 
{
	t_values * temp = *head_ref, *prev;
	if (temp != NULL && temp->value == 0)
	{
		*head_ref = temp->next;
		free(temp);
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
	free(temp);
	return (1);
} 

void	clean(t_values **head)
{
	int ret;

	ret = deleteNode(head);
	if (ret)
		clean(head);
}

void	solve(double a, double b, double c, int exp)
{
	double x1;
	double	x2;

	x1 = (-b + root(b * b  - 4 * a * c)) / (2 * a);
	x2 = (-b - root(b * b  - 4 * a * c)) / (2 * a);
	if (exp == 2)
		printf("X1: %f X2: %f\n", x1, x2);
	else
	{
		x1 = (-c) / b;
		printf("X: %f\n", x1);
	}
}

void	ft_ans(double a, double b, double c, int exp)
{
	(exp == 2 || exp == 1) ? printf("Reduced form: ") : 0;
	if (exp == 2)
	{
		printf("%.3fx^2", a);
		printf("%+.3fx", b);
		printf("%+.3f = 0\n", c);
	}
	else if (exp == 1)
	{
		printf("%.3fx", b);
		printf("%+.3f = 0\n", c);
	}
	else
		printf("can't solve: %d exponents\n", exp);
	(exp == 2 || exp == 1) ? solve(a, b, c, exp) : 0;
}

int		exponent(t_values *v)
{
	int high;

	high = 0;
	while (v)
	{
		if (v->exponent > high)
			high = v->exponent;
		v = v->next;
	}
	return (high);
}

void	evaluate(t_values *v)
{
	int		exp;
	double	a;
	double	b;
	double	c;

	exp = exponent(v);
	while (v)
	{
		if (v->exponent == 2)
			a = v->value;	
		if (v->exponent == 1)
			b = v->value;	
		if (v->exponent == 0)
			c = v->value;	
		v = v->next;
	}
	ft_ans(a, b, c, exp);
}

char	*spaces(char *s)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	while (s[i])
		i++;
	ret = malloc(sizeof(char) * i + 1);
	i = -1;
	j = -1;
	while (s[++i])
	{
		if (s[i] != ' ')
			ret[++j] = s[i];
	}
	ret[j] = '\0';
	return (ret);
}

int		main(int c, char **v)
{
	t_values	*values;
	char		*str;
	
	values = NULL;
	if (c == 2 || c == 1)
	{
		//str = spaces(v[1]);
		add_val(&values, 1, 2);
		add_val(&values, 3, 1);
		add_val(&values, -4, 0);
		clean(&values);
		evaluate(values);
	}
}
