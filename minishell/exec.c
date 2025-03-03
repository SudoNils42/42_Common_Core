/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabatist <rabatist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:56:58 by nbonnet           #+#    #+#             */
/*   Updated: 2025/02/27 17:46:47 by rabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	start_exec(t_data *data)
{
	while (data->current_token < data->token_count)
	{
		if (parse_command(data) != 0)
		{
			while (data->current_token < data->token_count
				&& data->tokens[data->current_token].type != TOKEN_PIPE)
				data->current_token++;
			if (data->current_token < data->token_count
				&& data->tokens[data->current_token].type == TOKEN_PIPE)
				data->current_token++;
			continue ;
		}
		if (execute_command(data) != 0)
			return (1);
		if (data->command)
		{
			free_command(data->command);
			free(data->command);
			data->command = NULL;
		}
		if (data->current_token < data->token_count
			&& data->tokens[data->current_token].type == TOKEN_PIPE)
			data->current_token++;
	}
	return (0);
}

void	sig_quit(int sig)
{
	(void)sig;
	printf("Quit (core dumped)\n");
}

int	process_command_line(t_data *data)
{
	g_signals(1);
	signal(SIGQUIT, &sig_quit);
	data->pid_index = 0;
	data->pids = malloc(sizeof(pid_t) * (data->token_count + 1));
	if (!data->pids)
		return (1);
	init_pid_list(data);
	if (start_exec(data) == 1)
		return (1);
	wait_for_children(data);
	g_signals(0);
	signal(SIGQUIT, SIG_IGN);
	return (0);
}

void	start_fork(t_data *data, char *cmd_path, int is_builtin_cmd)
{
	data->pid = fork();
	if (data->pid < 0)
	{
		free(cmd_path);
		data->exit_status = 1;
		return ;
	}
	data->pids[data->pid_index++] = data->pid;
	if (data->pid == 0)
		run_child_process(data, cmd_path, is_builtin_cmd);
	else
		cleanup_parent(data);
}

int	check_path(t_data *data)
{
	struct stat	st;

	data->cmd_path = find_command_path(data->command->args[0], data);
	if (!data->cmd_path)
	{
		data->exit_status = 127;
		print_first_error(data->command->args[0]);
		return (1);
	}
	else
	{
		if (stat(data->cmd_path, &st) == 0 && S_ISDIR(st.st_mode))
		{
			ft_putstr_fd(data->command->args[0], 2);
			ft_putstr_fd(": Is a directory\n", 2);
			data->exit_status = 126;
			free(data->cmd_path);
			return (1);
		}
	}
	return (0);
}
