/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushlib.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/10 20:19:59 by ageels        #+#    #+#                 */
/*   Updated: 2022/07/17 22:03:02 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHLIB_H
# define PUSHLIB_H
# include <unistd.h>
# include <stdlib.h>

//STRUCS
typedef struct s_cont
{
	int	ognr;
	int	inr;
	//int	*bin;
}	t_cont;

typedef struct s_list
{
	t_cont			con;
	struct s_list	*nxt;
}	t_list;

typedef struct s_info
{
	t_list	*staa;
	t_list	*stab;
	int		smolst;
	int		bigst;
	int		total;
}	t_info;
//FUNS
//main:

//libft (00, 01):
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *string);
int		ft_isdigit(int c);
int		ft_atoi(const char *s, int *rv);

//listfun (00, 01):
t_list	*ft_lstnew(t_cont cont);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	ft_lstdelone(t_list *lst);
void	ft_lstclear(t_list **lst);

//parse:
int		ft_parse(int argc, char **argv, t_info *data);
int		ft_is_nr_double(int nr, t_info *data);
int		ft_error(t_info *data, int a);

#endif