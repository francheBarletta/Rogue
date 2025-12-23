#include "player.h"
#include <ncurses.h>

void move_up(Player* player){
    player->y--;
}

void move_down(Player* player){
    player->y++;
}

void move_right(Player* player){
    player->x++;
}

void move_left(Player* player){
    player->x--;
}

void draw_player(Player* player){
    mvaddch(player->y, player->x, '@');
}