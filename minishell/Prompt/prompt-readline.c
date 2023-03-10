/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt-readline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:58:05 by mvicedo           #+#    #+#             */
/*   Updated: 2023/02/20 13:58:06 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// compiler le programme avec l'option -lreadline

void	signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();//on passe a une nouvelle ligne avec prompt
		rl_replace_line("", 0);//efface le contenu de la ligne avant le ctrl-C
		rl_redisplay();
	}
	// if (sig == SIGQUIT)
	// {
	// 	exit(1);
	// }
}

void	set_signal_action(void)
{
	struct	sigaction signal;

	ft_bzero(&signal, sizeof(signal));//met à 0 tous les bits dans la struct
	signal.sa_handler = &signal_handler;//invoque la routine signal_handler quand on recoit le signal
	sigaction(SIGINT, &signal, NULL);//applique cette structure avec la fonction à invoque au signal SIGINT (ctrl-c)
}

int	main(int ac, char **av, char **envp)
{
	char	*command;
	int	exit_status = 0;

	(void)ac;
	(void)av;
	(void)envp;
	signal(SIGQUIT, SIG_IGN);
	set_signal_action();
	while (exit_status == 0)
	{
		command = readline("minishell> ");
		add_history(command);
		//Traiter la commande
		if (strcmp(command, "exit") == 0)//Strcmp > ft_strcmp (libft)
			exit_status = 1;// Sortir de la boucle si la commande est "exit"
		else
			system(command);// Exécuter la commande (en attendant l'implementation)
		free(command);
	}
	return 0;
}
