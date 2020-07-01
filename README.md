# lem_in
lem_in is an ant-farm reader which displays the routes ants will follow from the starting room to the ending room

## creating and running the ant-farm reader
Simply run the following command on the terminal:
`make re`
Once the command says "lem-in COMPILED SUCCESSFULLY", the program has been created.

To run lem-in, you need to run the following command:
`./lem-in < map.txt`
where **map.txt** is your map input

Note: you have to create your own map, as map.txt does not exist. Sample working maps 1-3 can be found in the `maps` directory, whereas error maps 1-24 can be found in the `maps/wrong` directory.

###### Optional
You may also run lem-in as follows:
`./lemin`
After doing so, you will be required to type your map out in full, line by line.
Once you have completed typing your map out, simply end off by pressing `ctrl + D` to see the result.

## map rules
The ant-farm reader is very strict, so even the slightest margin of error will be picked up. The correct format is as follows:
`ants
rooms
pipes`
where ants represents the number of ants being passed, rooms represent the room names with their x and y coordinates, and pipes represent the links between rooms
maps may also have comments which are lines starting with `#` or commands which are lines starting with `##`.

### ants
Any integer from 1 upwards may be put here. Any other input will result in an error - this includes 0, negative numbers, additional whitespace characters, and non-numerical values

Only 1 line may consist of a value representing the number of ants

### rooms
a single room has the following syntax:
`room_name x_coordinate y_coordinate`
where **room_name** represents the name of the room, and **x_coordinate** + **y_coordinate** both represent the x-y coordinates of the room
* The room name may not start with `#` or `L`, and may not contain `-` or a space; they may be named any other way you wish, but please note it is case sensitive
* The coordinates must strictly be integers; negative values are accepted
* Each value in the syntax must be separated by a single space in between each value
* Any command line (starting with `##`) will be applied to the first room it comes across below it. Currently the only recognised commands are `##start` and `##end`
* Any other non-existing command will be recognised, but will take no action

Multiple lines may hold a single room each. Even if the syntax is correct for each room, the following can error out the program:
* Multiple rooms have the same name
* Multiple rooms have the exact same x- and y-coordinates
* No starting room is detected (defined by `##start` command)
* No ending room is detected (defined by `##end` command)
* The starting room is the same as the ending room
* There is no room beneath a command line

### pipes
a pipe has the following syntax:
`room1-room2`
where **room1** and **room2** both represents the room names defined in the map. They are linked together using only the `-` symbol with no spacing in between.

Multiple lines may hold a pipe each. Even if the syntax is correct for each pipe, the following can error out the program:
* a room name in the pipe does not exist
* a path from the starting room to the ending room is not linked

### other
A comment line (starting with `#` but NOT `##` which defines a command line) may be added on any line of the program and will not affect the lem-in program.
An empty line anywhere in the program will result in an error

## result
On a valid map, the output will print out a copy of the map as well as a line-by-line process of how the ants are moving through the rooms. This is displayed by the syntax:
`Lx-y`
where **x** is the ant ID number and **y** is the room name the ant is currently occupying.

If an error in the map is detected, the result will simply display `ERROR` in red.
