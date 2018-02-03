/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 16:19:15 by ibohonos          #+#    #+#             */
/*   Updated: 2018/02/02 22:21:21 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "get_next_line.h"
#define CYN   "\x1B[36m"
#define RESET "\x1B[0m"

void	ft_bonus(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'O')
			ft_printf("%S ", L"🌛");
		else if (line[i] == 'X')
			ft_printf("%S ", L"🌱");
		else if (line[i] == '.' && line[0] != 'l' && line[0] != '$'
			&& line[0] != '#')
			ft_printf(CYN"%S "RESET, L"☀");
		else if (line[i] == '*')
			ft_printf("%S ", L"🌽");
		else if ((line[i] == 'o' || line[i] == 'x') &&
			line[0] != '<' && line[0] != '$' && line[0] != '#'
			&& line[0] != 'l')
			ft_printf("%S ", L"🐗");
		else
			ft_printf("%c", line[i]);
		i++;
	}
	ft_printf("\n");
}

int		main(void)
{
	char *line;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		ft_bonus(line);
		free(line);
		line = NULL;
	}
	return (0);
}
