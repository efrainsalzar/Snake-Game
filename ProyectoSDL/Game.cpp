// Game.cpp
#include "Game.h"

Game::Game() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        isRunning = false;
        return;
    }

    window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        isRunning = false;
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        
        isRunning = false;
        return;
    }

    // Aquí se cambian los objetos para que sean punteros
    menu = new Menu(renderer, screenWidth, screenHeight);
    snake = new Snake(screenWidth / 2, screenHeight / 2); 
    food = new Food(screenWidth, screenHeight);

}

Game::~Game() {
    delete snake;  // Liberar memoria
    delete food;   // Liberar memoria
    delete menu;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::run() {
    bool isRunning = true;
    
    if (!menu->showStartScreen()) {
        isRunning = false;
    }
    //std::cout << "Inicio del juego..." << std::endl;  // Mensaje de depuración

    while (isRunning) {
        //std::cout << "..." << std::endl;  // Mensaje de depuración
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                std::cout << "Cerrando el juego..." << std::endl;  // Mensaje de depuración
                isRunning = false;
            }

            // Control del teclado
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                case SDLK_UP:
                    snake->setDirection(0, -1);  // Mover hacia arriba
                    break;
                case SDLK_DOWN:
                    snake->setDirection(0, 1);  // Mover hacia abajo
                    break;
                case SDLK_LEFT:
                    snake->setDirection(-1, 0);  // Mover hacia izquierda
                    break;
                case SDLK_RIGHT:
                    snake->setDirection(1, 0);  // Mover hacia derecha
                    break;
                }
            }
        }


        switch (snake->checkCollisions(food->getPosition(), screenWidth, screenHeight)
            ) {
        case Snake::CollisionType::Food:
            std::cout << "¡Fruta comida!" << std::endl;
            snake->grow();
            food->spawn(screenWidth, screenHeight);  // Cambia la posición de la fruta
            break;

        case Snake::CollisionType::Border:
            std::cout << "Colisión con el borde. Fin del juego." << std::endl;
            isRunning = false;
            break;

        case Snake::CollisionType::Self:
            std::cout << "Colisión con el propio cuerpo. Fin del juego." << std::endl;
            isRunning = false;
            break;

        case Snake::CollisionType::None:
            // Sin colisión; el juego continúa
            break;
            // Actualizar lógica del juego
            //update();
        }

            snake->move(screenWidth, screenHeight);



        // Renderizado
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Limpiar pantalla con color negro
        SDL_RenderClear(renderer);

        snake->render(renderer);  // Dibuja la serpiente
        food->render(renderer);

        SDL_RenderPresent(renderer);  // Muestra todo en la pantalla

        SDL_Delay(100);  // Retraso para controlar la velocidad del juego
    }


    if (!menu->showEndScreen()) {
        isRunning = false;
    }
}

