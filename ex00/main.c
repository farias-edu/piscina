/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davpalac <davpalac@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 15:41:31 by davpalac          #+#    #+#             */
/*   Updated: 2026/08/08 20:13:04 by davpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

/* ft_process_line Processes a line from stdin */
static void	ft_process_line_stdin(t_dict *dict, const char *line)
{
	if (!ft_is_number(line))
	{
		ft_putstr("Error\n");
		return ;
	}
	if (!ft_convert_number(dict, line))
		ft_putstr("Dict Error\n");
	else
		ft_putstr("\n");
}

/* ft_process_stdin Reads numbers from stdin (one per line) and converts them */
static int	ft_process_stdin(t_dict *dict)
{
	char	buf[1024];
	ssize_t	bytes;
	char	*line;
	char	*nl;

	while (1)
	{
		bytes = read(0, buf, sizeof(buf) - 1);
		if (bytes <= 0)
			break ;
		buf[bytes] = '\0';
		line = buf;
		while (*line)
		{
			nl = line;
			while (*nl && *nl != '\n')
				nl++;
			if (*nl == '\n')
				*nl = '\0';
			if (*line != '\0')
				ft_process_line_stdin(dict, line);
			line = nl + 1;
		}
	}
	return (1);
}

/* ft_handle_one_arg Handles the case of a single argument (number) */
static int	ft_handle_one_arg(char *arg)
{
	t_dict	*dict;

	dict = ft_read_dict("numbers.dict");
	if (!dict)
		return (ft_putstr("Dict Error\n"), 0);
	if (!ft_is_number(arg))
		return (ft_putstr("Error\n"), ft_free_dict(dict), 0);
	if (!ft_convert_number(dict, arg))
		ft_putstr("Dict Error\n");
	else
		ft_putstr("\n");
	ft_free_dict(dict);
	return (1);
}

/* ft_handle_two_args Handles the case of two arguments
 * (dictionary and number)
 */
static int	ft_handle_two_args(char *dict_file, char *number)
{
	t_dict	*dict;

	dict = ft_read_dict(dict_file);
	if (!dict)
		return (ft_putstr("Dict Error\n"), 0);
	if (!ft_is_number(number))
		return (ft_putstr("Error\n"), ft_free_dict(dict), 0);
	if (!ft_convert_number(dict, number))
		ft_putstr("Dict Error\n");
	else
		ft_putstr("\n");
	ft_free_dict(dict);
	return (1);
}

/* main Main function */
int	main(int argc, char **argv)
{
	t_dict	*dict;

	if (argc == 1)
		return (0);
	if (argc == 2 && argv[1][0] == '-' && argv[1][1] == '\0')
	{
		dict = ft_read_dict("numbers.dict");
		if (!dict)
			ft_putstr("Dict Error\n");
		else
		{
			ft_process_stdin(dict);
			ft_free_dict(dict);
		}
		return (0);
	}
	if (argc == 2)
		return (ft_handle_one_arg(argv[1]));
	if (argc == 3)
		return (ft_handle_two_args(argv[1], argv[2]));
	return (0);
}
