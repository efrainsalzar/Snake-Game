#ifndef MENU_H
#define MENU_H

#include <SDL.h>
#include <iostream>

class Menu {
private:
    SDL_Renderer* renderer;
    int screenWidth;
    int screenHeight;

    void renderStartScreen();
    void renderEndScreen();

public:
    Menu(SDL_Renderer* renderer, int screenWidth, int screenHeight);
    ~Menu();

    bool showStartScreen();
    bool showEndScreen();

};

#endif
