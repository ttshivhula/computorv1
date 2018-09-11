/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 14:12:55 by ttshivhu          #+#    #+#             */
/*   Updated: 2018/09/10 16:48:34 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef	struct		s_values
{
	double				value;
	unsigned int	exponent;
	struct s_values	*next;
}					t_values;

typedef struct		s_ans
{
	double			a;
	double			b;
	double			c;
	double			other;
}					t_ans;


double	root(double n)
{
	double lo = 0, hi = n, mid;
	for(int i = 0 ; i < 5000; i++)
	{
      mid = (lo+hi) / 2;
      if (mid*mid == n)
		  return mid;
      if (mid*mid > n)
	  {
          hi = mid;
      }
	  else{
          lo = mid;
      }
  	}
  	return mid;
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
	tmp = (t_values *)malloc(sizeof(t_values));
	tmp->value = value;
	tmp->exponent = exponent;
	tmp->next = *head;
	*head = tmp;
}

void	reduced(double a, double b, double c)
{
	printf("Reduced form: ");
	if (a)
		printf("%.3fx^2", a);
	if (b)
		printf("%+.3fx", b);
	if (c)
		printf("%+.3f\n", c);
}

void	solve(double a, double b, double c)
{
	double x1;
	double	x2;

	x1 = (-b + root(b * b  - 4 * a * c)) / (2 * a);
	x2 = (-b - root(b * b  - 4 * a * c)) / (2 * a);
	reduced(a, b, c);
	printf("X1: %f X2: %f\n", x1, x2);
}

void	evaluate(t_values *v, t_ans ans)
{
	while (v)
	{
		if (v->exponent == 2)
			ans.a += v->value;	
		if (v->exponent == 1)
			ans.b += v->value;	
		if (v->exponent == 0)
			ans.c += v->value;	
		v = v->next;
	}
	solve(ans.a, ans.b, ans.c);
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
	t_values *values = NULL;
	t_ans	ans;
	char	*str;

	ans.b = 0;
	ans.a = 0;
	ans.c = 0;
	if (c == 2 || c == 1)
	{
		//str = spaces(v[1]);
		add_val(&values, 2, 2);
		add_val(&values, -4, 1);
		add_val(&values, -3, 0);
		evaluate(values, ans);
	}
}
