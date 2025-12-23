#pragma once

typedef struct{
    int x;
    int y;
} Player;

void move_up(Player* player);
void move_down(Player* player);
void move_right(Player* player);
void move_left(Player* player);
void draw_player(Player* player);