/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushlib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageels <ageels@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:19:59 by ageels            #+#    #+#             */
/*   Updated: 2022/08/10 16:36:38 by ageels           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHLIB_H
# define PUSHLIB_H
# include <unistd.h>
# include <stdlib.h>

//STRUCS
typedef struct s_cont
{
	int				ognr;
	int				inr;
}	t_cont;

typedef struct s_list
{
	t_cont			con;
	struct s_list	*nxt;
}	t_list;

typedef struct s_info
{
	t_list			*staa;
	t_list			*stab;
	int				smolst;
	int				bigst;
	int				total;
}	t_info;

//FUNS
//main:

//libft (00, 01):
size_t	ft_strlen(const char *string);
int		ft_isdigit(int c);
int		ft_atoi(const char *s, int *rv);

//listfun (00, 01):
t_list	*ft_lstnew(t_cont cont);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstonebeforelast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	ft_lstdelone(t_list *lst);
void	ft_lstclear(t_list **lst);

//parse:
int		ft_parse(char **argv, t_info *data);
int		ft_is_nr_double(int nr, t_info *data);
int		ft_error(t_info *data, int a);
void	ft_calc_con(t_info *data);
t_list	*ft_lstbig(t_list *lst, t_list *bigst);

//display:
void	ft_putstr_fd(char *s, int fd);
void	ft_putnum_fd(long long int nbr, int fd);
void	ft_putlst_fd(t_list *lst, int fd);
void	ft_putstacks(t_info *data, int fd);

//issorted:
int		ft_issorted(t_info *data);
int		ft_issorted_bts(t_list *lst);
int		ft_issorted_stb(t_list *lst);

//sortfun (00, 01):
void	ft_pa(t_info *data, int fd);
void	ft_pb(t_info *data, int fd);
void	ft_ra(t_info *data, int fd);
void	ft_rb(t_info *data, int fd);
void	ft_rra(t_info *data, int fd);
void	ft_rrb(t_info *data, int fd);
void	ft_sa(t_info *data, int fd);
void	ft_sb(t_info *data, int fd);

//smolsort:
void	ft_smolsort(t_info *data, int fd);
void	ft_sort3(t_info *data, int fd);
void	ft_sort4(t_info *data, int fd);
void	ft_sort5(t_info *data, int fd);

//bigsort:
void	ft_bigsort(t_info *data, int fd);

#endif