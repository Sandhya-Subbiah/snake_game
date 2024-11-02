#include "input.h"
#include <termios.h>
#include <unistd.h>
#include <bits/stdc++.h>
#include <string>
#include <stdio.h>
#include "setup.h"
using namespace std;

struct termios t;

void input_enter_off() {
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

void input_enter_on() {
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag |= ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

enum Direction get_input()
{
    enum Direction result = East;
    char user_input = getchar();
    
    if (user_input >= '1' && user_input <= '3') {
        switch (user_input) {
            case '1':
                // easy
                pause_length = 1000 * 300; 
                break;
            case '2':
                // medium
                pause_length = 1000 * 200; 
                break;
            case '3':
                // hard
                pause_length = 1000 * 100; 
                break;
        }
        return result; 
    }

    switch (user_input) {
        case 'a':
            result = West;
            break;
        case 'w':
            result = North;
            break;
        case 'd':
            result = East;
            break;
        case 's':
            result = South;
            break;
        default:
            result = Error;
            cout << "Incorrect button clicked(" << user_input << ")" << endl;
            break;
    }
    return result;
}


void input_init() {

}
