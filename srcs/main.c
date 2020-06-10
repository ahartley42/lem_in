#include "../includes/lem_in.h"
#include <stdio.h> // remove

static void initialize_struct(t_room *lem)//initialize 
{
    lem->room_id = 0;
    lem->ant_id = 0;
    lem->run = 0;
    lem->xy[0] = 0;
    lem->xy[1] = 0;
    lem->name = NULL;
    lem->type = 0;
    lem->path = NULL;
    lem->next = NULL;
}

// int    ft_check_ants(char *base)
// {
//     int ant;

//     ant = ft_atoi(base);
//     if(ant > 2147483647 || ant < 1){
//         ft_putstr("Error: bigger or smaller than int size \n");
//         exit(1);
//     }
//     ft_putstr("works \n");
//     return (ant);
// }

// checks to see if there is a start and an end
// int    ft_check_start_end(char *twodarray)
// {
//      if (ft_strequ(twodarray, "##start"))
//     {
//         return (0);
//     }
//     else if (ft_strequ(twodarray, "##end"))
//     {
//         return (1);
//     }else // will have to remove
//     {
//         ft_putstr("Error: no known command");
//         exit(1);
//     }
// }

// // keeping track if two starts or ends
// void ft_keep_track_start_end(int total,int *start,int *end)
// {
//     int st;
//     int ed;
//     st = *start; // keeping track how many start and ends it finds
//     ed = *end;
//     if (total == 0)
//     {
//         st++;
//         *start = st;
//         if (st == 2)
//         {
//             ft_putstr("Error: two starts error Program Exit\n");
//             exit(1);
//         }
//     }
//     if (total == 1)
//     {
//         ed++;
//         *end = ed;
//         if (ed == 2)
//         {
//             ft_putstr("Error: two ends error Program Exit\n");
//             exit(1);
//         }
//     }
// }



// int ft_check_ants_and_skip_comments_on_top(char **twodarray, *ant_amount)
// {
//     int i;

//     i = 0;
//     while (twodarray[i])
//     {
//         if ((twodarray[i][0] == '#') && (twodarray[i][1] != '#' || twodarray[i][1] == '\0' || twodarray[i][1] == ' '))
//         i++;
//         if (check_int(twodarray[i]))
//         {
//             *ant_amount = ft_check_ants(twodarray[i]);
//             break;
//         }
//         i++;
//     }
//     return (i);
// }

// void verify_map_and_data(t_room *lem, char **twodarray, int *ant_amount)
// {
//     int i;
//     int start;  // will be removed for struct
//     int end;    // will be removed for struct
//     int total;
//     int strlen;
//     int strlenpipe;

//     lem->room_id = 1; // remove because lem not been used yet
//     i = 0;
//     start = 0;
//     end = 0;
//     total = 0;
//     strlen = 0;
//     strlenpipe = 0;
//     // i = ft_check_ants_and_skip_comments_on_top(**twodarray, &ant_amount); // not working right now

//     // looking for ant_amount once found breaks out and returns ant amount  if not found returns error
//     while (twodarray[i])
//     {
//         if (twodarray[i][0] == '#') {
//             if (ft_strequ(twodarray[i], "##start") || ft_strequ(twodarray[i], "##end")){

