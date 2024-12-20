// Food.cpp
#include "Food.h"

Food::Food(int _width, int _height) {
 
    spawn(_width, _height);  // Tamaño por defecto de la ventana
}

void Food::spawn(int _width, int _height) {
    position.x = rand() % (_width / size) * size;
    position.y = rand() % (_height / size) * size;
    position.w = size;
    position.h = size;
}

void Food::render(SDL_Renderer* renderer) {
    // Establecer color para la comida (rojo)
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Rojo
    SDL_RenderFillRect(renderer, &position);
}

SDL_Rect Food::getPosition() {
    return position;
}
