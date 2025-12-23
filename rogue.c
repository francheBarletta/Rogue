#include <ncurses.h>
#include "player.h"

struct Room
{
    int width;
    int height;
};

void draw_room(int x, int y, struct Room r)
{
    for (int i = y; i < r.height; i++)
    {
        for (int j = x; j < r.width; j++)
        {
            mvaddch(i, j, '.');
        }
    }
}

int main()
{
    initscr();
    int row, col;
    getmaxyx(stdscr, row, col);
    struct Room map;
    Player player;
    player.x = col - 11;
    player.y = row - 11;
    map.width = col - 10;
    map.height = row - 10;

    int ch;
    while (1){
        draw_room(10, 10, map);
        draw_player(&player);
        refresh();
        ch = getch();

        if(ch == 'q'){
            break;
        }

        if(ch == 'w'){
            move_up(&player);
        } else if(ch == 's') {
            move_down(&player);
        } else if(ch == 'a') {
            move_left(&player);
        } else if(ch == 'd'){
            move_right(&player);
        }
    }
    endwin();

    return 0;
}