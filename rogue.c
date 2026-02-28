#include <ncurses.h>
#include "player.h"

struct Room
{
    int width;
    int height;
};

void draw_room(int x, int y, struct Room r)
{
    int endy = y + r.height;
    int endx = x + r.width;
    for (int j = x; j < endx; j++) {
        for (int i = y; i < endy; i++) {
            if (i == y || i == endy - 1) {
                mvaddch(i, j, '-');
            } else if (j == x || j == endx - 1) {
                mvaddch(i, j, '|');
            } else {
                mvaddch(i, j, '.');
            }
        }
    }
}

int main()
{
    initscr();
    noecho();
    raw();
    keypad(stdscr, true);

    int row, col;
    getmaxyx(stdscr, row, col);

    Player player;
    player.x = 1;
    player.y = 1;

    struct Room map;
    map.width = 20;
    map.height = 10;

    while (true) {
        // TODO: make drawing more efficient
        clear();
        draw_room(0, 0, map);
        draw_player(&player);

        int ch = getch();

        if (ch == 'q') break;

        switch (ch) {
            case KEY_UP:    move_up(&player);    break;
            case KEY_LEFT:  move_left(&player);  break;
            case KEY_DOWN:  move_down(&player);  break;
            case KEY_RIGHT: move_right(&player); break;
        }
    }
    endwin();

    return 0;
}
