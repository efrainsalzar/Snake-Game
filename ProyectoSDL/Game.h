// Game.h
#ifndef GAME_H
#define GAME_H

#include "Snake.h"
#include "Food.h"
#include "Menu.h"
#include <SDL.h>
#include <iostream>

class Game {
private:
    Snake* snake;  // Usar punteros
    Food* food;    // Usar punteros
    Menu* menu;
    SDL_Window* window;
    SDL_Renderer* renderer;

    const int screenWidth = 640;
    const int screenHeight = 480;

    bool isRunning;

public:
    Game();
    ~Game();
    void run();
    //void update();
};

#endif
