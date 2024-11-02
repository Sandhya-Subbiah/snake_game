#ifndef _snake_map_h
#define _snake_map_h

#include "snake.h"
#include "setup.h"

class SnakeMap {
public:
    SnakeMap(Snake *snake);
    void redraw();
    void update_snake_food(bool force_update);
    void update_score();

    std::pair<int, int> snake_food; 

private:
    char map_array[MAP_HEIGHT][MAP_WIDTH];
    Snake *snake;
};

void clear_map(char map_array[MAP_HEIGHT][MAP_WIDTH]);
void update_snake_head(char map_array[MAP_HEIGHT][MAP_WIDTH], Snake *snake);

#endif
