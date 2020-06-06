#include "includes/lem_in.h"

static void initialize_struct(t_room *lem)//initialize 
{
    lem->room_id = 0;
    lem->ant_id = 0;
    lem->run = 0;
    lem->xy[2] = 0;
    lem->name = NULL;
    lem->type = 0;
}

int main(void){
    t_room lem;

    initialize_struct(&lem);
    return (0);
}