//             }
//             else{
//                 i++;
//             }
//         }
//         if (check_int(twodarray[i]) == 1)
//         {
//             *ant_amount = ft_check_ants(twodarray[i]);
//             break;
//         }
//         i++;
//     }
//     if (*ant_amount == 0)
//     {
//         ft_putstr("Error: please enter ant's\n");
//         exit(1);
//     }
//     i++; // incrementing past the ant_amount
//     while (twodarray[i])
//     {
//         if (twodarray[i][0] == '#' && !(ft_strequ(twodarray[i], "##start") || ft_strequ(twodarray[i], "##end"))){
//             printf("skiped: %s\n",twodarray[i]);
//         i++;
//         }
//         if (check_int(twodarray[i]) == 1)
//         {
//             ft_putstr("Error: Badly Formatted Map \n");
//             exit(1);
//         }
//         if (twodarray[i][0] == '#' && twodarray[i][1] == '#')
//         {
//             total = ft_check_start_end(twodarray[i]);
//             ft_keep_track_start_end(total, &start, &end);
//             // ft_add_Command_rooms(twodarray[i + 1], total);
//         }
//         if ((strlen = ft_strlen_space(twodarray[i])) && twodarray[i][strlen] == ' ' && twodarray[i][strlen + 1]){
//             // printf("was here\n");
//             char    **check_rooms;
//             ft_strlen_space_count(twodarray[i]); // counting the amount of spaces more or less than 2 displays error
//             check_rooms = ft_strsplit(twodarray[i], ' ');
//             ft_strlen_space_error(check_rooms[0]); // checks for name starting with L and - inside the name
//             if (check_int(check_rooms[1]) == 1 && check_int(check_rooms[2]) == 1)
//             {
//                 printf("Correct \n");
//             }else
//             {
//                 ft_putstr("Error: Badly Formatted Map X Y not integer \n");
//                 exit(1);
//             }
//             printf("room check: %s\n", check_rooms[0]);
//             free2dArray(check_rooms);
//         }
//         if ((strlenpipe = ft_strlen_space(twodarray[i])) && twodarray[i][strlenpipe] == '\0' && twodarray[i][0] != '#')
//         {
//             // printf("%s \n", twodarray[i]);
//             // printf("we got inside here \n");
//             strlenpipe = 0;
//             if (( strlenpipe = ft_strlen_pipes(twodarray[i])) == 1)
//             {
//                 printf("Correct pipe \n");
//             }
//             else{
//                 printf("Error: Invalid Pipe \n");
//             }
            
//         }
//         i++;
//         // printf("i: %d\n", i);
//         // printf("strlen: %d\n", strlen);
//         strlen = 0;
//     }
// }

// void    ft_strlen_2d_array(char **str)
// {
//     int i;
//     int k;
//     int trackHyphen;

//     i = 0;
//     k = 0;
//     trackHyphen = 0;
//     while (str[i])
//     {
//         while (str[i][k])
//         {
//             if (str[i][k] == '-'){
//                 trackHyphen++;
//                 break;
//             }
//             k++;
//         }
//         if (trackHyphen == 1)
//         break;
//         k = 0;
//         i++;
//     }
//     trackHyphen = 0;
//     while (str[i])
//     {
//         while (str[i][k])
//         {
//             if (str[i][k] == '-')
//             trackHyphen++;
//             if (str[i][0] == '#' && (str[i][1] != '#' || str[i][1] == '\0'))
//             trackHyphen++;
//             k++;
//         }
//         if (trackHyphen == 0)
//         {
//             ft_putstr("Error: Badly Formatted Map with pipes \n");
//             exit(1);
//         }else
//         trackHyphen = 0;
//         printf("a \n");
//         k = 0;
//         i++;
//     }
// }

int main(void){
    t_room lem;
    char    **map;
    int ant_amount;
    ant_amount = 0;
    initialize_struct(&lem);

        //useing
    // char    str[] = "#john\n5\n##end\nend 1 0\n##start\nstart 2 0\nLab 3 0\nba 4 0\nstart-a\na-end"; // test for caps L
    // char    str[] = "#john\n5\n##end\nend 1 0\n##start\nstart 2 0\nc-ab 3 0\nba 4 0\nstart-a\na-end"; // test for - in name
    // char    str[] = "#john\n5\n#wee\n##start\nstart 2 0\n##end\nend 1 0\ncab 3 0\nba 4 0\nstart-a\na-end"; // checking to see if no start or
    // char    str[] = "#wee";
    // char **array;
    // int ant_amount;

    // ant_amount = 0;
    // array = ft_strsplit(str, '\n');
    
    // printf("%s\n", array[1]);
    // printf("%s\n", &array[1][0]);
    // printf("%s\n", &array[1][1]);
    // printf("%s\n", &array[1][2]);
    // printf("%s\n", &array[1][3]);
    // printf("%s\n", &array[1][4]);
    // int i;
    // i = 0;
    //useing
    map = read_map();
    // printf("what: %s \n", map[0]);
    // printf("what: %s \n", map[1]);
    // printf("what: %s \n", map[2]);
    // printf("what: %s \n", map[3]);
    // while (map[i])
    // {
    //     printf("%s \n", map[i]);
    //     i++;
    // }
    ft_strlen_2d_array(map);
    verify_map_and_data(&lem, map, &ant_amount);
    printf("%d", ant_amount);
    free2dArray(map);
    return (0);
}