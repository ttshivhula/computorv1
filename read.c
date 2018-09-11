/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 10:39:53 by ttshivhu          #+#    #+#             */
/*   Updated: 2018/09/11 11:36:16 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <computorv1.h>

static double	concat(int a, int b)
{
	double c;
	
	c = (double)b;
	while(c > 1.0f)
		c *= 0.1f;
	c = (double)a + c;
	return c; 
}

static int		get_exponent(char **str)
{
	int	exp;

	exp = 0;
	while (*(*str) == '*' || *(*str) == 'X' || *(*str) == '^')
	{
		(*str)++;
	}
	while (isdigit(*(*str)))
	{
		exp	*= 10;
		exp += *(*str) - '0';
		(*str)++;
	}
	return (exp);
}

static int		ft_num(char **str, int *multi, int *sign)
{
	int first;

	first = 0;
	if (*(*str) == '=')
	{
		*multi = -1;
		(*str)++;
	}
	if (*(*str) == '+' || *(*str) == '-')
	{
		*sign = (*(*str) == '-') ? -1 : 1;
		(*str)++;
	}
	while (isdigit(*(*str)))
	{
		first *= 10;
		first += *(*str) - '0';
		(*str)++;
	}
	return (first);
}

static double	get_num(char **str, int *multi)
{
	int		first;
	int		last;
	int		sign;

	sign = 1;
	last = 0;
	first = ft_num(str, multi, &sign);
	if (*(*str) == '.')
	{
		(*str)++;
		while (isdigit(*(*str)))
		{
			last *= 10;
			last += *(*str) - '0';
			(*str)++;
		}
	}
	return (concat(first, last) * sign * (*multi));
}

void			read_values(char *s, t_values **values)
{
	int		multi;
	int		exp;
	double	n;

	multi = 1;
	while (*s)
	{
		n = get_num(&s, &multi);
		exp = get_exponent(&s);
		add_val(values, n, exp);
	}
}
