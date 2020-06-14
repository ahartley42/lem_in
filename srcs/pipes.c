void    add_pipes(t_room *current, char *pipe)
{

    t_room *first;
    t_room *second;

    while (current != NULL)
    {
        if (current->name == pipe[0])   //[a] - b
        {
            first = current;
        }
        else if (current->name == pipe[2])  //a - [b]
        {
            second = current;
        }
        current = current->next;
    }
    if (!first->path)
    {
        first->path = (t_room*)malloc(sizeof(t_room));
        if (first->path)
            //free
    }
    else
    {
        first->path->next = (t_room*)malloc(sizeof(t_room));
        if (!first->path->next)
            //free
        first->path = first->path->next;
    }
    first->path[0] = second;
    
    second->path[0] = first;
//     t_room  *path;
//     t_room  *tmp_room;
//     int i;

//     i = 0;
//     path = room->path;
//     tmp_room = room;
//     if (!path->begin)
//     {
//         path = (t_room*)malloc(sizeof(t_room));
//         if (!path)
//             //free path
//         path->begin = path;
//     }
//     else
//     {
//         path->next = (t_room*)malloc(sizeof(t_room));
//         if (!path->next)
//             //free path
//         path = path->next;
//     }

//     if (tmp_room->name != pipe[0] && tmp_room != NULL)
//     {
//         tmp_room = tmp_room->next;
//     }
//     path->room_id = //?
//     path->ant_id = //?
//     path->run = //?
//     path->xy[0] =
//     path->name;
//     path->type;
}