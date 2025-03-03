/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabatist <rabatist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:21:01 by rabatist          #+#    #+#             */
/*   Updated: 2025/02/27 17:47:49 by rabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_command(t_data *data)
{
	int	is_builtin_cmd;

	if (!data->command->args[0] || data->command->args[0][0] == '\0')
		return (0);
	prepare_pipe_connection(data);
	is_builtin_cmd = is_builtin(data);
	if (is_builtin_cmd && data->command->input_fd == STDIN_FILENO
		&& data->command->output_fd == STDOUT_FILENO
		&& data->command->fd_out == -1
		&& data->prev_pipe_read_end == -1)
	{
		exec_builtins(data);
		return (0);
	}
	if (is_builtin_cmd)
		data->cmd_path = NULL;
	else
		if (check_path(data) == 1)
			return (1);
	data->exit_status = 0;
	start_fork(data, data->cmd_path, is_builtin_cmd);
	free(data->cmd_path);
	return (0);
}
