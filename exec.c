/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzutter <mzutter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:41:10 by mzutter           #+#    #+#             */
/*   Updated: 2025/06/13 21:59:41 by mzutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_exec
{
	char	**arr;
	int		fd_in;
	int		fd_out;
	char	*heredoc;
	t_exec	*next;
	//PID?
	
} t_exec;

void init_exec(t_exec *exec)
{
	exec = malloc(sizeof(exec));
	exec->arr = NULL;
	exec->fd_in = 0;
	exec->fd_out = 1;
	exec->next = NULL;
}

t_exec	*new_node(t_exec *head)
{
	t_exec *last;	

	return (last);
}

void nom(t_shell *shell)
{
	t_token	tmp;
	t_exec	exec;
	t_exec	last;
	int		count;

	init(&exec);
	//shell->exec = exec;
	last = exec
	tmp = shell->token;
	while(tmp)
	{
		if (tmp->type == PIPE)
			// add un new node (passe au exec->next) last = new_node(shell->exec);
			//count++; (pour gerer le nom du heredoc)
		if (is_redir(tmp->type))
		{
			//check ambiguous redirect dans le token->next
		}
		if (tmp->type == CMD || tmp->type == ARG)
		{
			//ajout au exec->arr;
		}
		tmp = tmp->next;
	}
}

void nom2(t_shell *shell)
{
	t_exec *tmp;
	int		pipe_fd[2];
	int		pid[nb_pipe];
	char	*path;

	tmp = shell->exec;
	while (tmp)
	{
		pipe(); // A VERIF DANS LE CAS D'UNE SEULE COMMANDE
		if (is_builtin(tmp->arr[0]))
		//(ON FORK PAS DONC ATTENTION AUX DUP2 IL FAUT LES REMETTRES AUX VALEURS INITIALES)
		
		else
		{
			pid = fork();
			dup2 // pour input
			dup2 // pour output
			if (exec->arr)
				path = pathfinder(exec->arr[0]);
			if (!path)
				//cmd not found
			execve(path);
			while ()
			waitpid(pid[i], &status, 0)
		}
		///
	}
	
}


//On procede de gauche a droite en faisant toutes les operations qu'il faut
//Si erreur, on peut skip tous les checks de redir suivant MAIS ON GARDE LES CHECK
//


//REDIR_IN
exec->fd_in = open(tmp->next->value, O_RDONLY);
if (exec->fd_outfd_in < 0)
erreur + skip

//REDIR_OUT
exec->fd_out = open(tmp->next->value, O_WRONLY, O_TRUNC, O_CREAT);
if (exec->fd_out < 0)
erreur + skip


//REDIR_APPEND
exec-> open(O_WRONLY, O_CREAT, O_APPEND);

//REDIR_HEREDOC
// HEREDO
//MAKEFILE(OU OPENDIR/READDIR/CLOSEDIR) QUI CREER UN DOSSIER DANS LE /TMP, ON PROTEGE CE DOSSIER AVANT CHAQUE OPEN (PERMISSION DENIED)
// UNLINK SE FAIT A LA FIN PENDANT LE CLEANUP
// 
char *nbr = itoa(count);
char *name;
name = ft_strjoin("/tmp/hdoc_minishell/heredoc", nbr)
exec->fd_in = open(name, O_RDONLY);
free (nbr);
free(name);

//A rajouter dans le check de logique, check si y'a pas de commande

	Si on a le flag ambiguous redirect, on ecrit le message d'erreur on peut directement skip au prochain pipe
	On open le fichier qui suit chaque redirection avec les flags requis (Ce qui creer les fichiers d'output s'ils n'existent pas)
	Si open fail, on affiche l'erreur et on passe aussi au next pipe
	A chaque open on stock le fd qui vient du open dans la structure
	---- L'ERREUR LA PLUS A GAUCHE ENVOIE SON MESSAGE AVANT DE PASSER AU PIPE SUIVANT --------
}
- Un pointeur vers le suivant (On passe au suivant a chaque pipe)
-On remplit le tableau tel que les tokens viennent (Juste besoin de realloc le tableau a chaque fois + strdup les chaines dedans)
-//HEREDOC//



(Verifier si builtin) (if is_builtin)
Dans le cas d'un builtin, on n'appelle pas fork du coup il faut remettre a 0 & 1 le STDIN et STDOUT apres appel fonction
dup2(STDIN, fd_in)
dup(STDIN, 0)


------------------ DUP2 + fork-------------

on appelle fork
on fait les dup2
On cherche le path de la commande
On appelle execve et on passe au suivant
(FAIRE ATTENTION AUX CLOSE)

./push_swap 2> out.txt 