
#ifndef SNAKE_H
#define SNAKE_H

#include <SDL.h>
#include <vector>
#include <iostream>
#include <cstdlib>

class Snake {
private:
    std::vector<SDL_Rect> body;  // Cuerpo de la serpiente
    std::vector<SDL_Color> bodyColors;
    int dirX, dirY;              // Direcci�n de movimiento
    const int segmentSize = 20;  // Tama�o de cada segmento

public:
    Snake(int _width, int _heght);
    void setDirection(int x, int y);
    void move(int screenWidth, int screenHeight);
    void grow(); //hacer crecer la serpiente

    void render(SDL_Renderer* renderer);


    SDL_Color generateRandomColor();  // M�todo para generar colores aleatorios
    

    enum class CollisionType {
        None,         // No hay colisi�n
        Food,         // Colisi�n con la fruta
        Border,       // Colisi�n con los bordes
        Self          // Colisi�n con el propio cuerpo
    };

    CollisionType checkCollisions(const SDL_Rect& foodRect, int screenWidth, int screenHeight);

    enum Direction {
        Up,
        Down,
        Left,
        Right
    };

    Direction currentDirection; // Direcci�n inicial

};

#endif
