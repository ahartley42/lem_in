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
}

int    ft_check_ants(char *base)
{
    long ant;

    ant = ft_atoi(base);
    if(ant > 2147483647 || ant < 1){
        ft_putstr("error bigger or smaller than int size \n");
        exit(1);
    }
    ft_putstr("works \n");
    return (ant);
}

// checks to see if there is a start and an end
int    ft_check_start_end(char *twodarray)
{
     if (ft_strequ(twodarray, "##start"))
    {
        return (0);
    }
    else if (ft_strequ(twodarray, "##end"))
    {
        return (1);
    }else // will have to remove
    {
        ft_putstr("error no known command");
        exit(1);
    }
}

// keeping track if two starts or ends
void ft_keep_track_start_end(int total,int *start,int *end)
{
    int st;
    int ed;
    st = *start; // keeping track how many start and ends it finds
    ed = *end;
    if (total == 0)
    {
        st++;
        *start = st;
        if (st == 2)
        {
            ft_putstr("two starts error Program Exit\n");
            exit(1);
        }
    }
    if (total == 1)
    {
        ed++;
        *end = ed;
        if (ed == 2)
        {
            ft_putstr("two starts error Program Exit\n");
            exit(1);
        }
    }
}

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

void check_file(t_room *lem, char **twodarray, int *ant_amount)
{
    int i;
    int start;  // will be removed for struct
    int end;    // will be removed for struct
    int total;

    lem->room_id = 1; // remove because lem not been used yet
    i = 0;
    start = 0;
    end = 0;
    total = 0;
    // i = ft_check_ants_and_skip_comments_on_top(**twodarray, &ant_amount); // not working right now
    while (twodarray[i])
    {
        if ((twodarray[i][0] == '#') && (twodarray[i][1] != '#' || twodarray[i][1] == '\0' || twodarray[i][1] == ' '))
        i++;
        if (check_int(twodarray[i]))
        {
            *ant_amount = ft_check_ants(twodarray[i]);
            break;
        }
        i++;
    }
    if (*ant_amount == 0)
    {
        ft_putstr("Error: please enter ants\n");
        exit(1);
    }
    i++;
    while (twodarray[i])
    {
        if ((twodarray[i][0] == '#') && (twodarray[i][1] != '#' || twodarray[i][1] == '\0' || twodarray[i][1] == ' '))
        i++;
        if (check_int(twodarray[i]))
        {
            ft_putstr("Error: Badly Formatted Map \n");
            exit(1);
        }
        if (twodarray[i][0] == '#' && twodarray[i][1] == '#')
        {
            total = ft_check_start_end(twodarray[i]);
            ft_keep_track_start_end(total, &start, &end);
            // ft_add_Command_rooms(twodarray[i + 1], total);
        }
        if ((twodarray[i]) && twodarray[i][1] == ' ' && twodarray[i] && twodarray[i][3] == ' ' && twodarray[i]){
            printf("was here\n");
            // ft_verify_rooms();
        }
        i++;
        printf("i: %d\n", i);
    }
}

int main(void){
    t_room lem;

    initialize_struct(&lem);

        //useing
    char    str[] = "#john\n5\n##end\nend 1 0\n##start\nstart 2 0\nab 3 0\nba 4 0\nstart-a\na-end";
    char **array;
    int ant_amount;

    ant_amount = 0;
    array = ft_strsplit(str, '\n');
    
    // printf("%s\n", array[1]);
    // printf("%s\n", &array[1][0]);
    // printf("%s\n", &array[1][1]);
    // printf("%s\n", &array[1][2]);
    // printf("%s\n", &array[1][3]);
    // printf("%s\n", &array[1][4]);

    //useing
    check_file(&lem, array, &ant_amount);
    printf("%d", ant_amount);
    free2dArray(array);

    return (0);
}