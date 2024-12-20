// Food.h
#ifndef FOOD_H
#define FOOD_H

#include <SDL.h>
#include <cstdlib>  // Para rand()

class Food {
private:
    SDL_Rect position;
    const int size=20;  // Cambiado de const a variable

public:
    Food(int width, int height);  // Constructor

    void spawn(int screendWidth, int screenHeight);
    void render(SDL_Renderer* renderer);
    SDL_Rect getPosition();
};

#endif
