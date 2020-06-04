#include "includes/lem_in.h"
#include "libft/libft.h"

static void intitailze_struct(t_room *lem)
{
    lem->room_id = 0;
    lem->ant_id = 0;
    lem->run = 0;
    lem->xy[2] = 0;
    lem->name = NULL;
    lem->type = 0; // NULL not working setting to 0 check again
}

int main(void){
    t_room lem;

    intitailze_struct(&lem);
    return (0);
}