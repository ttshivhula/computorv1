/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 14:12:55 by ttshivhu          #+#    #+#             */
/*   Updated: 2018/10/05 09:51:32 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <computorv1.h>

static int		exponent(t_values *v)
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

static void		evaluate(t_values *v)
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

static char		*spaces(char *s, t_garbage **gb)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	while (s[i])
		i++;
	ret = GMALLOC(gb, sizeof(char) * i + 1);
	i = -1;
	j = -1;
	while (s[++i])
	{
		if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
			ret[++j] = s[i];
	}
	ret[++j] = '\0';
	return (ret);
}

int				main(int c, char **v)
{
	t_values	*values;
	char		*str;
	t_garbage	*mem;

	mem = NULL;
	values = NULL;
	if (c == 2)
	{
		str = spaces(v[1], &mem);
		read_values(str, &values, &mem);
		clean(&values, &mem);
		evaluate(values);
	}
	GCOLLECT(mem);
}
