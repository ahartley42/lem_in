/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map_add_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 22:26:16 by svan-nie          #+#    #+#             */
/*   Updated: 2020/06/08 22:26:16 by svan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void    check_if_pipe(t_room *lem_head,char **twodarray, int *i, unsigned char *dip_Switch)
{
    int strlenpipe;
    int j;

    strlenpipe = 0;
    j = *i;
    if ((strlenpipe = ft_strlen_space(twodarray[j])) && twodarray[j][strlenpipe] == '\0' && twodarray[j][0] != '#') // checks to see if pipes is valid
    {
    if (( strlenpipe = ft_strlen_pipes(twodarray[j])) == 1)
    {
        ft_add_pipe_address(lem_head, twodarray, &j);
    }
    else{
        ft_putstr("Error: Invalid Pipe \n");
    }
    *dip_Switch |= 8;
    *i = j;
    }
}

void    ft_check_for_random_ants(char **twodarray, int *i)
{
    int j;

    j = *i;
    if (check_int(twodarray[j]) == 1) // checks to see if more than one ant
    {
        ft_putstr("Error: Badly Formatted Map, Ants all ready Found \n");
        exit(1);
    }
    *i = j;
}

void    ft_check_start_end_room(char **twodarray,int *ij, int total, unsigned char *dip_Switch)
{
    if (twodarray[ij[0]][0] == '#' && twodarray[ij[0]][1] == '#') // checks for start and end
    {
        total = ft_check_start_end(twodarray[ij[0]]);
        ft_keep_track_start_end(total, dip_Switch);
        if ((*dip_Switch & 32) == 32)
        ft_check_start_room(twodarray, &ij[0]);
        if ((*dip_Switch & 64) == 64)
        ft_check_end_room(twodarray, &ij[0]);
    }
}

void    ft_skip_comment(char **twodarray,int *ij)
{
        if (twodarray[ij[0]][0] == '#' && twodarray[ij[0]][1] != '#') // checks for comment
        ij[0]++;
}

void    verify_map_and_data(t_room *lem_tmp, t_room *lem_head, char **twodarray, int *ant_amount)
{
    int     ij[2];
    int     total;
    int     strlen;
    //1, 2, 4, 8, 16, 32, 64, 128
    unsigned char   dip_Switch; // [2] start, [4] end, [8] pipeTrack, [16] roomTrack, [32] isStart, [64] isEnd

    ij[0] = 0;
    ij[1] = 0;
    total = 0;
    strlen = 0;
    ft_check_one(twodarray, &ij[0]);
    ft_check_for_ant_amount(twodarray, &ij[0], ant_amount);
    while (twodarray[ij[0]])
    {
        ft_skip_comment(twodarray, &ij[0]);
        ft_check_for_random_ants(twodarray, &ij[0]); // checks to see if more than one ant
        ft_check_start_end_room(twodarray, ij, total, &dip_Switch);
        if ((strlen = ft_strlen_space(twodarray[ij[0]])) && twodarray[ij[0]][strlen] == ' ' && twodarray[ij[0]][strlen + 1]){ // checks for room valid
            ft_check_valid_room(lem_tmp, twodarray, ij, &dip_Switch);
            lem_tmp = lem_tmp->next;
        }
        check_if_pipe(lem_head, twodarray, &ij[0], &dip_Switch); // checks to see if pipes is valid
        ij[0]++;
        strlen = 0;
    }
    ft_check_for_error(dip_Switch); //saving lines checks to see if end and start < 1 or if pipeTrack and roomTrack is < 1
}