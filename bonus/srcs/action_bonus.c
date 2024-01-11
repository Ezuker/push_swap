/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 01:55:45 by bcarolle          #+#    #+#             */
/*   Updated: 2024/01/11 01:55:45 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

static t_action    *char_to_action(char *name)
{
    t_action    *new_action;

    new_action = malloc(sizeof(t_action));
    if (!new_action)
        return (NULL);
    new_action->name = ft_strdup(name);
    new_action->next = NULL;
    return (new_action);
}

t_action    *ft_lastaction(t_action *lst)
{
    if (!lst)
        return (NULL);
    while (lst->next != NULL)
        lst = lst->next;
    return (lst);
}

t_bool  check_name(char *name)
{
    if (!ft_strcmp(name, "sa\n"))
        return (true);
    if (!ft_strcmp(name, "sb\n"))
        return (true);
    if (!ft_strcmp(name, "ss\n"))
        return (true);
    if (!ft_strcmp(name, "pa\n"))
        return (true);
    if (!ft_strcmp(name, "pb\n"))
        return (true);
    if (!ft_strcmp(name, "ra\n"))
        return (true);
    if (!ft_strcmp(name, "rb\n"))
        return (true);
    if (!ft_strcmp(name, "rr\n"))
        return (true);
    if (!ft_strcmp(name, "rra\n"))
        return (true);
    if (!ft_strcmp(name, "rrb\n"))
        return (true);
    if (!ft_strcmp(name, "rrr\n"))
        return (true);
    return (false);
}

t_bool    add_action(char *name, t_action **action)
{
    t_action    *last;

    if (!check_name(name))
        return (false);
    if (!action || !(*action))
        (*action) = char_to_action(name);
    else
    {
        last = ft_lastaction(*action);
        last->next = char_to_action(name);
    }
    return (true);
}