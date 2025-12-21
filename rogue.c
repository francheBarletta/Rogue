#include <ncurses.h>

struct Room{
    int width;
    int height;
};

void draw_room(int x, int y, struct Room r){
    for (int i = y; i < r.height; i++){
        for(int j = x; j < r.width; j++){
           mvaddch(i, j, '.');
        }
    }
}

int main(){
    initscr();
    int row, col;
    getmaxyx(stdscr,row,col);
    struct Room map;
    map.width = col-10;
    map.height = row-10;
    draw_room(10, 10, map);
    refresh();
    getch();
    endwin();

    return 0;
}