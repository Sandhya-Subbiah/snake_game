#include <stdio.h>
#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <unistd.h>
#include <bits/stdc++.h>
#include "input.h"
#include "snake.h"
#include "snake_map.h"
#include "setup.h"

using namespace std;

int pause_length = 1000 * 300; // Default to easy level (300 ms)

Snake snake;
SnakeMap snake_map(&snake);

void initialize()
{
    input_init();
    input_enter_off();
}

bool is_game_end()
{
    bool result = false;
    pair<int, int> snake_head = snake.snake_head;
    if (snake_head.first < 0 || snake_head.first >= MAP_HEIGHT || snake_head.second < 0 || snake_head.second >= MAP_WIDTH)
    {
        result = true;
    }
    if (snake.is_dead)
    {
        result = true;
    }
    return result;
}

void game_over()
{
    cout << "GAME IS OVER" << endl;
}

void start_game()
{
    while (true)
    {
        snake.update_movement();
        if (is_game_end())
        {
            game_over();
            break;
        }
        snake_map.redraw();

        usleep(pause_length); 

        snake.validate_direction();
    }
}

int main()
{
    initialize();

    cout << "Select Difficulty Level: Press 1 for Easy, 2 for Medium, 3 for Hard" << endl;
    char difficulty_input = getchar(); 
    if (difficulty_input < '1' || difficulty_input > '3') {
        cout << " Invalid choice. Defaulting to Easy." << endl;
        pause_length = 1000 * 300; 
    } else {
        
        switch (difficulty_input) {
            case '1':
                pause_length = 1000 * 300; // Easy
                break;
            case '2':
                pause_length = 1000 * 200; // Medium
                break;
            case '3':
                pause_length = 1000 * 100; // Hard
                break;
        }
    }
    start_game();
    return 0;
}
