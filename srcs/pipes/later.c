			else if (i > 0 && i < pipecount)
			{
				dprintf(2, "middle:[%d]\n", fildes[(i - 1) * 2]);
	//			perror("perrormiddle");
				dup2(fildes[(i - 1) * 2], 0);
				dup2(fildes[3 + ((i - 1) * 2)], 1);
			}




	fildes = ft_calloc(sizeof(*fildes), pipecount * 2);
	while (i < pipecount)
	{
		pipe(fildes + (i * 2));
		i++;
	}










	void	enter_pipe(t_minishell *data, t_envvar_list *envlist)
{
	int			fildes[2];
	int			id[2];
	int			status;
	int			pipecount;
	int			i;
	t_minishell	*temp[2];
	char		**envp;
	char		**arg;

	temp[0] = data;
	temp[1] = data;
	pipecount = 0;
	i = 0;
	while (temp[0] && temp[0]->type == 4)
	{
		pipecount++;
		temp[0] = temp[0]->next;
	}
	i = 0;
	pipe(fildes);
	// while (i <= pipecount)
	// {
	printf("fildes0:[%d]\nfildes1:[%d]\n", fildes[0], fildes[1]);
	id[0] = fork();
	if (id[0] == 0)
	{
		// if (i == 0)
		// {
		dprintf(2, "first:[%d]\n", fildes[1]);
//			perror("perrorfirst");
		if (dup2(fildes[1], STDOUT_FILENO) == -1)
			exit_with_1message("dup failed", 1);
		close(fildes[1]);
	//	}
		run_command(temp[1], envlist, 1);
		exit(1);
	}
	id[1] = fork();
	if (id[1] == 0)
	{
	// if (i == pipecount)
// {
		dprintf(2, "last:[%d]\n", fildes[0]);
		//			perror("perrorlast");
		if (dup2(fildes[0], STDIN_FILENO) == -1)
			exit_with_1message("dup failed", 1);
		close(fildes[0]);
		//	}
		run_command(temp[1]->next, envlist, 1);
		exit(1);
	}
	else
	{
		close(fildes[0]);
		close(fildes[1]);
		waitpid(id[0], &status, 0);
		waitpid(id[1], &status, 0);
	}
	// i++;
	// temp[1] = temp[1]->next;
//	}
}













void	enter_pipe(t_minishell *data, t_envvar_list *envlist)
{
	int			fildes[2];
	int			id;
	int			status;
	int			pipecount;
	int			i;
	t_minishell	*temp[2];

	temp[0] = data;
	temp[1] = data;
	pipecount = 0;
	i = 0;
	while (temp[0] && temp[0]->type == 4)
	{
		pipecount++;
		temp[0] = temp[0]->next;
	}
	i = 0;
	pipe(fildes);
	printf("fildes0:[%d]\nfildes1:[%d]\n", fildes[0], fildes[1]);
	while (i <= pipecount)
	{
		id = fork();
		if (id == 0)
		{
			if (i == 0)
			{
				dprintf(2, "first:[%d]\n", fildes[1]);
	//			perror("perrorfirst");
				dup2(fildes[1], STDOUT_FILENO);
				close(fildes[1]);
			}

			else if (i == pipecount)
			{
	//			perror("perrorlast");
				dprintf(2, "last:[%d]\n", fildes[(pipecount * 2) - 2]);
				dup2(fildes[0], STDIN_FILENO);
			}
			run_command(temp[1], envlist, 1);
			exit(1);
		}
		else
		{
		//	close_pipes(fildes, pipecount);
//			dprintf(2, "whyyyy\n");
			waitpid(id, &status, 0);
		}
		i++;
		temp[1] = temp[1]->next;
	}
}