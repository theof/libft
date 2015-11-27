/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/15 10:16:04 by tvallee           #+#    #+#             */
/*   Updated: 2015/11/23 10:29:32 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"
#define TOO_M_ARG "getopt error: validopts len over uintmax_t bit number"

static uintmax_t	get_opt(char *opt, char **validopts, int soloopt)
{
	size_t	i;

	i = 0;
	if (soloopt && *opt == '-')
	{
		while (validopts[i])
			if (!ft_strcmp(validopts[i++], opt + 1))
				return (1 << (i - 1));
		return (0);
	}
	else
	{
		if (*opt == 0)
			return (0);
		while (validopts[i])
		{
			if (validopts[i][0] == *opt && !validopts[i][1])
				break ;
			i++;
		}
		if (!validopts[i])
			return (0);
		return (1 << i | get_opt(opt + 1, validopts, 0));
	}
}

static void			remove_line(char **av)
{
	while (av[1])
	{
		av[0] = av[1];
		av++;
	}
	av[0] = NULL;
}

char				*ft_getopt_emsg(char *emsg)
{
	static char		*err = NULL;

	if (emsg)
		err = emsg;
	else
		return (err);
	return (err);
}

int					ft_getopt(int *ac, char **av, char **validopts,
																uintmax_t *opts)
{
	uintmax_t	ret;

	*opts = 0;
	if (ft_tablen((void **)validopts) > sizeof(uintmax_t) * 8)
	{
		ft_getopt_emsg(TOO_M_ARG);
		return (-1);
	}
	while (*av != NULL)
	{
		if (*av[0] == '-' && (*ac)--)
		{
			ret = get_opt(*av + 1, validopts, 1);
			if (!ret)
			{
				ft_getopt_emsg(ft_strjoin("unrecognized option: ", *av + 1, 0));
				return (-1);
			}
			remove_line(av);
			*opts |= ret;
		}
		else
			av++;
	}
	return (0);
}
