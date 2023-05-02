/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 22:16:18 by tikhacha          #+#    #+#             */
/*   Updated: 2023/05/02 14:43:52 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char static	*read_from_file(int fd)
{
	char	*s;
	char	*text;

	s = ft_strdup("");
	text = get_next_line(fd);
	while (text != NULL)
	{
		s = ft_strjoin(s, text);
		free(text);
		text = get_next_line(fd);
	}
	return (s);
}

void static	borders_check(char **splited, char *str)
{
	int	i;
	int	j;

	i = -1;
	while (splited[++i])
	{
		j = -1;
		if (i > 0 && ft_strlen(splited[i - 1]) != ft_strlen(splited[i]))
		{
			write (2, "ERROR: There are different lenghted rows.\n", 42);
			exit (free_strings (splited, str));
		}
		while (splited[i][++j])
		{
			if ((i == 0 || splited[i + 1] == NULL) || \
			(j == 0 || splited[i][j + 1] == '\0'))
			{
				if (splited[i][j] != '1')
				{
					write (2, "ERROR: There are missing '1' in borders.\n", 41);
					exit (free_strings (splited, str));
				}
			}
		}
	}
}

void static	forbidden_sym_check(char **splited, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 'C' && str[i] != 'P' && str[i] != '1' \
			&& str[i] != '0' && str[i] != 'E')
		{
			if (str[i] != '\n')
			{
				free (str);
				write (2, "ERROR: There are forbidden character in our map.\n", 49);
				exit (0);
			}
		}
		if ((str[i] == '\n' && str[i + 1] == '\n'))
		{
			free (str);
			write (2, "ERROR: There are empty new line in our map.\n", 44);
			exit (0);
		}
		i++;
	}
	borders_check(splited, str);
}

char	**parsing(char *arg)
{
	char	*s;
	char	**splited;
	int		fd;

	s = ft_strrchr(arg, '.');
	if (!s || ft_strcmp(s, ".ber"))
	{
		write (2, "ERROR: Invalid file type. Program only works with .ber files. Please check and try again.\n", 90);
		exit(0);
	}
	fd = open(arg, O_RDONLY);
	if (fd == -1)
	{
		write (2, "ERROR: Invalid file. Please check and try again.\n", 49);
		exit(0);
	}
	s = ft_strtrim(read_from_file(fd), ' ');
	splited = ft_split(s, '\n');
	forbidden_sym_check(splited, s);
	flood_fill(splited);
	return (splited);
}
