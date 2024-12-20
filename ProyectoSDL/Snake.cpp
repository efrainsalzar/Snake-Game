#include "Snake.h"

Snake::Snake(int startX, int _height) {
    // Inicializa la serpiente con un solo segmento
    body.push_back({ startX, _height, segmentSize, segmentSize });
    bodyColors.push_back({ 0, 255, 0, 255 });
    dirX = 1;  // Sin movimiento inicial
    dirY = 0;
}

void Snake::setDirection(int dx, int dy) {
    // Validar dirección opuesta
    if (dx != -dirX && dy != -dirY) {
        dirX = dx;
        dirY = dy;
    }
}

void Snake::move(int screenWidth, int screenHeight) {
    // Mover cada segmento de la serpiente (de cola a cabeza)
    for (int i = body.size() - 1; i > 0; --i) {
        body[i] = body[i - 1];  // Cada segmento toma la posición del anterior

    }

    // Evita que salga de los límites de la pantalla
    if (body[0].x > 0 || body[0].x < screenWidth) {
        body[0].x += dirX * (segmentSize);
    }
    if (body[0].y > 0 || body[0].x < screenHeight) {
        body[0].y += dirY * (segmentSize);
    }
}

void Snake::render(SDL_Renderer* renderer) {
    
   
    SDL_SetRenderDrawColor(renderer,0, 255, 200, 0);
    for (size_t i = 0; i < body.size(); ++i) {  // Itera con índice
        SDL_RenderFillRect(renderer, &body[i]);
    }
    // Dibuja la serpiente, dibujando cada segmento con su color
    //for (int i = 0; i < body.size(); i++) {

        //SDL_SetRenderDrawColor(renderer, bodyColors[i].r, bodyColors[i].g, bodyColors[i].b, bodyColors[i].a);
        //SDL_RenderFillRect(renderer, &body[i]);  // Dibuja cada segmento con el color correspondiente
    //}
}

Snake::CollisionType Snake::checkCollisions(const SDL_Rect& foodRect, int screenWidth, int screenHeight) {
    // Colisión con la fruta
    if (SDL_HasIntersection(&body[0], &foodRect)) {
        return CollisionType::Food;
    }

    // Colisión con los bordes
    if (body[0].x < 0 || body[0].x + segmentSize > screenWidth ||
        body[0].y < 0 || body[0].y + segmentSize > screenHeight) {
        return CollisionType::Border;
    }


    // Colisión con el propio cuerpo
    for (size_t i = 1; i < body.size(); ++i) {
        if (body[0].x == body[i].x && body[0].y == body[i].y) {
            return CollisionType::Self;
        }
    }

    return CollisionType::None;  // Sin colisión
}

void Snake::grow() {
    SDL_Rect newSegment = body.back(); // copia el ultimo segmento

    body.push_back(newSegment);
    // Asigna un color aleatorio al nuevo segmento
    bodyColors.push_back(generateRandomColor());
}

SDL_Color Snake::generateRandomColor() {
    // Genera un color aleatorio para cada nuevo segmento de la serpiente
    SDL_Color color;
    color.r = rand() % 256;  // Rojo aleatorio entre 0 y 255
    color.g = rand() % 256;  // Verde aleatorio entre 0 y 255
    color.b = rand() % 256;  // Azul aleatorio entre 0 y 255
    color.a = 255;  // Totalmente opaco
    return color;
}

